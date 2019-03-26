#include <msp430f249.h>
#include "led.h"
#include "sendbyte.h"
#define uchar unsigned char
#define uint unsigned int
#define SHCP_H P3OUT |= BIT2
#define SHCP_L P3OUT &=~ BIT2


void initialize(void)
{
  P1SEL = 0x00;
  P1DIR = 0xFF;
  P1OUT = 0X00;
  
  P3SEL = 0x00;
  P3DIR = 0xFF;
  P3OUT = 0X00;
}

void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  initialize();

    while(1)
    {
        LEDshow();
    }
}
