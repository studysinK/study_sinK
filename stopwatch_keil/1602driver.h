#include <reg52.h>

#ifndef _1602DRIVER_H_
#define _1602DRIVER_H_


#define uchar unsigned char
#define uint unsigned int

sbit lcden = P2^2;
sbit lcdrs = P2^0;
sbit lcdrw = P2^1;

void delay(uint z);
void write_com(uchar com);//写指令
void write_data(uchar date);//按位写数据
void init();//复位
void printf_data1(uchar ch[]);//写入第一行
void printf_data1x(uchar ch[]);//刷新写入第一行
void printf_data2(uchar ch[]);//写入第二行
void printf_data2x(uchar ch[]);//刷新写入第二行
void LCD_Roll(char _c);
void LCD_Page_Turning_R();//翻页
void LCD_Page_Turning_l();//翻页
void LCD_cursor_R();//光标移动
void LCD_cursor_L();//光标移动

#endif