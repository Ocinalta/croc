#!/bin/bash

# Script per compilare cnt con Verilator usando output di Bender
# Uso:
#   ./run_verilator_cnt.sh [log_file]
#   ./run_verilator_cnt.sh clean    # per pulire i file generati

LOG_FILE=${1:-"compile.log"}

# Gestione del comando "clean"
if [ "$1" == "clean" ]; then
    echo "=== Cleaning build artifacts ==="
    rm -f Bender.lock bender_files.f compile.log
    rm -rf obj_dir
    echo "✅ Cleanup completed."
    exit 0
fi

echo "=== Starting Verilator compilation for cnt at $(date) ===" | tee $LOG_FILE

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
