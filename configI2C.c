#include "config.h"
void configI2C(void)
{
    //ANSELBbits.ANSB4 = LO;  //turn off analog pin RB5 (default analog)
    TRISBbits.TRISB4 = HI;  //RB4 pin 13    SDA (I2C) Serial Data is configured as an input pin as required
    TRISBbits.TRISB6 = HI;  //RB6 pin 11    SCL (I2C)Serial Clock is configured as an input pin as required
    
    
    SSPCON1bits.SSP1M3 = HI;//I2C Master Mode, clock = Fosc/(4 * (SSPADD+1)) 
    SSPCON1bits.SSP1M2 = LO;
    SSPCON1bits.SSP1M1 = LO;
    SSPCON1bits.SSP1M0 = LO;
    
    SSPADD = 9; // SSPADD =  ((SCL period/4) * Fosc) - 1        
                //= ((10us/4) * 4MHz) - 1 = 9

    
    SSPCON1bits.SSPEN = HI; // Enables serial port and configures SDA and SCL pins  as source of the serial port   
}           

