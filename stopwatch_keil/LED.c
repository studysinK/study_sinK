#include "LED.h"

uchar  seg[] = {0x3F,  //"0"
                0x06,  //"1"
                0x5B,  //"2"
                0x4F,  //"3"
                0x66,  //"4"
                0x6D,  //"5"
                0x7D,  //"6"
                0x07,  //"7"
                0x7F,  //"8"
                0x6F,  //"9"
		    };
void LEDdelay(uint z)
{
	uint x,y;
	for(x = z;x > 0;x--)
		{
			for(y = 110;y > 0;y--);
		}
}

void LED_printf(uchar ab[])
{


 uchar i;
 uchar k;
 uchar kk;
 for(i=0;i<4;i++)
 {
   k=ab[i];
  switch(k)
  {
      case'0': kk=0;
   break;
      case'1': kk=1;
   break;
      case'2': kk=2;
   break;
      case'3': kk=3;
   break;  
      case'4': kk=4;
   break;
      case'5': kk=5;
   break;
      case'6': kk=6;
   break;
      case'7': kk=7;
   break;
      case'8': kk=8;
   break;
      case'9': kk=9;
   break;
   ////////////////////
      case 0: kk=0;
   break;
      case 1: kk=1;
   break;
      case 2: kk=2;
   break; 
      case 3: kk=3;
   break;  
      case 4: kk=4;
   break;
      case 5: kk=5;
   break;
      case 6: kk=6;
   break;
      case 7: kk=7;
   break;
      case 8: kk=8;
   break;
      case 9: kk=9;
   break;
   ////////////////////
   default:
   break;	  

  }
  if(i==2)
  {
   P1=seg[ kk ]+0x80;
  led0=i/2;
  led1=i%2;
  LEDdelay(4);
  P1=0X00;
  }
  else
  {
     P1=seg[ kk ];
  led0=i/2;
  led1=i%2;
  LEDdelay(4);
  P1=0X00;
  }
 }


}