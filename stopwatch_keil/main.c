#include "1602driver.h"
#include "LED.h"

uchar page;//0=menu 1=Timer 2=Count_Down
uchar state;//0=空闲 1=正计时中 2=倒计时中
uchar code keyboard_dictionaries[ ]={'l','1','4','7','d','o','u','0','2','5','8','r','3','6','9','b'};//键盘顺序 123789 10 12 13 14
uchar key[16];//键盘不按下的为X
uchar Zero[]="                ";
uchar menu1[]="1/Timer";//菜单第一行
uchar menu2[]="2/Down";//菜单第二行
uchar Timer[]="Timing";//正计时页面
uchar Count_Down[]="Enter";//倒计时页面


uchar time[4];
uchar time_hidden;
uchar over;//0 =不需要翻页 1需要翻页
uchar over1;//解决跳转时无法跳转
uint text1;
uint text2;


void keyboard_scanning();//扫描键盘


sbit CLK = P3^7;
sbit PL = P3^6;
sbit KEY = P3^5;

void main()
{
    uchar itim;
    uint text;

    TMOD=0x01;
    TH0 = 60536/256;
    TL0 = 60536%256;
    TH1=55536/256;
    TL1=55536%256;
    EA=1;
    ET0=1;
    TR0=1;
    EA = 1; // 开总中断
    EX1 = 1; // 开外中断1
    PX1 = 1; // 外中断1设成高级别中断
    IT1 = 1; // 外中断1设成边沿触发
    EX0 = 1;
    IT0 = 1;
    ET1=1;
    TR1=1;
    PT1=1;
	lcdrw = 0;
	init();
	PL=1;
	CLK=0;
	over=0;
	page=0;
	state=0;
	time_hidden=0;
	delay(5);


      printf_data1x(menu1);
	printf_data2x(menu2);


	while(1)
	{
	switch (page)
	{
	 case 0://---------------- 
	 {
	 EA=0;
	  if(key[1]=='1')
	  {
	  page=1;
	  over=1;

	  } 
	  if(key[8]=='2')
	  {
	  page=2;
	  over=1;

	  }
	    if(over1==0)
	    {
          printf_data1x(menu1);
	    printf_data2x(menu2);
	    over1=1;
	    over=0;
	    page=0;
	    }
	 EA=1;
	 }
       break;


	 case 1 ://------------------
	 {
	 EA=0;
	  if(over==1)
  	  { 
	  printf_data1x(Timer);
	  printf_data2x(Zero);
	  over=0;
	  page=1;
	  }
	  if(key[5]!='X')
	  {
	  state=1;
	  text1=0;
	  time[0]=0;
	 time[1]=0;
	 time[2]=0;
	 time[3]=0;
	  }

	 EA=1;	 
	 }
       break;
	 
	 	
	 case 2 ://--------------
	 { 
	  
	  if(over==1)
 	  { 
	  EA=0;
	  printf_data1x(Count_Down);
 	  printf_data2x(Zero);
	  over=0;
	  page=2;
	  EA=1;
	  }
	  


	  for(itim=0;itim<16;itim++)
	  {
	  if(key[itim]!='X')
	  {
	  time[1]=key[itim];
	  }
	  }

	  if(key[5]!='X')
	  {
	  EA=0;
	  state=2;
	 // text=(time[2]-3)*100;				                                                                                                                                      
	  text1=0;
	  
	 EA=1; 
	  }
	  switch(time[1])
  {
      case'0': text2=0;
   break;
      case'1': text2=100;
   break;
      case'2': text2=200;
   break;
      case'3': text2=300;			    
   break;  
      case'4': text2=400;
   break;
      case'5': text2=500;
   break;
      case'6': text2=600;
   break;		 
      case'7': text2=700;
   break;
      case'8': text2=800;
   break;
      case'9': text2=900;
   break;
      default:
   break;	  
  }

	  
	  	 
	 }
       break;	
   default:
   break;

	}
	text=text1;
	if(state==1)
	{
	 for(itim=0;itim<4;itim++)
	 {
	 time[3-itim]=text%10;
	 text=text/10;
	 }
	 LED_printf(time);
	}

	if(state==2)
	{
	text=text2-text1;
	 for(itim=0;itim<4;itim++)
	 {
	 time[3-itim]=text%10;
	 text=text/10;
	 }
	 LED_printf(time);

//	 if(text==0)

	}


	 


	}///
}


void counter0() interrupt 1 //计时器中断服务函数
{
    LED_printf(time);
    keyboard_scanning();
  
    
    LED_printf(time);
     TH0 = 5536/256;
    TL0 = 5536%256;
}

void counter1() interrupt 3
{
     time_hidden++;  
  if(time_hidden==17)
    {
    time_hidden=0;
    text1 = text1+1;
    if(text1==9999)
    {text1=0;}
    }		   
    TH1=15536/256;
    TL1=15536%256;
}
void int0() interrupt 0 
{
   state=0;
   time_hidden=0;
   text1=0;
   text2=0;

}

void int1() interrupt 2 
{
   page=0;
   over1=0;
   time[0]=0;
   time[1]=0;
   time[2]=0;
   time[3]=0;
}






void keyboard_scanning()
{
  uchar i;
   PL=0;
 delay(1);  
   PL=1;
  for(i=0;i<16;i++)
 {
  key[i]=KEY;
  CLK=0;
 delay(1);   
  CLK=1;
 }
 for(i=0;i<16;i++)
 {
  if(key[i]==1)
  {
  key[i]=keyboard_dictionaries[i];
  }
  if(key[i]==0)
  {
  key[i]='X';
  }
 }

}

  

 