#include "RTC.h"
#include "lcd.h"
#include <LPC21xx.H>
#include "kpm.h"
#include "delay.h"
#define SW1 16
#define SW2 17
#define BUZ 20

unsigned char keyv;
unsigned int hour,min,sec,day,date,month,year,num=0,mh=23,mm=12,ms=33;
unsigned char keyv;

int main()
{
	IODIR0 |=1<<BUZ;
	RTC_Init();
	initlcd();
	Init_KPM();
	cmdlcd(0x0C);
	RTCSetTime(23,12,30);
	RTCSetDate(31,1,2025);
	RTCSetDay(2);
	while(1)
	{
		do
		{
			RTCGetTime(&hour,&min,&sec);
			DisplayRTCTime(hour,min,sec);
			RTCGetDate(&date,&month,&year);
			DisplayRTCDate(date,month,year);
			RTCGetDay(&day);
			DisplayRTCDay(day);
			if((hour==mh)&&(min==mm)&&(sec==ms))
			{
				IOSET0=1<<BUZ;
				while(1)
				{

					if(((IOPIN0>>SW2)&1)==1)
					{
						while(((IOPIN0>>SW2)&1)==1);
						IOCLR0= 1<<BUZ;
						break;
					}
				cmdlcd(0x01);
				cmdlcd(0xc0);
				strlcd("   Medicine Alert!!");
				delayms(700);
				cmdlcd(0x01);
				}
			}
			
		}while((((IOPIN0>>SW1)&1)==0)&&(((IOPIN0>>SW1)&1)==0));
		
		//while(((IOPIN0>>SW1)&1)==0);
		if(((IOPIN0>>SW1)&1)==1)
		{
			while(((IOPIN0>>SW1)&1)==1);
			cmdlcd(0x01);
			cmdlcd(0x80);
			strlcd("Hello user press:");
			cmdlcd(0xc0);
			strlcd("1.RTC Edit");
			cmdlcd(0x94);
			strlcd("2.Medicine time edit");
			while(colscan()==0);
			keyv = keyscan();
			while(colscan()==1);
			if(keyv=='1')
			{
				cmdlcd(0x01);
				cmdlcd(0x80);
				strlcd("1.Hour 2.Min 3.Sec");
				cmdlcd(0xc0);
				strlcd("4.Day 5.Date 6.Month");
			  cmdlcd(0x94);
				strlcd("7.Year 8.EXIT");
				while(colscan()==0);
				keyv = keyscan();
			  while(colscan()==1);
				switch(keyv)
				{
					case '1':cmdlcd(0x01);
									 cmdlcd(0x0F);
									 cmdlcd(0xc0);
									 strlcd("Hour :");
									num=0;
                  while(1)
                  {
                  while(colscan()==0);
                  keyv = keyscan();
                  delayus(100);
                  while(colscan()==1);
                  if(keyv=='*')
									{
										keyv=keyv/10;
										cmdlcd(0x10);
										charlcd(' ');
										cmdlcd(0x10);
										num=num/10;
										continue;
									}
									else if((keyv>='0')&&(keyv<='9'))
                  {
										charlcd(keyv);
										num = num*10 +(keyv-48);
                  }
                  else if(keyv=='#')
                     break;
                  }
									if(num>23)
									{
										cmdlcd(0x01);
										cmdlcd(0xc0);
										strlcd("Invalid input");
										delays(1);
										cmdlcd(0x0C);
										cmdlcd(0x01);
										break;
									}
                  hour = num;
                  RTCSetTime(hour,min,sec);
                  cmdlcd(0x0C);
                  cmdlcd(0x01);
									break;            
									
					case '2':cmdlcd(0x01);
									 cmdlcd(0x0F);
									 cmdlcd(0xc0);
									 strlcd("Min :");
									num=0;
                  while(1)
                  {
                  while(colscan()==0);
                  keyv = keyscan();
                  delayus(100);
                  while(colscan()==1);
									if(keyv=='*')
									{
										keyv=keyv/10;
										cmdlcd(0x10);
										charlcd(' ');
										cmdlcd(0x10);
										num=num/10;
										continue;
									}
                  else if((keyv>='0')&&(keyv<='9'))
                  {
										charlcd(keyv);
										num = num*10 +(keyv-48);
                  }
                  else if(keyv=='#')
                     break;
                  }
									if(num>60)
									{
										cmdlcd(0x01);
										cmdlcd(0xc0);
										strlcd("Invalid input");
										delays(1);
										cmdlcd(0x0C);
										cmdlcd(0x01);
										break;
									}
                  min = num;
                  RTCSetTime(hour,min,sec);
                  cmdlcd(0x0C);
                  cmdlcd(0x01);
                  break;
									
									
				  case '3':cmdlcd(0x01);
									 cmdlcd(0x0F);
									 cmdlcd(0xc0);
									 strlcd("Sec :");
									num=0;
                  while(1)
                  {
                  while(colscan()==0);
                  keyv = keyscan();
                  delayus(100);
                  while(colscan()==1);
									if(keyv=='*')
									{
										keyv=keyv/10;
										cmdlcd(0x10);
										charlcd(' ');
										cmdlcd(0x10);
										num=num/10;
										continue;
									}
                  else if((keyv>='0')&&(keyv<='9'))
                  {
										charlcd(keyv);
										num = num*10 +(keyv-48);
                  }
                  else if(keyv=='#')
                     break;
                  }
									if(num>59)
									{
										cmdlcd(0x01);
										cmdlcd(0xc0);
										strlcd("Invalid input");
										delays(1);
										cmdlcd(0x0C);
										cmdlcd(0x01);
										break;
									}
                  sec = num;
                  RTCSetTime(hour,min,sec);
                  cmdlcd(0x0C);
                  cmdlcd(0x01);
                  break;
									
									
					case '4':cmdlcd(0x01);
									 cmdlcd(0x0F);
									 cmdlcd(0xc0);
									 strlcd("Day :");
									num=0;
                  while(1)
                  {
                  while(colscan()==0);
                  keyv = keyscan();
                  delayus(100);
                  while(colscan()==1);
									if(keyv=='*')
									{
										keyv=keyv/10;
										cmdlcd(0x10);
										charlcd(' ');
										cmdlcd(0x10);
										num=num/10;
										continue;
									}
                  else if((keyv>='0')&&(keyv<='9'))
                  {
										charlcd(keyv);
										num = num*10 +(keyv-48);
                  }
                  else if(keyv=='#')
                     break;
                  }
									if(num>6)
									{
										cmdlcd(0x01);
										cmdlcd(0xc0);
										strlcd("Invalid input");
										delays(1);
										cmdlcd(0x0C);
										cmdlcd(0x01);
										break;
									}
                  day = num;
                  RTCSetDay(num);
                  cmdlcd(0x0C);
                  cmdlcd(0x01);
                  break;
									
									
					case '5':cmdlcd(0x01);
									 cmdlcd(0x0F);
									 cmdlcd(0xc0);
									 strlcd("Date :");
									num=0;
                  while(1)
                  {
                  while(colscan()==0);
                  keyv = keyscan();
                  delayus(100);
                  while(colscan()==1);
                  if(keyv=='*')
									{
										keyv=keyv/10;
										cmdlcd(0x10);
										charlcd(' ');
										cmdlcd(0x10);
										num=num/10;
										continue;
									}
									else if((keyv>='0')&&(keyv<='9'))
                  {
										charlcd(keyv);
										num = num*10 +(keyv-48);
                  }
                  else if(keyv=='#')
                     break;
                  }
									if(num>31)
									{
										cmdlcd(0x01);
										cmdlcd(0xc0);
										strlcd("Invalid input");
										delays(1);
										cmdlcd(0x0C);
										cmdlcd(0x01);
										break;
									}
                  date = num;
                  RTCSetDate(date,month,year);
                  cmdlcd(0x0C);
                  cmdlcd(0x01);
                  break;
									
									
					case '6':cmdlcd(0x01);
									 cmdlcd(0x0F);
									 cmdlcd(0xc0);
									 strlcd("Month :");
									num=0;
                  while(1)
                  {
                  while(colscan()==0);
                  keyv = keyscan();
                  delayus(100);
                  while(colscan()==1);
                  if(keyv=='*')
									{
										keyv=keyv/10;
										cmdlcd(0x10);
										charlcd(' ');
										cmdlcd(0x10);
										num=num/10;
										continue;
									}
									else	if((keyv>='0')&&(keyv<='9'))
                  {
										charlcd(keyv);
										num = num*10 +(keyv-48);
                  }
                  else if(keyv=='#')
                     break;
                  }
									if(num>12)
									{
										cmdlcd(0x01);
										cmdlcd(0xc0);
										strlcd("Invalid input");
										delays(1);
										cmdlcd(0x0C);
										cmdlcd(0x01);
										break;
									}
                  month = num;
                  RTCSetDate(date,month,year);
                  cmdlcd(0x0C);
                  cmdlcd(0x01);
                  break;
									
					case '7':cmdlcd(0x01);
									 cmdlcd(0x0F);
									 cmdlcd(0xc0);
									 strlcd("Year :");
									num=0;
                  while(1)
                  {
                  while(colscan()==0);
                  keyv = keyscan();
                  delayus(100);
                  while(colscan()==1);
									if(keyv=='*')
									{
										keyv=keyv/10;
										cmdlcd(0x10);
										charlcd(' ');
										cmdlcd(0x10);
										num=num/10;
										continue;
									}
                  else if((keyv>='0')&&(keyv<='9'))
                  {
										charlcd(keyv);
										num = num*10 +(keyv-48);
                  }
                  else if(keyv=='#')
                     break;
                  }
                  if(num>25)
									{
										cmdlcd(0x01);
										cmdlcd(0xc0);
										strlcd("Invalid input");
										delays(1);
										cmdlcd(0x0C);
										cmdlcd(0x01);
										break;
									}
									year = num;
                  RTCSetDate(date,month,year);
                  cmdlcd(0x0C);
                  cmdlcd(0x01);
                  break;
									
					case '8':cmdlcd(0x01);
									 cmdlcd(0x80);
									 break;
									
					default :cmdlcd(0x01);
									 cmdlcd(0xc0);
									 strlcd("Invalid choice");
									 delays(1);
									 cmdlcd(0x01);
									 cmdlcd(0x80);
									 break;
				}

			} 
			
			if(keyv=='2')
			{
					cmdlcd(0x01);
					cmdlcd(0x80);
					strlcd("Medicine Time Edit");
					cmdlcd(0xc0);
				  strlcd("1.Hour 2.Min 3.Sec");
				  cmdlcd(0x94);
				  strlcd("4.EXIT");
				  while(colscan()==0);
				keyv = keyscan();
			  while(colscan()==1);
				switch(keyv)
				{
						case '1':cmdlcd(0x01);
									 cmdlcd(0x0F);
									 cmdlcd(0xc0);
									 strlcd("Hour :");
									num=0;
                  while(1)
                  {
                  while(colscan()==0);
                  keyv = keyscan();
                  delayus(100);
                  while(colscan()==1);
                  if(keyv=='*')
									{
										keyv=keyv/10;
										cmdlcd(0x10);
										charlcd(' ');
										cmdlcd(0x10);
										num=num/10;
										continue;
									}
									else if((keyv>='0')&&(keyv<='9'))
                  {
										charlcd(keyv);
										num = num*10 +(keyv-48);
                  }
                  else if(keyv=='#')
                     break;
                  }
									if(num>23)
									{
										cmdlcd(0x01);
										cmdlcd(0xc0);
										strlcd("Invalid input");
										delays(1);
										cmdlcd(0x0C);
										cmdlcd(0x01);
										break;
				          }
									mh = num;
                  cmdlcd(0x0C);
                  cmdlcd(0x01);
									break;
									
				case '2':cmdlcd(0x01);
									 cmdlcd(0x0F);
									 cmdlcd(0xc0);
									 strlcd("Min :");
									num=0;
                  while(1)
                  {
                  while(colscan()==0);
                  keyv = keyscan();
                  delayus(100);
                  while(colscan()==1);
                  if(keyv=='*')
									{
										keyv=keyv/10;
										cmdlcd(0x10);
										charlcd(' ');
										cmdlcd(0x10);
										num=num/10;
										continue;
									}
									else if((keyv>='0')&&(keyv<='9'))
                  {
										charlcd(keyv);
										num = num*10 +(keyv-48);
                  }
                  else if(keyv=='#')
                     break;
                  }
									if(num>60)
									{
										cmdlcd(0x01);
										cmdlcd(0xc0);
										strlcd("Invalid input");
										delays(1);
										cmdlcd(0x0C);
										cmdlcd(0x01);
										break;
									}
                  mm = num;
                  cmdlcd(0x0C);
                  cmdlcd(0x01);
                  break;
									
									
				  case '3':cmdlcd(0x01);
									 cmdlcd(0x0F);
									 cmdlcd(0xc0);
									 strlcd("Sec :");
									num=0;
                  while(1)
                  {
                  while(colscan()==0);
                  keyv = keyscan();
                  delayus(100);
                  while(colscan()==1);
                  if(keyv=='*')
									{
										keyv=keyv/10;
										cmdlcd(0x10);
										charlcd(' ');
										cmdlcd(0x10);
										num=num/10;
										continue;
									}
									else	if((keyv>='0')&&(keyv<='9'))
                  {
										charlcd(keyv);
										num = num*10 +(keyv-48);
                  }
                  else if(keyv=='#')
                     break;
                  }
									if(num>59)
									{
										cmdlcd(0x01);
										cmdlcd(0xc0);
										strlcd("Invalid input");
										delays(1);
										cmdlcd(0x0C);
										cmdlcd(0x01);
										break;
									}
                  ms = num;
                  cmdlcd(0x0C);
                  cmdlcd(0x01);
                  break;
									
							
				case '4':cmdlcd(0x01);
									 cmdlcd(0x80);
									 break;
									
				default :cmdlcd(0x01);
									 cmdlcd(0xc0);
									 strlcd("Invalid choice");
									 delays(1);
									 cmdlcd(0x01);
									 cmdlcd(0x80);
									 break;
			}
		}
			
	}
		
	
}
}

