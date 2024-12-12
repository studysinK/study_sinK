#include <reg52.h>

#ifndef _1602DRIVER_H_
#define _1602DRIVER_H_


#define uchar unsigned char
#define uint unsigned int

sbit lcden = P2^2;
sbit lcdrs = P2^0;
sbit lcdrw = P2^1;

void delay(uint z);
void write_com(uchar com);//дָ��
void write_data(uchar date);//��λд����
void init();//��λ
void printf_data1(uchar ch[]);//д���һ��
void printf_data1x(uchar ch[]);//ˢ��д���һ��
void printf_data2(uchar ch[]);//д��ڶ���
void printf_data2x(uchar ch[]);//ˢ��д��ڶ���
void LCD_Roll(char _c);
void LCD_Page_Turning_R();//��ҳ
void LCD_Page_Turning_l();//��ҳ
void LCD_cursor_R();//����ƶ�
void LCD_cursor_L();//����ƶ�

#endif