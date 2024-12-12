#include "interrupt.h"


//--------------------
//计时器中断0和1
//--------------------
void counter0_init(uchar i)
{
    TMOD=i;
    EA=1;
    ET0=1;
    TR0=1;
}
void counter0_num(uchar i)
{
     TH0 = i/256;
     TL0 = i%256;
}


void counter1_init(uchar i)
{
    TMOD=i;
    EA=1;
    ET1=1;
    TR1=1;
}
void counter1_num(uchar i)
{
     TH1 = i/256;
     TL1 = i%256;
}

void counter1() interrupt 3
{

}

//--------------------
// 外部中断0和1
//--------------------
void int0_init()
{
    EA = 1; // 开总中断
    EX0 = 1; // 开外中断0
    IT0 = 1; //边沿触发
}

void int1_init()
{
    EA = 1; // 开总中断
    EX1 = 1; // 开外中断1
    IT1 = 1; 
}





