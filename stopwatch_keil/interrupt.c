#include "interrupt.h"


//--------------------
//��ʱ���ж�0��1
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
// �ⲿ�ж�0��1
//--------------------
void int0_init()
{
    EA = 1; // �����ж�
    EX0 = 1; // �����ж�0
    IT0 = 1; //���ش���
}

void int1_init()
{
    EA = 1; // �����ж�
    EX1 = 1; // �����ж�1
    IT1 = 1; 
}





