#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int

sbit led0=P2^3;
sbit led1=P2^4;

void LED_printf(uchar a[]);