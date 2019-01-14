/*
Example for PAC1921 Click

    Date          : Jan 2018.
    Author        : Nemanja Medakovic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.1.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes click driver.
- Application Task - (code snippet) - Gets VBUS measurement data witch be measured in 512 samples. 
  Results logs on USB UART and repeats measurement every 500ms.

*/

#include "Click_PAC1921_types.h"
#include "Click_PAC1921_config.h"

float data_read;
char text[100] = {0};

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_OUTPUT );

    mikrobus_i2cInit( _MIKROBUS1, &_PAC1921_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART, 9600 );

    Delay_ms( 100 );
}

void applicationInit()
{
    pac1921_i2cDriverInit( (T_PAC1921_P)&_MIKROBUS1_GPIO, (T_PAC1921_P)&_MIKROBUS1_I2C, 0x00 );

    Delay_ms( 100 );
    
    data_read = 0;
}

void applicationTask()
{
    data_read = pac1921_getMeasurementData( _PAC1921_VBUS_FREE_RUN, _PAC1921_512_SAMPLES );

    FloatToStr( data_read, text );
    mikrobus_logWrite( text, _LOG_TEXT );
    if ( _PAC1921_UNIT == 0 )
    {
        mikrobus_logWrite( " mV", _LOG_LINE );
    }
    else
    {
        mikrobus_logWrite( " W", _LOG_LINE );
    }
        
    Delay_ms( 500 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}
