/*
 *                  16f1459
 *                  ---------
 *   +5 Volts    1 |Vdd      | 20 0 Volts
        LCD D6   2 |RA5   RA0| 19
 *    motor ACW  3 |RA4   RA1| 18
 *    MCLR/ RST  4 |RA3      | 17  MOTOR DIRECTION
 *    GREEN LED  5 |RC5   RC0| 16  LIGHT SENSOR (analog)
 *    RS         6 |RC4   RC1| 15  RTC INPUT
 *    EN         7 |RC3   RC2| 14  TOP LIMIT SWITCH
 *    LCD D4     8 |RC6   RB4| 13  SDA i2C
 *    LCD D5     9 |RC7   RB5| 12  LCD D7
 *    TX        10 |RB7   RB6| 11  SCL i2C
 *                  ---------
 motor CW and BOTTOM LIMIT SWITCH need to be allocated  uC pin each
 */
#include "config.h"
void configPorts(void)
{
    ANSELA = 0x00;                  // disable all analogue inputs
    ANSELB = 0x00;
    ANSELC = 0x00;
    
    CM1CON0 = 0x00;                 // all COMPARATORS off
    CM2CON0 = 0x00;
    CM1CON1 = 0x00;
    CM2CON1 = 0x00;
    TRISBbits.TRISB5 = LO;  //RB5 pin 12    Diagnostic LED
    
    DIAGNOSTIC_LED = LO;     //turn off Diagnostic LED
}
