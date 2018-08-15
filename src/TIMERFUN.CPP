/***************************/
/* Delay modules           */
/***************************/


#include "Header.h"
#define MAX_DBL   0xFFFFFFFFFFFFFFFF

double CalibrateTimer()
{
	LARGE_INTEGER t;
	double gTimeFact;
	QueryPerformanceFrequency(&t);
	gTimeFact = (double)(1000000*60)/t.QuadPart;
	return gTimeFact;
}

void VarDelay(int tick)
{
	LARGE_INTEGER t;
	extern double gTimeFact;
	double start, endt, period;
	QueryPerformanceCounter(&t);
//	gTimeFact = (double)(1000000*60)/t.QuadPart;
	period = 0;
	start = (double)t.QuadPart;
	while (period < tick)
	{
		QueryPerformanceCounter(&t);
		endt = (double)t.QuadPart;
		if (endt < start)		/* count past 0 */
			period = MAX_DBL + (endt - start);
		else 
			period = (100*(endt - start))/gTimeFact;
	}
}

