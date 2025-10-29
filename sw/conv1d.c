#include <stdint.h>
#include <limits.h>
#include "conv1d.h"
#include "data.h" // for PAD, STRIDE, KERNEL_LEN
#include "config.h"
#include "conv_accel.h"

void conv1d_sw(const int8_t * const input_data, const int8_t * const filter, int32_t *output_data, const uint32_t input_len, const uint32_t input_ch, const uint32_t output_ch)
{
    // Calculate the length of the input data after padding
    uint32_t padded_input_len = input_len + 2 * PAD;

    // Calculate the length of the output data
    uint32_t output_len = ((padded_input_len - KERNEL_LEN) / STRIDE) + 1;

    // Loop over each output channel (output_ch times)
    for (uint32_t m = 0; m < output_ch; m++) {
        // Loop over each output position
        for (uint32_t o = 0; o < output_len; o++) {
            int32_t accumulated_output = 0;

            // Loop over each input channel
            for (uint32_t n = 0; n < input_ch; n++) {
                // Compute the starting index in the input data for this convolution window
                int32_t input_start = o * STRIDE - PAD;

                int32_t sum = 0;

                // Loop over the kernel elements
                for (uint32_t k_idx = 0; k_idx < KERNEL_LEN; k_idx++) {
                    int32_t input_index = input_start + k_idx;
                    int8_t input_value;

                    // Handle padding: if the input index is outside the valid range, use zero
                    if (input_index < 0 || input_index >= (int32_t)input_len) {
                        // Input value is zero due to padding
                        input_value = 0;
                    } else {
                        // Access the input data using the mem2d macro
                        input_value = mem2d(input_data, input_len, n, input_index);
                    }

                    // Access the filter coefficient using the mem3d macro
                    int8_t filter_value = mem3d(filter, input_ch, KERNEL_LEN, m, n, k_idx);

                    // Multiply and accumulate
                    sum += input_value * filter_value;
                }

                // Accumulate the sum from all input channels
                accumulated_output += sum;
            }

            // Store the accumulated result in the output data array
            // The output data is organized in row-major order: output_data[m][o] = output_data[m * output_len + o]
            output_data[m * output_len + o] = accumulated_output;
        }
    }
}

//conv1d_hw(A, F, R_hw, INPUT_LEN, INPUT_CH, K_NUM);
void conv1d_hw(const int8_t * const in_data, const int8_t * const filter, int32_t *output_data, const uint32_t input_len, const uint32_t input_ch, const uint32_t output_ch) {

    int R_index=0;
    conv_accel_set_start();
    conv_accel_clear_start();
for(int filter_cycle=0; filter_cycle<8; filter_cycle++){    
    //Filter storing
    int F_index=0;
    int A_index=0;
    int tmp=0;
    int column_number=0;

    

    for(int i=0; i<20;i++){
        tmp=F[F_index+(filter_cycle*80)] << 24 | ((F[F_index + 5+(filter_cycle*80)] << 16) & 0x00FF0000) | ((F[F_index + 10+(filter_cycle*80)] << 8) & 0x0000FF00) | (F[F_index+ 15+(filter_cycle*80)] & 0x000000FF);
        *((volatile uint32_t *)(CONV1D_ACCEL_START_ADDRESS)+(i)) = tmp;
        if (((i+1)) % 5 == 0 && i != 0) { //If we wrote 5 filters weigth, we need to go to the next row
            F_index += 16;
        } else {
            F_index += 1;
        }
    }
    

    //Data input SRAM 1
    for (int i=20; i<108;i++){
        if(i==20|i==21|i==42|i==43|i==64|i==65|i==86|i==87){
            tmp=0;
        } else {
            tmp=A[A_index] << 24 | ((A[A_index + 128] << 16) & 0x00FF0000) | ((A[A_index + 256] << 8) & 0x0000FF00) | (A[A_index+ 384] & 0x000000FF);
            if(column_number==19){
                A_index+=493;
                column_number=0;
            } else {
                A_index++;
                column_number++;
            }
        }
        *((volatile uint32_t *)(CONV1D_ACCEL_START_ADDRESS)+(i)) = tmp;
    }
    
    conv_accel_set_loaded_flag();
    conv_accel_clear_loaded_flag();
    conv_accel_wait_reload_flag();
    for(int i=0; i<18;i++){
        output_data[R_index]=*((volatile uint32_t *)(CONV1D_ACCEL_START_ADDRESS)+(i+108));
        R_index++;
    }
    //Data input SRAM 2-7
    for(int column_index=16; column_index<=106; column_index+=18){
    A_index=0;
    for (int i=20; i<108;i++){
        
            tmp=A[A_index+column_index] << 24 | ((A[A_index + 128+column_index] << 16) & 0x00FF0000) | ((A[A_index + 256+column_index] << 8) & 0x0000FF00) | (A[A_index+ 384+column_index] & 0x000000FF);
            if(column_number==21){
                A_index+=491;
                column_number=0;
            } else {
                A_index++;
                column_number++;
            }
        
        *((volatile uint32_t *)(CONV1D_ACCEL_START_ADDRESS)+(i)) = tmp;
    }
    conv_accel_set_loaded_flag();
    conv_accel_clear_loaded_flag();
    
    if(filter_cycle==7 & column_index==106){
        conv_accel_wait_done();
    } else {
        conv_accel_wait_reload_flag();
    }
    if(column_index==106){
        for(int i=0; i<20;i++){
            output_data[R_index]=*((volatile uint32_t *)(CONV1D_ACCEL_START_ADDRESS)+(i+108));
            R_index++;
        }
    } else {
        for(int i=0; i<18;i++){
            output_data[R_index]=*((volatile uint32_t *)(CONV1D_ACCEL_START_ADDRESS)+(i+108));
            R_index++;
        }
        
    }
    
    }

}

    /*
    for (int i = 80; i <= 87; i++) {
        *(volatile uint8_t *)(CONV1D_ACCEL_START_ADDRESS + i) = 0;
    }    

    for (int i = 0; i < 80; i++) {  // 167 - 88 + 1 = 80
        int addr =  88 + i;
        int index = (i % 4) * 128 + (i / 4);  // Calcolo degli indici: A[0], A[128], A[256], A[384], A[1], ...
        *(volatile uint8_t *)(CONV1D_ACCEL_START_ADDRESS+addr) = A[index];
    }
    
    for (int i = 168; i <= 175; i++) {
        *(volatile uint8_t *)(CONV1D_ACCEL_START_ADDRESS + i) = 0;
    }

    for (int i = 0; i < 80; i++) {  // 167 - 88 + 1 = 80
        int addr =  176 + i;
        int index = 4*128+(i % 4) * 128 + (i / 4);  // Calcolo degli indici: A[0], A[128], A[256], A[384], A[1], ...
        *(volatile uint8_t *)(CONV1D_ACCEL_START_ADDRESS+addr) = A[index];
    }

    for (int i = 256; i <= 263; i++) {
        *(volatile uint8_t *)(CONV1D_ACCEL_START_ADDRESS + i) = 0;
    }

    for (int i = 0; i < 80; i++) {  // 167 - 88 + 1 = 80
        int addr =  264 + i;
        int index = 8*128+(i % 4) * 128 + (i / 4);  // Calcolo degli indici: A[0], A[128], A[256], A[384], A[1], ...
        *(volatile uint8_t *)(CONV1D_ACCEL_START_ADDRESS+addr) = A[index];
    }
    
    for (int i = 344; i <= 351; i++) {
        *(volatile uint8_t *)(CONV1D_ACCEL_START_ADDRESS + i) = 0;
    }

    for (int i = 0; i < 80; i++) {  // 167 - 88 + 1 = 80
        int addr =  352 + i;
        int index = 12*128+(i % 4) * 128 + (i / 4);  // Calcolo degli indici: A[0], A[128], A[256], A[384], A[1], ...
        *(volatile uint8_t *)(CONV1D_ACCEL_START_ADDRESS+addr) = A[index];
    }

    
    */
    
    // Tiling loop(s)
    //for (size_t o = 0; o < output_ch; o++) //Output channel è il numero di filtri, nel nostro caso 8
    //{
        // for ...

        /*
         * TODO: program the system DMA to transfer the current input data chunk
         * (tile) and, possibly, filters, from the system memory to the hardware
         * accelerator's private buffer.
         */
        // dma_copy(...); // from `dma_sdk.h`

        /*
         * TODO: call the appropriate functions from the hardware accelerator's
         * driver to start the computation, then wait for it to complete.
         */
        // conv_accel_start(); // from `conv_accel.h`
        // conv_accel_wait(); // from `conv_accel.h`

        /*
         * TODO: program the system DMA to transfer the current output data chunk
         * from the hardware accelerator's private buffer to the `R` buffer in
         * the system main memory.
         */
        // dma_copy(...); // from `dma_sdk.h`
    //}
    
    return;
}