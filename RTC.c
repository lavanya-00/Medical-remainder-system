#include <LPC21xx.h>
#include "rtc_defines.h"
#include "lcd.h"

signed char week[][10]={"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"};

//RTC INIT CONFIG & ENABLE RTC
void RTC_Init(void)
{
        CCR=RTC_CTC_RESET;//rst rtc
				PREINT=PREINT_VAL;//SET PRESCALER INTEGER PART
        PREFRAC=PREFRAC_VAL;//SET PRESCALER FRACTIONAL PART
        //CCR=RTC_CCR_EN;// ENABLE FOR RTC LPC2129
        CCR=RTC_CCR_EN|RTC_CLK_SRC;//ENABLE FOR 2148 WITH EXTERNAL CLK
}

void RTCGetTime(unsigned int *hr,unsigned int *mi,unsigned int *se)
{
        *hr=HOUR;
        *mi=MIN;
        *se=SEC;
}

void DisplayRTCTime(unsigned int hr,unsigned int mi,unsigned int se)
{
        SetCursor(1,0);
				strlcd("      ");
        charlcd((hr/10)+48);
        charlcd((hr%10)+48);
        charlcd(':');
        charlcd((mi/10)+48);
        charlcd((mi%10)+48);
        charlcd(':');
        charlcd((se/10)+48);
        charlcd((se%10)+48);
}

void RTCGetDate(unsigned int *dt,unsigned int *mo,unsigned int *yr)
{
        *dt=DOM;
        *mo=MONTH;
        *yr=YEAR;
}

void DisplayRTCDate(unsigned int dt,unsigned int mo,unsigned int yr)
{
        SetCursor(3,0);
        charlcd((dt/10)+48);
        charlcd((dt%10)+48);
        charlcd('/');
        charlcd((mo/10)+48);
        charlcd((mo%10)+48);
        charlcd('/');
        u32lcd(yr);
}

void RTCGetDay(unsigned int *day)
{
        *day=DOM;
}
void DisplayRTCDay(unsigned int day)
{
        SetCursor(3,12);
        strlcd(week[day]);
}

void RTCSetTime(unsigned int hr,unsigned int mi,unsigned int se)
{
        HOUR=hr;
        MIN=mi;
        SEC=se;
}
void RTCSetDate(unsigned int dt,unsigned int mo,unsigned int yr)
{
        DOM=dt;
        MONTH=mo;
        YEAR=yr;
}
void RTCSetDay(unsigned int day)
{
        DOM=day;
}
