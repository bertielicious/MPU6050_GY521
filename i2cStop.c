#include "config.h"
void i2cStop(void)
{
    SSP1CON2bits.PEN = HI;  // initiate stop condition
    while(SSP1CON2bits.PEN);   // wait for stop condition to complete
}