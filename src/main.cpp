/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
#include "peg.hpp"
#include "lab7.h"
#include "math.h"
#include "Header.h"
#include <embkern.h>
#include <embclib.h>
#include <malloc.h>
#include <video.h>
#include "tunes.inc"
#include <process.h>


/* functions */
void    ShowDriveInfo(char *pWhere);
void	EcsConsoleMsg(char *pMsg);
//void	EcsGuiInit(HANDLE hGuiThread, PegPresentationManager * , EcsPic *);
//void	EcsGuiInit(HANDLE hGuiThread, struct PegPresentationManager  , struct EcsPic );
void	EcsGuiInit(HANDLE *hGuiThread, HANDLE *hpScrMgr , HANDLE *hpEcsPic);
void	EcsGuiQuit(EcsPic *pEcsPic);
char 	EcsDrawBMP(char *file, PegPresentationManager *pScrMgr);

unsigned int __stdcall music_thread(void* pArguments);


char	*gpECSBitmapfile;	/* global */



Ubyte KeyBeep(void);  // wait for key, then BEEP
//Ubyte KeyPressed(); // waits for key to be pressed
//void BEEP(); // sounds a beep on speaker*/


void main()
{
	
	HANDLE hThread_music;
	unsigned int threadID_music;
	hThread_music = (HANDLE)_beginthreadex(NULL,0,&music_thread,NULL,0,&threadID_music);
	SuspendThread(hThread_music);

    	PegPresentationManager *pScrMgr;
	EcsPic *pEcsPic;
	char floor[] = {'0','1','2','3','4','5','6','7','8','9',' '};
	int count, key, autostate = 0, wait = 0;
	int start = 1;
	int end = 1;
	int DoorState = 1;
	

	HANDLE hpEcsPic, hpScrMgr,hGuiThread;

	char c, exit=0;;
	char file2[] ="C:\\IMAGES\\p2.BMP";
	char file3[] ="C:\\IMAGES\\p3.BMP";
	char file4[] ="C:\\IMAGES\\p4.BMP";
	char file5[] ="C:\\IMAGES\\p5.BMP";
	char file6[] ="C:\\IMAGES\\p6.BMP";
	char file7[] ="C:\\IMAGES\\p7.BMP";
	char file8[] ="C:\\IMAGES\\p8.BMP";
	char file9[] ="C:\\IMAGES\\p9.BMP";
	char file10[] ="C:\\IMAGES\\p10.BMP";
	char file11[] ="C:\\IMAGES\\b1.BMP";
	

	/* Initialise graphics */	
	EcsGuiInit(&hGuiThread, &hpScrMgr, &hpEcsPic);	
	pEcsPic = (EcsPic *)hpEcsPic;
	pScrMgr = (PegPresentationManager *)hpScrMgr;
	/* Initialise graphics */	

	LcdInit();		/* Initialise Lcd screen */
	LcdLine1();LcdMsg("Floor No. ");LcdData(floor[start]);
    	LcdLine2();LcdMsg("Press 1 - 10");
	EcsDrawBMP(file11, pScrMgr);
	while(1)
	{	
		key = KeyBeep();
		end = key;
		if( wait == 500 && start == 1 ){

			wait = 0;
		}
		else if( wait == 500 && start != 1 ){

			wait = 0;
			key = 1;
			end = 1;
			LedDisp(1);
			autostate = 1;
			
		}
	
		if(key >= 0 && key <= 9 && start != end){ //After Key press

			count = 0;
			
			while( ((count < 100 && key != 10) || key == 11) && autostate == 0 ){
				key = ScanKey();
				Sleep(10);
				count ++;
			}

			if(DoorState == 1){
			EcsDrawBMP(file2, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file3, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file4, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file5, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file6, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file7, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file8, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file9, pScrMgr);
			Sleep(30);
			}
			EcsDrawBMP(file10, pScrMgr);
			Sleep(500);

			ResumeThread(hThread_music);

			if (end == 0)
				end = 10;
			if(start < end){
				for(;start < end;){
					LcdLine1();LcdMsg("Floor No. ");
					start++;
					if(end == 10 && start == 10){
						LcdData(floor[1]);
						LcdData(floor[0]);
					}
					else
						LcdData(floor[start]);
					Sleep(1200);
				}
			}
			else{
				for(;start > end;){
					start--;
					LcdLine1();
					LcdMsg("Floor No. ");
					LcdData(floor[start]);
					LcdData(floor[10]);
					Sleep(1200);
				}
			}
			SuspendThread(hThread_music);
			Sleep(500);
			EcsDrawBMP(file10, pScrMgr);//opening
			Sleep(30);
			EcsDrawBMP(file9, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file8, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file7, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file6, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file5, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file4, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file3, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file2, pScrMgr);
			Sleep(500);
			LcdLine2();LcdMsg("Floor reached!");
			PlaySong((const char*)CocaCola);
			DoorState = 1;
			Sleep(500);
			LcdLine2();LcdMsg("Press 1 - 10");
			EcsDrawBMP(file11, pScrMgr);
			wait = 0;
			autostate = 0;

		}
		else if(key == 10 && DoorState == 1){// Closing door

			EcsDrawBMP(file2, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file3, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file4, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file5, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file6, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file7, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file8, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file9, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file10, pScrMgr);
			Sleep(500);
			DoorState = 0;
			EcsDrawBMP(file11, pScrMgr);
			wait = 0;
		}
		else if(key == 11 && DoorState == 0){//Opening door
			EcsDrawBMP(file10, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file9, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file8, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file7, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file6, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file5, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file4, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file3, pScrMgr);
			Sleep(30);
			EcsDrawBMP(file2, pScrMgr);
			Sleep(500);
			DoorState = 1;
			EcsDrawBMP(file11, pScrMgr);
			wait = 0;
			//EcsDrawBMP(file1, pScrMgr);
			//Sleep(100);
		}

		Sleep(10);
		wait++;
	}
	LcdClear();
	LcdLine1();LcdMsg("   B Y E   ");

	EcsGuiQuit(pEcsPic);

	WaitForSingleObject(hGuiThread, INFINITE);
    CloseHandle(hGuiThread);
    EcsConsoleMsg("ECS Demo has completed.\n");
}


Ubyte KeyBeep(void)
{
	char c;
	c = KeyPressed();
	if( c >= 0 && c <= 11)
	LedDisp(c);
//	BEEP();
	return c;
}
/* display message to host console */
void EcsConsoleMsg(char *pMsg)
{
	EtsSelectConsole(ETS_CO_HOST);
	printf(pMsg);
}

unsigned int __stdcall music_thread(void* pArguments)
{
	
	while(TRUE)
	{
		PlaySong((const char*)attention);
	}
	return(0);
}
