#include <LPC21xx.H>
#include "lcd_define.h"
#include "delay.h"
#include "lcd.h"

void initlcd(void)
{
        IODIR0|=255<<(LCD_DATA);
        IODIR0|=(1<<RS)|(1<<RW)|(1<<EN);

        delayms(15);
        cmdlcd(0x30);
        delayms(5);
        cmdlcd(0x30);
        delayus(100);
        cmdlcd(0x30);// 8bit mode  1 line
        cmdlcd(0x38);    //      2 line
        cmdlcd(0x0E);     //dsp on cur off
        cmdlcd(0x01); // clear lcd
        cmdlcd(0x06);   //dspon cur blink

}  
void writelcd(unsigned char dat)
{
        IOCLR0 =1<<RW;
        IOPIN0 = (IOPIN0&~(255<<LCD_DATA))|(dat<<LCD_DATA);
        IOSET0 = 1<<EN;
        delayus(1);
        IOCLR0=1<<EN;
        delayms(2);//internal write op
}
void charlcd(unsigned char ascii)
{
        IOSET0=1<<RS;
        writelcd(ascii);
}

void cmdlcd(unsigned char cmd)
{
        IOCLR0=1<<RS;
        writelcd(cmd);
}

void SetCursor(unsigned char lineNo,unsigned char pos)
{
        if(lineNo==1)
                cmdlcd(GOTO_LINE1_POS0+pos);
        else if(lineNo==2)
                cmdlcd(GOTO_LINE2_POS0+pos);
        else if(lineNo==3)
                cmdlcd(GOTO_LINE3_POS0+pos);
        else if(lineNo==4)
                cmdlcd(GOTO_LINE4_POS0+pos);
}
void strlcd(unsigned char *str)
{
        while(*str)
        {
                charlcd(*str++);
        }
}
void u32lcd(unsigned int num)
{
        unsigned char a[10];
        signed int i=0;
        if(num==0)
        {
                charlcd('0');
        }
        else
        {
                while(num)
                {
                        a[i++]=(num%10)+48;
                        num=num/10;
                }
                for(--i;i>=0;i--)
                {
                        charlcd(a[i]);
                }
        }

}
