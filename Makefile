# Copyright (c) 2024 ETH Zurich and University of Bologna.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
#
# Authors:
# - Philippe Sauter <phsauter@iis.ee.ethz.ch>

# Global configuration
ROOT_DIR			:= $(realpath .)

# Tools
BENDER	  ?= bender
PYTHON3   ?= python3
VERILATOR ?= /foss/tools/bin/verilator
YOSYS     ?= yosys
OPENROAD  ?= openroad
KLAYOUT   ?= klayout
REGGEN    ?= $(PYTHON3) $(shell $(BENDER) path register_interface)/vendor/lowrisc_opentitan/util/regtool.py

# Directories
# directory of the path to the last called Makefile (this one)
PROJ_DIR  := $(realpath $(dir $(realpath $(lastword $(MAKEFILE_LIST)))))

# Firmware installing
FIRMWARE	?= $(ROOT_DIR)/sw/bin/main.hex
APP_MAKE 	:= $(wildcard sw/applications/$(PROJECT)/*akefile)
APP_PARAMS  ?=

default: help

################
# Dependencies #
################
# Download RCX file used for parasitic extraction from ORFS (configuration got ok by IHP)
IHP_RCX_URL  := "https://raw.githubusercontent.com/The-OpenROAD-Project/OpenROAD-flow-scripts/7747f88f70daaeb63f43ce36e71829707b7e3fa7/flow/platforms/ihp-sg13g2/IHP_rcx_patterns.rules"
IHP_RCX_FILE := $(PROJ_DIR)/openroad/IHP_rcx_patterns.rules

## Checkout/update dependencies using Bender
checkout: $(IHP_RCX_FILE)
	$(BENDER) checkout
	git submodule update --init --recursive

$(IHP_RCX_FILE): 
	curl -L -o $@ $(IHP_RCX_URL)

## Reset dependencies (without updating Bender.lock)
clean-deps:
	rm -rf .bender
	git submodule deinit -f --all

.PHONY: checkout clean-deps


############
# Software #
############
.PHONY: app
app: $(ROOT_DIR)/sw/bin/
ifneq ($(APP_MAKE),)
	@echo "### Calling application-specific makefile '$(APP_MAKE)'..."
	$(MAKE) -C $(dir $(APP_MAKE)) APP_PARAMS="$(APP_PARAMS)"
endif
	@echo "### Building application for SRAM execution with GCC compiler..."
	CDEFS=$(CDEFS) $(MAKE) -f $(XHEEP_MAKE) $(MAKECMDGOALS) LINK_FOLDER=$(LINK_FOLDER) ARCH=$(ARCH)
	find $(SW_BUILD_DIR)/ -maxdepth 1 -type f -name "main.*" -exec cp '{}' $(BUILD_DIR)/sw/app/ \;

SW_HEX := sw/bin/main.hex

$(SW_HEX): sw/*.c sw/*.h sw/*.S sw/*.ld
	$(MAKE) -C sw/ compile

## Build all top-level programs in sw/
software: $(SW_HEX)

sw: $(SW_HEX)

.PHONY: software sw

##################
# RTL Simulation #
##################
# Verilator
# Turn off style warnings and well-defined SystemVerilog warnings that should be part of -Wno-style
VERILATOR_ARGS = -Wno-fatal -Wno-style \
	-Wno-BLKANDNBLK -Wno-WIDTHEXPAND -Wno-WIDTHTRUNC -Wno-WIDTHCONCAT -Wno-ASCRANGE

VERILATOR_ARGS += --binary -j 0
VERILATOR_ARGS += --timing --autoflush --trace-fst --trace-threads 2 --trace-structs
VERILATOR_ARGS +=  --unroll-count 2 --unroll-stmts 1
VERILATOR_ARGS += --x-assign fast --x-initial fast
VERILATOR_CFLAGS += -O3 -march=native -mtune=native

verilator/croc.f: Bender.lock Bender.yml
	$(BENDER) script verilator -t rtl -t verilator -DSYNTHESIS -DVERILATOR > $@

verilator/obj_dir/Vtb_croc_soc: verilator/croc.f $(SW_HEX)
	cd verilator; $(VERILATOR) $(VERILATOR_ARGS) -O3 --top tb_croc_soc -f croc.f

## Simulate RTL using Verilator
verilator: verilator/obj_dir/Vtb_croc_soc
	cd verilator; obj_dir/Vtb_croc_soc +binary="$(realpath $(SW_HEX))"

.PHONY: verilator


####################
# Open Source Flow #
####################
# Bender manages the different IPs and can be used to generate file-lists for synthesis
TOP_DESIGN     ?= croc_chip
DUT_DESIGN	   ?= croc_soc
BENDER_TARGETS ?= asic ihp13 rtl synthesis
SV_DEFINES     ?= VERILATOR SYNTHESIS COMMON_CELLS_ASSERTS_OFF

## Generate croc.flist used to read design in yosys
yosys-flist: Bender.lock Bender.yml rtl/*/Bender.yml
	$(BENDER) script flist-plus $(foreach t,$(BENDER_TARGETS),-t $(t)) $(foreach d,$(SV_DEFINES),-D $(d)=1) > $(PROJ_DIR)/croc.flist

include yosys/yosys.mk
include openroad/openroad.mk

klayout/croc_chip.gds: $(OR_OUT)/croc.def klayout/*.sh klayout/*.py
	./klayout/def2gds.sh

## Generate merged .gds from openroads .def output
klayout: klayout/croc_chip.gds

.PHONY: klayout yosys-flist


#################
# Documentation #
#################

help: Makefile
	@printf "Available targets:\n------------------\n"
	@for mkfile in $(MAKEFILE_LIST); do \
		awk '/^[a-zA-Z\-\_0-9]+:/ { \
			helpMessage = match(lastLine, /^## (.*)/); \
			if (helpMessage) { \
				helpCommand = substr($$1, 0, index($$1, ":")-1); \
				helpMessage = substr(lastLine, RSTART + 3, RLENGTH); \
				printf "%-20s %s\n", helpCommand, helpMessage; \
			} \
		} \
		{ lastLine = $$0 }' $$mkfile; \
	done

.PHONY: help


###########
# Cleanup #
###########

## Delete generated files and directories
clean: 
	rm -f $(SV_FLIST)
	rm -f klayout/croc_chip.gds
	rm -rf verilator/obj_dir/
	rm -f verilator/croc.f
	rm -f verilator/croc.vcd
	$(MAKE) ys_clean
	$(MAKE) or_clean

.PHONY: clean
