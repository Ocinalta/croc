#!/bin/bash

# Script per compilare con Verilator usando output di Bender
# Uso: ./run_verilator.sh [log_file]

LOG_FILE=${1:-"compile.log"}

echo "=== Starting Verilator compilation at $(date) ===" | tee $LOG_FILE

# Genera la lista dei file con Bender
echo "Generating file list with Bender..." | tee -a $LOG_FILE
bender script verilator -t test > bender_files.f 2>&1 | tee -a $LOG_FILE

if [ ! -f bender_files.f ]; then
    echo "ERROR: Failed to generate file list" | tee -a $LOG_FILE
    exit 1
fi

# Compila con Verilator
echo "Running Verilator..." | tee -a $LOG_FILE
verilator \
    --cc \
    --exe \
    --build \
    -f bender_files.f \
    tb/cnt_tb.cpp \
    tb/tb_macros.cpp \
    tb/tb_components.cpp \
    --top-module cnt_tb_wrapper \
    --Mdir obj_dir \
    -I./hw/vendor/pulp-platform-common-cells/include \
    -I./hw/vendor/pulp-platform-register-interface/include \
    -I./tb \
    -CFLAGS "-std=c++14 -I../tb -I../sw" \
    -LDFLAGS "-lpthread" \
    --trace \
    --trace-fst \
    --trace-structs \
    --trace-max-array 128 \
    -Wall \
    -Wno-fatal \
    --x-assign unique \
    --x-initial unique \
    2>&1 | tee -a $LOG_FILE

EXIT_CODE=${PIPESTATUS[0]}

if [ $EXIT_CODE -eq 0 ]; then
    echo "=== ✅ Compilation SUCCESS at $(date) ===" | tee -a $LOG_FILE
    echo "Executable: obj_dir/Vcnt_tb_wrapper" | tee -a $LOG_FILE
else
    echo "=== ❌ Compilation FAILED (exit code: $EXIT_CODE) at $(date) ===" | tee -a $LOG_FILE
fi

echo "Full log saved to: $LOG_FILE"
exit $EXIT_CODE