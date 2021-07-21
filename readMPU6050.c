#include "config.h"
#include "i2cStart.h"
#include "i2cWrite.h"
#include "i2cRead.h"
#include "i2cReStart.h"
#include "i2cStop.h"
uchar readMPU6050(uchar addrByte, uchar rwBit, uchar regAddrByte)
{
    uchar readByteMPU = 0;
    i2cStart();
    i2cWrite((addrByte<<1)|(rwBit));      //write address byte 0xd0
    i2cWrite (regAddrByte);  // let MPU6050 know which internal register is to be read  (temp L = 0x41)
    i2cStart();
    //i2cReStart();
    i2cWrite((addrByte<<1)|(rwBit + 1)); // read data from internal register  temp L  0x41
    readByteMPU = i2cRead();
    i2cStop();
 return readByteMPU;   
}