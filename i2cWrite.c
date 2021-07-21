#include "config.h"
void i2cWrite(uchar byte)
{
    SSP1BUF = byte; // load data contained in byte to the buffer
    while(!PIR1bits.SSP1IF); // shift bits out of SSP1BUF until the interrupt flag is set at 9th SCL pulse
    PIR1bits.SSP1IF = LO;           // clear the interrupt flag ready for the next trigger
    __delay_us(5);
    if(SSP1CON2bits.ACKSTAT)       // if NACK received
    {
        SSP1CON2bits.PEN = HI;          // initiate stop condition
        while(SSP1CON2bits.PEN);  // wait for stop condition to complete
    }
}
