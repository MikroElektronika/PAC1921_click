/*
    __pac1921_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__pac1921_driver.h"
#include "__pac1921_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

uint8_t _PAC1921_CONFIGURATION_BYTE;
uint8_t _PAC1921_CONTROL_BYTE;
uint8_t _PAC1921_UNIT;
uint8_t check_pointer;
uint8_t temp;
uint8_t temp1;
uint16_t out_fsr;

const uint8_t _PAC1921_SLAVE_ADDRESS = 0x4C;

const uint8_t _PAC1921_GAIN_CONFIGURATION_REG = 0x00;
const uint8_t _PAC1921_INTEGRATION_CONFIGURATION_REG = 0x01;
const uint8_t _PAC1921_CONTROL_REG = 0x02;
const uint8_t _PAC1921_VBUS_HIGH_BYTE_REG = 0x10;
const uint8_t _PAC1921_VBUS_LOW_BYTE_REG = 0x11;
const uint8_t _PAC1921_VSENSE_HIGH_BYTE_REG = 0x12;
const uint8_t _PAC1921_VSENSE_LOW_BYTE_REG = 0x13;
const uint8_t _PAC1921_VSUM_HIGH_BYTE_REG = 0x14;
const uint8_t _PAC1921_VSUM_MIDDLE_HIGH_BYTE_REG = 0x15;
const uint8_t _PAC1921_VSUM_MIDDLE_LOW_BYTE_REG = 0x16;
const uint8_t _PAC1921_VSUM_LOW_BYTE_REG = 0x17;
const uint8_t _PAC1921_ISUM_HIGH_BYTE_REG = 0x18;
const uint8_t _PAC1921_ISUM_MIDDLE_HIGH_BYTE_REG = 0x19;
const uint8_t _PAC1921_ISUM_MIDDLE_LOW_BYTE_REG = 0x1A;
const uint8_t _PAC1921_ISUM_LOW_BYTE_REG = 0x1B;
const uint8_t _PAC1921_OVERFLOW_STATUS_REG = 0x1C;
const uint8_t _PAC1921_VPOWER_HIGH_BYTE_REG = 0x1D;
const uint8_t _PAC1921_VPOWER_LOW_BYTE_REG = 0x1E;
const uint8_t _PAC1921_SAMPLES_HIGH_BYTE_REG = 0x21;
const uint8_t _PAC1921_SAMPLES_LOW_BYTE_REG = 0x22;
const uint8_t _PAC1921_PSUM_HIGH_BYTE_REG = 0x23;
const uint8_t _PAC1921_PSUM_MIDDLE_HIGH_BYTE_REG = 0x24;
const uint8_t _PAC1921_PSUM_MIDDLE_BYTE_REG = 0x25;
const uint8_t _PAC1921_PSUM_MIDDLE_LOW_BYTE_REG = 0x26;
const uint8_t _PAC1921_PSUM_LOW_BYTE_REG = 0x27;
const uint8_t _PAC1921_PRODUCT_ID_REG = 0xFD;
const uint8_t _PAC1921_MANUFACTURER_ID_REG = 0xFE;
const uint8_t _PAC1921_REVISION_REG = 0xFF;

const uint8_t _PAC1921_ADC_RESOLUTION_14_BIT_GAIN_1X = 0x00;
const uint8_t _PAC1921_ADC_RESOLUTION_VSENSE_11_BIT = 0x80;
const uint8_t _PAC1921_ADC_RESOLUTION_VBUS_11_BIT = 0x40;
const uint8_t _PAC1921_DIG_CURRENT_GAIN_2X = 0x08;
const uint8_t _PAC1921_DIG_CURRENT_GAIN_4X = 0x10;
const uint8_t _PAC1921_DIG_CURRENT_GAIN_8X = 0x18;
const uint8_t _PAC1921_DIG_CURRENT_GAIN_16X = 0x20;
const uint8_t _PAC1921_DIG_CURRENT_GAIN_32X = 0x28;
const uint8_t _PAC1921_DIG_CURRENT_GAIN_64X = 0x30;
const uint8_t _PAC1921_DIG_CURRENT_GAIN_128X = 0x38;
const uint8_t _PAC1921_DIG_BUS_VOLTAGE_GAIN_2X = 0x01;
const uint8_t _PAC1921_DIG_BUS_VOLTAGE_GAIN_4X = 0x02;
const uint8_t _PAC1921_DIG_BUS_VOLTAGE_GAIN_8X = 0x03;
const uint8_t _PAC1921_DIG_BUS_VOLTAGE_GAIN_16X = 0x04;
const uint8_t _PAC1921_DIG_BUS_VOLTAGE_GAIN_32X = 0x05;

const uint8_t _PAC1921_1_SAMPLE_ADC_FILTER_DISABLE_OVERRIDE_DISABLE_READ_STATE = 0x00;
const uint8_t _PAC1921_2_SAMPLES = 0x10;
const uint8_t _PAC1921_4_SAMPLES = 0x20;
const uint8_t _PAC1921_8_SAMPLES = 0x30;
const uint8_t _PAC1921_16_SAMPLES = 0x40;
const uint8_t _PAC1921_32_SAMPLES = 0x50;
const uint8_t _PAC1921_64_SAMPLES = 0x60;
const uint8_t _PAC1921_128_SAMPLES = 0x70;
const uint8_t _PAC1921_256_SAMPLES = 0x80;
const uint8_t _PAC1921_512_SAMPLES = 0x90;
const uint8_t _PAC1921_1024_SAMPLES = 0xA0;
const uint8_t _PAC1921_2048_SAMPLES = 0xB0;
const uint8_t _PAC1921_VSENSE_ADC_FILTER_ENABLE = 0x08;
const uint8_t _PAC1921_VBUS_ADC_FILTER_ENABLE = 0x04;
const uint8_t _PAC1921_OVERRIDE_ENABLE = 0x02;
const uint8_t _PAC1921_INTEGRATE_STATE = 0x01;

const uint8_t _PAC1921_VPOWER_PIN_CONTROLLED_3000MV_FULL_SCALE_TIMEOUT_DIS_NORMAL_OP = 0x00;
const uint8_t _PAC1921_VSENSE_FREE_RUN = 0x40;
const uint8_t _PAC1921_VBUS_FREE_RUN = 0x80;
const uint8_t _PAC1921_VPOWER_FREE_RUN = 0xC0;
const uint8_t _PAC1921_2000MV_FULL_SCALE_RANGE = 0x10;
const uint8_t _PAC1921_1500MV_FULL_SCALE_RANGE = 0x20;
const uint8_t _PAC1921_1000MV_FULL_SCALE_RANGE = 0x30;
const uint8_t _PAC1921_TIMEOUT_ENABLE = 0x08;
const uint8_t _PAC1921_SLEEP_STATE = 0x04;
const uint8_t _PAC1921_FORCED_READ_MODE = 0x02;
const uint8_t _PAC1921_RECALCULATE_DAC_UPDATE_MODE = 0x01;

#ifdef   __PAC1921_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __PAC1921_DRV_SPI__

void pac1921_spiDriverInit(T_PAC1921_P gpioObj, T_PAC1921_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __PAC1921_DRV_I2C__

void pac1921_i2cDriverInit(T_PAC1921_P gpioObj, T_PAC1921_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    check_pointer = 0x03;
    temp = 0xFF;
    temp1 = 0xFF;

    pac1921_singleWriteReg( _PAC1921_GAIN_CONFIGURATION_REG, _PAC1921_ADC_RESOLUTION_VSENSE_11_BIT | _PAC1921_ADC_RESOLUTION_VBUS_11_BIT );
    pac1921_singleWriteReg( _PAC1921_CONTROL_REG, _PAC1921_VPOWER_PIN_CONTROLLED_3000MV_FULL_SCALE_TIMEOUT_DIS_NORMAL_OP | _PAC1921_FORCED_READ_MODE | _PAC1921_RECALCULATE_DAC_UPDATE_MODE );
    pac1921_singleWriteReg( _PAC1921_INTEGRATION_CONFIGURATION_REG, _PAC1921_OVERRIDE_ENABLE | _PAC1921_INTEGRATE_STATE );
}

#endif
#ifdef   __PAC1921_DRV_UART__

void pac1921_uartDriverInit(T_PAC1921_P gpioObj, T_PAC1921_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void pac1921_singleWriteReg( uint8_t register_address, uint8_t transfer_data )
{
    uint8_t buffer_data[2] = {0};
    
    if (register_address > 256)
    {
        return;
    }
    if (transfer_data > 256)
    {
        return;
    }
    
    buffer_data[0] = register_address;
    buffer_data[1] = transfer_data;
    
    hal_i2cStart();
    hal_i2cWrite( _PAC1921_SLAVE_ADDRESS, buffer_data, 2, END_MODE_STOP );
    
    if (register_address == 0x01)
    {
        _PAC1921_CONFIGURATION_BYTE = transfer_data;
    }
    else if (register_address == 0x02)
    {
        _PAC1921_CONTROL_BYTE = transfer_data;
    }
}

uint8_t pac1921_singleReadReg( uint8_t register_address )
{
    uint8_t data_ = 0;
    
    if (register_address > 256)
    {
        return;
    }
    
    hal_i2cStart();
    hal_i2cWrite( _PAC1921_SLAVE_ADDRESS, &register_address, 1, END_MODE_RESTART );
    hal_i2cRead( _PAC1921_SLAVE_ADDRESS, &data_, 1, END_MODE_STOP );
    
    return data_;
}

uint8_t pac1921_consecutiveReadReg( uint8_t register_address )
{
    uint8_t data_ = 0;
    
    if (register_address > 256)
    {
        return;
    }
    
    if (check_pointer != register_address)
    {
        hal_i2cStart();
        hal_i2cWrite( _PAC1921_SLAVE_ADDRESS, &register_address, 1, END_MODE_STOP );
        check_pointer = register_address;
    }
    hal_i2cStart();
    hal_i2cRead( _PAC1921_SLAVE_ADDRESS, &data_, 1, END_MODE_STOP );
    
    return data_;
}

void pac1921_blockWriteReg( uint8_t register_address, uint8_t *data_buffer, uint8_t nBytes )
{
    uint8_t buffer_data[3] = {0};
    uint8_t cnt = 0;
    uint8_t count = 0;
    
    if (nBytes > 3)
    {
        return;
    }
    if (register_address > 256)
    {
        return;
    }
    
    buffer_data[0] = register_address;
    cnt = nBytes;
    while (cnt > 0)
    {
        buffer_data[count + 1] = data_buffer[count];
        cnt--;
        count++;
    }
    
    nBytes++;
    hal_i2cStart();
    hal_i2cWrite( _PAC1921_SLAVE_ADDRESS, buffer_data, nBytes, END_MODE_STOP );
    
    if (register_address == 0x00)
    {
        if (nBytes == 2)
        {
            _PAC1921_CONFIGURATION_BYTE = data_buffer[1];
            return;
        }
        else if (nBytes == 3)
        {
            _PAC1921_CONFIGURATION_BYTE = data_buffer[1];
            _PAC1921_CONTROL_BYTE = data_buffer[2];
            return;
        }
    }
    else if (register_address == 0x01)
    {
        if (nBytes == 1)
        {
            _PAC1921_CONFIGURATION_BYTE = data_buffer[0];
            return;
        }
        else if (nBytes == 2)
        {
            _PAC1921_CONFIGURATION_BYTE = data_buffer[0];
            _PAC1921_CONTROL_BYTE = data_buffer[1];
            return;
        }
    }
    else if (register_address == 0x02)
    {
        if (nBytes == 1)
        {
            _PAC1921_CONTROL_BYTE = data_buffer[0];
        }
    }
}

void pac1921_blockReadReg( uint8_t register_address, uint8_t *data_buffer, uint8_t nBytes )
{
    if (nBytes > 28)
    {
        return;
    }
    if (register_address > 256)
    {
        return;
    }
    
    hal_i2cStart();
    hal_i2cWrite( _PAC1921_SLAVE_ADDRESS, &register_address, 1, END_MODE_RESTART );
    hal_i2cRead( _PAC1921_SLAVE_ADDRESS, data_buffer, nBytes, END_MODE_STOP );
}

float pac1921_getMeasurementData( const uint8_t data_type, const uint8_t nSamples )
{
    uint8_t buff_data[2] = {0};
    uint8_t buff_sampl[2] = {0};
    uint8_t registerAddress = 0;
    uint16_t res = 0;
    float retVal = 0;
    uint16_t samples_num = 0;
    uint8_t i_max = 10;
    uint8_t v_max = 32;
    
    if (data_type & 0x3F)
    {
        return;
    }
    if (nSamples & 0x0F)
    {
        return;
    }

    _PAC1921_CONTROL_BYTE &= 0x3F;
    _PAC1921_CONTROL_BYTE |= data_type;
    
    _PAC1921_CONFIGURATION_BYTE &= 0x0F;
    _PAC1921_CONFIGURATION_BYTE |= nSamples;

    if (temp != _PAC1921_CONTROL_BYTE)
    {
        pac1921_singleWriteReg( _PAC1921_CONTROL_REG, _PAC1921_CONTROL_BYTE );
        temp = _PAC1921_CONTROL_BYTE;
    }
    if (temp1 != _PAC1921_CONFIGURATION_BYTE)
    {
        pac1921_singleWriteReg( _PAC1921_INTEGRATION_CONFIGURATION_REG, _PAC1921_CONFIGURATION_BYTE );
        temp1 = _PAC1921_CONFIGURATION_BYTE;
    }
    
    switch (data_type)
    {
        case 0x40 : registerAddress = 0x12;
                    out_fsr = 100;
                    break;
        case 0x80 : registerAddress = 0x10;
                    out_fsr = 32000;
                    break;
        case 0xC0 : registerAddress = 0x1D;
    }
    
    pac1921_blockReadReg( registerAddress, buff_data, 2 );
    
    res = buff_data[0];
    res <<= 2;
    buff_data[1] >>= 6;
    res |= buff_data[1];
    
    if (data_type == 0xC0)
    {
        retVal = res / 1023.0;
        retVal *= i_max;
        retVal *= v_max;

        _PAC1921_UNIT = 1;
    }
    else
    {
        retVal = res / 1023.0;
        retVal *= out_fsr;
        
        _PAC1921_UNIT = 0;
    }
    
    return retVal;
}

/* -------------------------------------------------------------------------- */
/*
  __pac1921_driver.c

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