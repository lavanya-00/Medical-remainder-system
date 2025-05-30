#ifndef _RTC_DEFINES_H
#define _RTC_DEFINES_H
#define FOSC 12000000
#define CCLK (5*FOSC)
#define PCLK (CCLK/4)

//RTC MACROS
#define PREINT_VAL (int)((PCLK/32768))
#define PREFRAC_VAL (PCLK-((PREINT+1)*32768))
#define RTC_CCR_EN (1<<0)
#define RTC_CTC_RESET (1<<1)
#define RTC_CLK_SRC (1<<4)
#endif 
