// Copyright (c) 2024 ETH Zurich and University of Bologna.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0/
//
// Authors:
// - Philippe Sauter <phsauter@iis.ee.ethz.ch>

// System library headers
#include <string.h>

#include "uart.h"
#include "print.h"
#include "timer.h"
#include "gpio.h"
#include "util.h"
#include "data.h"
#include "conv1d.h"
#include "conv_accel.h"

uint32_t R_sw[K_NUM * R_ROWS * R_COLS] = {0};
uint32_t R_hw[K_NUM * R_ROWS * R_COLS] = {0};

int main() {

    // INITIALIZATION
    // --------------
    uint32_t t_start=0, t_end=0;
    uart_init(); // setup the uart peripheral

    // simple printf support (only prints text and hex numbers)
    // printf("Hello World!\n");
    // wait until uart has finished sending
    // uart_write_flush();

    //conv_accel_init();
    // HARDWARE-ACCELERATED 1D CONVOLUTION
    t_start = get_mcycle();
    conv1d_hw(A, F, R_hw, INPUT_LEN, INPUT_CH, K_NUM);
    t_end   = get_mcycle();
    printf("HW Cycles: 0x%x\n", t_end - t_start);
    uart_write_flush();


    // SOFTWARE 1D CONVOLUTION
    t_start = get_mcycle();
    //conv1d_sw(A, F, R_sw, INPUT_LEN, INPUT_CH, K_NUM);
    t_end   = get_mcycle();
    printf("CPU Cycles: 0x%x\n", t_end - t_start);
    uart_write_flush();


    // RESULT CHECKING
    // ---------------
    // Compare the CPU output data with the golden output
    /*if (memcmp(R_sw, R, R_SIZE) != 0) {
        printf("CPU result mismatch!\n");
        return -1;
    }*/

    // Compare the HW output data with the golden output
    /*if (memcmp(R_hw, R, R_SIZE) != 0) {
        printf("HW result mismatch!\n");
        return -1;
    }*/

    // using the timer
    printf("Tick\n");
    sleep_ms(10);
    printf("Tock\n");
    uart_write_flush();
    return 1;
}
