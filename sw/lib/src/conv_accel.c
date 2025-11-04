#include <stdint.h>

#include "conv_accel.h"
#include "config.h"
#include "conv1d_control_reg.h"

/*----------------------INITIALIZATION--------------------*/
void conv_accel_init() {
    *(volatile uint32_t *)(USER_CONV1D_CSR_START_ADDRESS + CONV1D_CONTROL_CONTROL_REG_OFFSET) = 0;
    *(volatile uint32_t *)(USER_CONV1D_CSR_START_ADDRESS + CONV1D_CONTROL_STATUS1_REG_OFFSET) = 0;
    *(volatile uint32_t *)(USER_CONV1D_CSR_START_ADDRESS + CONV1D_CONTROL_STATUS2_REG_OFFSET) = 0;
}

/*----------------------START DRIVERS---------------------*/
void conv_accel_set_start() {
    *(volatile uint32_t *)(USER_CONV1D_CSR_START_ADDRESS + CONV1D_CONTROL_CONTROL_REG_OFFSET) |= (1 << CONV1D_CONTROL_CONTROL_START_BIT);
}

uint8_t conv_accel_get_start() {
    return (*(volatile uint32_t *)(USER_CONV1D_CSR_START_ADDRESS + CONV1D_CONTROL_CONTROL_REG_OFFSET) & (1 << CONV1D_CONTROL_CONTROL_START_BIT)) != 0;
}

void conv_accel_clear_start(){
    *(volatile uint32_t *)(USER_CONV1D_CSR_START_ADDRESS + CONV1D_CONTROL_CONTROL_REG_OFFSET) &= ~(1 << CONV1D_CONTROL_CONTROL_START_BIT);
}

/*------------------LOADED FLAG DRIVERS-------------------*/
void conv_accel_set_loaded_flag() {
    *(volatile uint32_t *)(USER_CONV1D_CSR_START_ADDRESS + CONV1D_CONTROL_CONTROL_REG_OFFSET) |= (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT);
}

uint8_t conv_accel_get_loaded_flag() {
    return (*(volatile uint32_t *)(USER_CONV1D_CSR_START_ADDRESS + CONV1D_CONTROL_CONTROL_REG_OFFSET) & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)) != 0;
}

void conv_accel_clear_loaded_flag(){
    *(volatile uint32_t *)(USER_CONV1D_CSR_START_ADDRESS + CONV1D_CONTROL_CONTROL_REG_OFFSET) &= ~(1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT);
}

/*------------------RELOAD FLAG DRIVERS-------------------*/
__attribute__((inline)) uint8_t conv_accel_get_reload_flag(){
    return (*(volatile uint32_t *)(USER_CONV1D_CSR_START_ADDRESS + CONV1D_CONTROL_STATUS1_REG_OFFSET) & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)) != 0;
}

void conv_accel_clear_reload_flag(){
    *(volatile uint32_t *)(USER_CONV1D_CSR_START_ADDRESS + CONV1D_CONTROL_STATUS1_REG_OFFSET) &= ~(1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT);
}

void conv_accel_wait_reload_flag() {
    // Wait for the DONE status bit to be set
    while (!conv_accel_get_reload_flag()) {
        continue; // Busy waiting
    }
    //conv_accel_clear_reload_flag(); // clear RELOAD FLAG bit
}

/*-----------------------DONE DRIVERS---------------------*/
__attribute__((inline)) uint8_t conv_accel_get_done(){
    return (*(volatile uint32_t *)(USER_CONV1D_CSR_START_ADDRESS + CONV1D_CONTROL_STATUS1_REG_OFFSET) & (1 << CONV1D_CONTROL_STATUS1_DONE_BIT)) != 0;
}

void conv_accel_clear_done(){
    *(volatile uint32_t *)(USER_CONV1D_CSR_START_ADDRESS + CONV1D_CONTROL_STATUS1_REG_OFFSET) &= ~(1 << CONV1D_CONTROL_STATUS1_DONE_BIT);
}

void conv_accel_wait_done() {
    // Wait for the DONE status bit to be set
    while (!conv_accel_get_done()) {
        continue; // Busy waiting
    }
    //conv_accel_clear_done(); // clear DONE bit
}
