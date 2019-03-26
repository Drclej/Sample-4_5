#include <msp430f249.h>
#include "led.h"
#include "sendbyte.h"
#define uchar unsigned char
#define uint unsigned int
#define STCP_H P3OUT |= BIT0
#define STCP_L P3OUT &=~ BIT0

uchar const Table_of_Kanji[] = 
{
0x00,0x00,0x3F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x04,0x40,0x04,0x40,
0x04,0x40,0x04,0x40,0x08,0x40,0x08,0x42,0x10,0x42,0x20,0x42,0x40,0x3E,0x80,0x00,
};

uint const Table_of_rows[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
                                0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};

void delayus(uint t)
{
  while (t--);
}


void LEDshow (void)
{
  uchar row;
  uint i;
  uint bit;
  bit = 0;
  uint k;
    for(row = 0;row < 16;++row)
    {
      for(i=0;i<16;++i)
      {
        sendbyte(Table_of_Kanji[bit]);
        bit++;
      }

      P1OUT = Table_of_rows[row];
      STCP_L;
      for(k=16;k>0;--k);
      STCP_H;
      for(k=16;k>0;--k);
    }

}