#ifndef CONV_ACCEL_HH_
#define CONV_ACCEL_HH_

/*----------------------INITIALIZATION--------------------*/
/**
 * @brief Initialize the accelerator.
 * 
 */
void conv_accel_init();

/*----------------------START DRIVERS---------------------*/
/**
 * @brief Trigger the START of processing.
 * 
 */
void conv_accel_set_start();

/**
 * @brief Poll the START bit of the conv1d.
 * 
 * @return true if the START bit is set, false otherwise.
 */
uint8_t conv_accel_get_start();

/**
 * @brief Clear START bit.
 * 
 */
void conv_accel_clear_start();


/*------------------LOADED FLAG DRIVERS-------------------*/
/**
 * @brief Trigger the LOADED FLAG.
 * 
 */
void conv_accel_set_loaded_flag();

/**
 * @brief Poll the LOADED FLAG bit of the conv1d.
 * 
 * @return true if the START bit is set, false otherwise.
 */
uint8_t conv_accel_get_loaded_flag();

/**
 * @brief Clear LOADED FLAG bit.
 * 
 */
void conv_accel_clear_loaded_flag();

/*------------------RELOAD FLAG DRIVERS-------------------*/
/**
 * @brief Poll the RELOAD FLAG bit of the conv1d.
 * 
 * @return true if the RELOAD FLAG bit is set, false otherwise.
 */
__attribute__((inline)) uint8_t conv_accel_get_reload_flag();

/**
 * @brief Clear RELOAD FLAG bit.
 * 
 */
void conv_accel_clear_reload_flag();

/**
 * @brief Wait for the accelerator to complete execution of SRAM Refresh.
 * 
 */
void conv_accel_wait_reload_flag();

/*-----------------------DONE DRIVERS---------------------*/
/**
 * @brief Poll the DONE bit of the conv1d.
 * 
 * @return true if the DONE bit is set, false otherwise.
 */
__attribute__((inline)) uint8_t conv_accel_get_done();

/**
 * @brief Clear DONE bit.
 * 
 */
void conv_accel_clear_done();

/**
 * @brief Wait for the accelerator to complete execution.
 * 
 */
void conv_accel_wait_done();

#endif /* CONV_ACCEL_HH_ */
