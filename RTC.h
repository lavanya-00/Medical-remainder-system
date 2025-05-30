#ifndef _RTC_H
#define _RTC_H

void RTC_Init(void);
void RTCGetTime(unsigned int *,unsigned int *,unsigned int *);
void DisplayRTCTime(unsigned int,unsigned int,unsigned int);

void RTCGetDate(unsigned int *,unsigned int *,unsigned int*);
void DisplayRTCDate(unsigned int,unsigned int,unsigned int);

void RTCGetDay(unsigned int *);
void DisplayRTCDay(unsigned int );

void RTCSetTime(unsigned int ,unsigned int,unsigned int);
void RTCSetDate(unsigned int ,unsigned int,unsigned int);
void RTCSetDay(unsigned int);


#endif
