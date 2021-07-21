#include "config.h"
void putch (uchar byte)
{
    while( ! TXIF)
    continue;
    TXREG = byte;
}
