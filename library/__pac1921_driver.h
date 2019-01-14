/*
    __pac1921_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __pac1921_driver.h
@brief    PAC1921 Driver
@mainpage PAC1921 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   PAC1921
@brief      PAC1921 Click Driver
@{

| Global Library Prefix | **PAC1921** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2018.**      |
| Developer             | **Nemanja Medakovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _PAC1921_H_
#define _PAC1921_H_

/** 
 * @macro T_PAC1921_P
 * @brief Driver Abstract type 
 */
#define T_PAC1921_P    const uint8_t*

/** @defgroup PAC1921_COMPILE Compilation Config */              /** @{ */

//  #define   __PAC1921_DRV_SPI__                            /**<     @macro __PAC1921_DRV_SPI__  @brief SPI driver selector */
   #define   __PAC1921_DRV_I2C__                            /**<     @macro __PAC1921_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __PAC1921_DRV_UART__                           /**<     @macro __PAC1921_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup PAC1921_VAR Variables */                           /** @{ */

//value witch determines unit (mV or W)
extern uint8_t _PAC1921_UNIT;

//registers address
extern const uint8_t _PAC1921_GAIN_CONFIGURATION_REG;
extern const uint8_t _PAC1921_INTEGRATION_CONFIGURATION_REG;
extern const uint8_t _PAC1921_CONTROL_REG;
extern const uint8_t _PAC1921_VBUS_HIGH_BYTE_REG;
extern const uint8_t _PAC1921_VBUS_LOW_BYTE_REG;
extern const uint8_t _PAC1921_VSENSE_HIGH_BYTE_REG;
extern const uint8_t _PAC1921_VSENSE_LOW_BYTE_REG;
extern const uint8_t _PAC1921_VSUM_HIGH_BYTE_REG;
extern const uint8_t _PAC1921_VSUM_MIDDLE_HIGH_BYTE_REG;
extern const uint8_t _PAC1921_VSUM_MIDDLE_LOW_BYTE_REG;
extern const uint8_t _PAC1921_VSUM_LOW_BYTE_REG;
extern const uint8_t _PAC1921_ISUM_HIGH_BYTE_REG;
extern const uint8_t _PAC1921_ISUM_MIDDLE_HIGH_BYTE_REG;
extern const uint8_t _PAC1921_ISUM_MIDDLE_LOW_BYTE_REG;
extern const uint8_t _PAC1921_ISUM_LOW_BYTE_REG;
extern const uint8_t _PAC1921_OVERFLOW_STATUS_REG;
extern const uint8_t _PAC1921_VPOWER_HIGH_BYTE_REG;
extern const uint8_t _PAC1921_VPOWER_LOW_BYTE_REG;
extern const uint8_t _PAC1921_SAMPLES_HIGH_BYTE_REG;
extern const uint8_t _PAC1921_SAMPLES_LOW_BYTE_REG;
extern const uint8_t _PAC1921_PSUM_HIGH_BYTE_REG;
extern const uint8_t _PAC1921_PSUM_MIDDLE_HIGH_BYTE_REG;
extern const uint8_t _PAC1921_PSUM_MIDDLE_BYTE_REG;
extern const uint8_t _PAC1921_PSUM_MIDDLE_LOW_BYTE_REG;
extern const uint8_t _PAC1921_PSUM_LOW_BYTE_REG;
extern const uint8_t _PAC1921_PRODUCT_ID_REG;
extern const uint8_t _PAC1921_MANUFACTURER_ID_REG;
extern const uint8_t _PAC1921_REVISION_REG;

//control data for _PAC1921_GAIN_CONFIGURATION_REG register
extern const uint8_t _PAC1921_ADC_RESOLUTION_14_BIT_GAIN_1X;
extern const uint8_t _PAC1921_ADC_RESOLUTION_VSENSE_11_BIT;
extern const uint8_t _PAC1921_ADC_RESOLUTION_VBUS_11_BIT;
extern const uint8_t _PAC1921_DIG_CURRENT_GAIN_2X;
extern const uint8_t _PAC1921_DIG_CURRENT_GAIN_4X;
extern const uint8_t _PAC1921_DIG_CURRENT_GAIN_8X;
extern const uint8_t _PAC1921_DIG_CURRENT_GAIN_16X;
extern const uint8_t _PAC1921_DIG_CURRENT_GAIN_32X;
extern const uint8_t _PAC1921_DIG_CURRENT_GAIN_64X;
extern const uint8_t _PAC1921_DIG_CURRENT_GAIN_128X;
extern const uint8_t _PAC1921_DIG_BUS_VOLTAGE_GAIN_2X;
extern const uint8_t _PAC1921_DIG_BUS_VOLTAGE_GAIN_4X;
extern const uint8_t _PAC1921_DIG_BUS_VOLTAGE_GAIN_8X;
extern const uint8_t _PAC1921_DIG_BUS_VOLTAGE_GAIN_16X;
extern const uint8_t _PAC1921_DIG_BUS_VOLTAGE_GAIN_32X;

//control data for _PAC1921_INTEGRATION_CONFIGURATION_REG register
extern const uint8_t _PAC1921_1_SAMPLE_ADC_FILTER_DISABLE_OVERRIDE_DISABLE_READ_STATE;
extern const uint8_t _PAC1921_2_SAMPLES;
extern const uint8_t _PAC1921_4_SAMPLES;
extern const uint8_t _PAC1921_8_SAMPLES;
extern const uint8_t _PAC1921_16_SAMPLES;
extern const uint8_t _PAC1921_32_SAMPLES;
extern const uint8_t _PAC1921_64_SAMPLES;
extern const uint8_t _PAC1921_128_SAMPLES;
extern const uint8_t _PAC1921_256_SAMPLES;
extern const uint8_t _PAC1921_512_SAMPLES;
extern const uint8_t _PAC1921_1024_SAMPLES;
extern const uint8_t _PAC1921_2048_SAMPLES;
extern const uint8_t _PAC1921_VSENSE_ADC_FILTER_ENABLE;
extern const uint8_t _PAC1921_VBUS_ADC_FILTER_ENABLE;
extern const uint8_t _PAC1921_OVERRIDE_ENABLE;
extern const uint8_t _PAC1921_INTEGRATE_STATE;

//control data for _PAC1921_CONTROL_REG register
extern const uint8_t _PAC1921_VPOWER_PIN_CONTROLLED_3000MV_FULL_SCALE_TIMEOUT_DIS_NORMAL_OP;
extern const uint8_t _PAC1921_VSENSE_FREE_RUN;
extern const uint8_t _PAC1921_VBUS_FREE_RUN;
extern const uint8_t _PAC1921_VPOWER_FREE_RUN;
extern const uint8_t _PAC1921_2000MV_FULL_SCALE_RANGE;
extern const uint8_t _PAC1921_1500MV_FULL_SCALE_RANGE;
extern const uint8_t _PAC1921_1000MV_FULL_SCALE_RANGE;
extern const uint8_t _PAC1921_TIMEOUT_ENABLE;
extern const uint8_t _PAC1921_SLEEP_STATE;
extern const uint8_t _PAC1921_FORCED_READ_MODE;
extern const uint8_t _PAC1921_RECALCULATE_DAC_UPDATE_MODE;

                                                                       /** @} */
/** @defgroup PAC1921_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup PAC1921_INIT Driver Initialization */              /** @{ */

#ifdef   __PAC1921_DRV_SPI__
void pac1921_spiDriverInit(T_PAC1921_P gpioObj, T_PAC1921_P spiObj);
#endif
#ifdef   __PAC1921_DRV_I2C__
void pac1921_i2cDriverInit(T_PAC1921_P gpioObj, T_PAC1921_P i2cObj, uint8_t slave);
#endif
#ifdef   __PAC1921_DRV_UART__
void pac1921_uartDriverInit(T_PAC1921_P gpioObj, T_PAC1921_P uartObj);
#endif
                                                                       /** @} */
/** @defgroup PAC1921_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Single write function
 *
 * @param[in] register_address    Register when data be written
 * @param[in] transfer_data       Data witch be written
 *
 * Function writes one byte data to register determined by parametar of function.
 */
void pac1921_singleWriteReg( uint8_t register_address, uint8_t transfer_data );

/**
 * @brief Single read function
 *
 * @param[in] register_address    Register witch from data be read
 *
 * @return    One byte data
 *
 * Function reads one byte data from register determined by parametar of function.
 */
uint8_t pac1921_singleReadReg( uint8_t register_address );

/**
 * @brief Consecutive read function
 *
 * @param[in] register_address    Register witch from data be read
 *
 * @return    One byte data
 *
 * Function sets pointer to one register and can read data consecutive from that register at any time.
 */
uint8_t pac1921_consecutiveReadReg( uint8_t register_address );

/**
 * @brief Block write function
 *
 * @param[in] register_address    Start location when data be written
 * @param[in] data_buffer         Pointer to buffer witch from data be written
 * @param[in] nBytes              Number of bytes witch be written
 *
 * Function writes bytes from buffer to registers with start location determined by register_address parametar.
 */
void pac1921_blockWriteReg( uint8_t register_address, uint8_t *data_buffer, uint8_t nBytes );

/**
 * @brief Block read function
 *
 * @param[in] register_address    Start location witch from data be read
 * @param[out] data_buffer        Pointer to buffer when data be storaged
 * @param[in] nBytes              Number of bytes witch be read
 *
 * Function reads bytes from registers to buffer with start location determined by register_address parametar.
 */
void pac1921_blockReadReg( uint8_t register_address, uint8_t *data_buffer, uint8_t nBytes );

/**
 * @brief Get data function
 *
 * @param[in] data_type            Determined witch data be measured
 * @param[in] nSamples             Determined number of samples for measurement
 *
 * @return    Converted and calculated values from registers
 *
 * Function returns measurement data determined by data_type parametar, witch can be VSENSE (max 100mV), VBUS (max 32V) in mV,
 * or VPOWER (max 320W) witch unit is W.
 * One round of measurement consists of determined number of samples.
 */
float pac1921_getMeasurementData( const uint8_t data_type, const uint8_t nSamples );

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_PAC1921_STM.c
    @example Click_PAC1921_TIVA.c
    @example Click_PAC1921_CEC.c
    @example Click_PAC1921_KINETIS.c
    @example Click_PAC1921_MSP.c
    @example Click_PAC1921_PIC.c
    @example Click_PAC1921_PIC32.c
    @example Click_PAC1921_DSPIC.c
    @example Click_PAC1921_AVR.c
    @example Click_PAC1921_FT90x.c
    @example Click_PAC1921_STM.mbas
    @example Click_PAC1921_TIVA.mbas
    @example Click_PAC1921_CEC.mbas
    @example Click_PAC1921_KINETIS.mbas
    @example Click_PAC1921_MSP.mbas
    @example Click_PAC1921_PIC.mbas
    @example Click_PAC1921_PIC32.mbas
    @example Click_PAC1921_DSPIC.mbas
    @example Click_PAC1921_AVR.mbas
    @example Click_PAC1921_FT90x.mbas
    @example Click_PAC1921_STM.mpas
    @example Click_PAC1921_TIVA.mpas
    @example Click_PAC1921_CEC.mpas
    @example Click_PAC1921_KINETIS.mpas
    @example Click_PAC1921_MSP.mpas
    @example Click_PAC1921_PIC.mpas
    @example Click_PAC1921_PIC32.mpas
    @example Click_PAC1921_DSPIC.mpas
    @example Click_PAC1921_AVR.mpas
    @example Click_PAC1921_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __pac1921_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */