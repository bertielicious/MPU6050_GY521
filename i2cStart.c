#include "config.h"
void i2cStart(void)
{
    SSPCON2bits.SEN = HI;   // start condition begins
    while(SSP1CON2bits.SEN);             // wait until SEN is LO (start condition is complete)
    PIR1bits.SSP1IF = LO;   // clear Synchronous serial port interrupt flag
}