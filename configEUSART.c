#include "config.h"
void configEUSART (void)
{
    /*The EUSART transmitter is enabled for asynchronous
    operations by configuring the following three control
    bits:*/
    TXSTAbits.TXEN = HI;    /*Setting the TXEN bit of the TXSTA register enables the
                                transmitter circuitry of the EUSART.*/
    TXSTAbits.SYNC = LO;    /*Clearing the SYNC bit of the TXSTA register configures
                             the EUSART for asynchronous operation.*/
    RCSTAbits.SPEN = HI;    /*Setting the SPEN bit of the
                            RCSTA register enables the EUSART and automatically
                            configures the TX/CK I/O pin as an output. If the TX/CK
                            pin is shared with an analog peripheral, the analog I/O
                            function must be disabled by clearing the corresponding
                            ANSEL bit. The TXIF Transmitter Interrupt flag is set
                            when the TXEN enable bit is set.*/
    SPBRG = 0x19;
}
