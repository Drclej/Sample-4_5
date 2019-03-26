#include <msp430f249.h>
#define uchar unsigned char
#define uint unsigned int

#define SHCP_H P3OUT |= BIT2
#define SHCP_L P3OUT &=~ BIT2
#define DS_H P3OUT |= BIT1
#define DS_L P3OUT &=~ BIT1
#define STCP_H P3OUT |= BIT0
#define STCP_L P3OUT &=~ BIT0

void sendbyte (uchar data)
{
  uchar i,k;
  for(i=0;i<8;i++)
  {
    if((data & 0x80) == 0)
      DS_L;
    else
      DS_H;
    data <<= 1;
    SHCP_H;
    for(k=1;k>0;--k);
    SHCP_L;
    for(k=1;k>0;--k);    
  }
}

