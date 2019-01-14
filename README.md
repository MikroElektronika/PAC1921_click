![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# PAC1921 Click

- **CIC Prefix**  : PAC1921
- **Author**      : Nemanja Medakovic
- **Version**     : 1.0.0
- **Date**        : Jan 2018.

---

### Software Support

We provide a library for the PAC1921 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2314/pac1921-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Initializes click driver functions and I2C bus driver. Offers a choise for single or block writting to registers and reading from registers.
Also offers a choise for calculating power and different types of voltage in different number of samples and different full scale range.
Fore more details check documentation. 

Key functions :

- ``` float pac1921_getMeasurementData( const uint8_t data_type, const uint8_t nSamples, const uint8_t full_scale ) ``` - Function returns measurement data determined by 
  data_type parametar, witch can be VSENSE (max 100mV), VBUS (max 32V) in mV, or VPOWER (max 320W) witch unit is W. One round of measurement consists of determined number of samples.
- ``` void pac1921_blockReadReg( uint8_t register_address, uint8_t *data_buffer, uint8_t nBytes ) ``` - Function reads bytes from registers to buffer 
  with start location determined by register_address parametar.
- ```  void pac1921_singleWriteReg( uint8_t register_address, uint8_t transfer_data ) ``` - Function writes one byte data to register determined by parametar of function.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes click driver.
- Application Task - (code snippet) - Gets VBUS measurement data witch be measured in 512 samples. 
  Results logs on USB UART and repeats measurement every 500ms.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2314/pac1921-click) page.

Other mikroE Libraries used in the example:

- Conversions
- I2C
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
