#include "config.h"
uchar i2cRead(void)
{
    uchar readByte = 0;
    SSP1CON2bits.RCEN = HI; // enables Master receive mode from Slave for i2c
    while(!SSPSTATbits.BF);     // while buffer is not full keep reading data into it
    readByte = SSP1BUF;
    SSP1CON2bits.ACKDT = HI;      // prepare to send NACK
    SSP1CON2bits.ACKEN = HI;      // initiate NACK
    while(SSP1CON2bits.ACKEN);               // wait for NACK to repeat
    return readByte;
}
