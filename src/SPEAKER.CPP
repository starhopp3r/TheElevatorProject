/****************************************************************/
/* Speaker Output                                               */
/****************************************************************/

#include "Header.h"
extern double		gTimeFact;      /* global variable */

void SpOn()             /* Speaker output is high */    
{
	_outp(DACPort,0x38);
	return;
}

void SpOff()    /* Speaker output is low */
{
	_outp(DACPort, 0x00);
	return;
}

void BEEP()
{
    //Ushort i;
     //gTimeFact = CalibrateTimer();   /* needed for music routines */
    
    //for(i=0;i<150;i++)
    //{
	//	SpOn();
	//	VarDelay(2000);
	//	SpOff();
	//	VarDelay(2000);
    //}
    return;
}

void  Spin(char dir, int steps, char time)
{
    Ushort          i;          /* for counter */
	Ubyte phase;

    if (dir == CCW ) 
	{
	phase = 0x08;               /* Initialize the motor phase for 1st
                                  direction */
    i = 0;
    while (i < steps)
		{
        _outp(SMPort, phase);
        phase >>= 1;
        if (phase == 0x00)
            phase = 0x08;
        Sleep(time);
        i++;
		}
	}
	else
	{
		phase = 0x01; /* Initialize the motor phase for 1st
                                  direction */
    i = 0;
    while (i < steps)
		{
        _outp(SMPort, phase);
        phase <<= 1;
        if (phase == 0x10)
            phase = 0x01;
        Sleep(time);
        i++;
		}
	}

  return;
}

