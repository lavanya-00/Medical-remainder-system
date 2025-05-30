#include <LPC21xx.H>
#include "kpm.h"

unsigned char KPM_LUT[4][4]={{'1','2','3','/'},{'4','5','6','*'},{'7','8','9','-'},{'A','0','#','+'}};
void Init_KPM(void)
{
        IODIR1 |= (15<<ROW0);
}

unsigned char keyscan(void)
{
        unsigned char rno,cno,keyv;
        while(colscan()==0);
        rno= rowcheck();
        cno= colcheck();
        keyv= KPM_LUT[rno][cno];

        return keyv;
}

unsigned char colscan(void)
{
        //if swpress is lessthan 15 1
        //else 0
      return(((IOPIN1>>COL0)&15)<15)?1:0;

}

unsigned char rowcheck(void)
{
        unsigned char rno;
        for(rno=0;rno<4;rno++)
        {
                IOPIN1 = (IOPIN1&~(15<<ROW0))|(~(1<<rno)<<ROW0);
                if(colscan()==1)
                        break;
        }
        IOPIN1 = (IOPIN1&~(15<<ROW0))|(0x0<<ROW0);
        return rno;
}

unsigned char colcheck(void)
{
        unsigned char cno;
        for(cno=0;cno<4;cno++)
        {
                if(((IOPIN1>>(COL0+cno))&1)==0)
                {
                        break;
                }
        }
        return cno;
}
