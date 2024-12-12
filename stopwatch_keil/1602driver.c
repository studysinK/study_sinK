#include "1602driver.h"

uchar pagination=1;

void delay(uint z)
{
	uint x,y;
	for(x = z;x > 0;x--)
		{
			for(y = 110;y > 0;y--);
		}
}
 
void write_com(uchar com)
{
	lcdrs = 0;
	P0 = com;
	delay(5);
	lcden = 1;
	
	delay(5);
	lcden = 0;
}
 
void write_data(uchar date)
{
	lcdrs = 1;
	P0 = date;
	delay(5);
	lcden = 1;
	delay(5);
	lcden = 0;
}

void printf_data1(uchar ch[])
{
 	uint i;
	write_com(0x80);
   	lcdrs = 1;
	for(i=0;ch[i]!='\0';i++)
	{
	 P0 = ch[i];
 	 delay(5);
 	 lcden = 1;
 	 delay(5);
	 lcden = 0;
	}
}
void printf_data1x(uchar ch[]) ////
{
 	uint i;
	write_com(0x0a);
	write_com(0x80);
   	lcdrs = 1;
	for(i=0;ch[i]!='\0';i++)
	{
	 P0 = ch[i];
 	 delay(5);
 	 lcden = 1;
 	 delay(5);
	 lcden = 0;
	}
	write_com(0x0e);
} 
void printf_data2(uchar ch[])
{
 	uint i;
	write_com(0x80 + 0x40);
   	lcdrs = 1;
	for(i=0;ch[i]!='\0';i++)
	{
	 P0 = ch[i];
 	 delay(5);
 	 lcden = 1;
 	 delay(5);
	 lcden = 0;
	}
}
 
 void printf_data2x(uchar ch[])
{
 	uint i;
	write_com(0x0a);
	write_com(0x80 + 0x40);
   	lcdrs = 1;
	for(i=0;ch[i]!='\0';i++)
	{
	 P0 = ch[i];
 	 delay(5);
 	 lcden = 1;
 	 delay(5);
	 lcden = 0;
	}
	write_com(0x0e);
}



void LCD_Roll(char _dir) //������Ļ:'1'-���ҹ���һ��,'2'-����
{
    if (_dir == 1 || _dir == 1)
    {
        write_com(0x18); //���
    }
    else if (_dir == 2 || _dir == 2)
    {
        write_com(0x1C); //�ҹ�
    }
}

void LCD_Page_Turning_R()	//�ҷ�ҳ
{
	
	uint i=0;
	write_com(0x0a);
	for(i=0;i<16;i++)
	{
	write_com(0x18);
	}
	write_com(0x0e);
}

void LCD_Page_Turning_L()	//��ҳ
{
	
	uint i=0;
	write_com(0x0a);
	for(i=0;i<16;i++)
	{
	write_com(0x1c);
	}
	write_com(0x0e);
}

void LCD_cursor_R()
{
	write_com(0x14);
}
void LCD_cursor_L()
{
	write_com(0x10);
}

void init()
{
	lcden = 0;
	write_com(0x38);
	write_com(0x0f);
	write_com(0x06);
	write_com(0x01);
	write_com(0x0e);
}
 