/*
 * File:   main.c
 * Author: User
 *
 * Created on 04 July 2021, 20:14
 */


#include "config.h"
#include <stdio.h>
#include "configOsc.h"
#include "configPorts.h"
#include "configEUSART.h"
#include "configI2C.h"
#include "readMPU6050.h"
#include "writeMPU6050RegAddr.h"

void main(void) 
{

    configOsc(); 
    configPorts();
    configI2C();
    configEUSART();
    

    printf("Hiya Philboy!\n");
    writeMPU6050RegAddr(0x68, 0x00, SMPLRT_DIV, 0x07);// 1kHz sample rate
    writeMPU6050RegAddr(0x68, 0x00, PWR_MGMT_1, 0x00);// write 0x00 to register 0x6b Power Management register
    writeMPU6050RegAddr(0x68, 0x00, CONFIG, 0x00);// Fs = 8KHz
    writeMPU6050RegAddr(0x68, 0x00, GYRO_CONFIG, 0x18);//Full scale range +/- 2000 degree/C
    writeMPU6050RegAddr(0x68, 0x00, INT_ENABLE, 0x00);//
    
    
     
         __delay_ms(1);
   
    signed int resultLow = 0;
    signed int resultHigh = 0;
    signed int T;
    float t;
    
    int xout_H, xout_L = 0;
    int xout16 = 0;
    
    
    while(1)
    {
        
        resultLow = readMPU6050(0x68,0x00,TEMP_OUT_L);  // Read temperature of chip die
        resultHigh = readMPU6050(0x68,0x00,TEMP_OUT_H);
        T = (resultHigh<<8)|resultLow;    
        t = ((float)T/340.00)+36.53;/* Convert temperature in °/c */
        printf("t = %.1f C\n", t);
        
        
        xout_L = readMPU6050(0x68, 0x00, ACCEL_XOUT_L);
        xout_H = readMPU6050(0x68, 0x00, ACCEL_XOUT_H);
        
        xout16 = (xout_H<<8)|xout_L;
        printf("xout16 = %d\n", xout16);
        
        
        
        DIAGNOSTIC_LED = HI;
        __delay_ms(500);
        DIAGNOSTIC_LED = LO;
        __delay_ms(500);
    }
}
