#include "config.h"
#include "i2cStart.h"
#include "i2cWrite.h"
#include "i2cStop.h"
void writeMPU6050RegAddr(uchar addrByte, uchar rWbit, uchar regAddrByte, uchar data)
{
    i2cStart();
    i2cWrite((addrByte<<1)|(rWbit));      // write addressByte to MPU6050 and wait for an ACK
    i2cWrite(regAddrByte);   // tell the MPU6050 which internal register we want to write to (PWR_MGMT_1  0x6b)
    i2cWrite(data);         // write required config data to internal register
    i2cStop();
}
