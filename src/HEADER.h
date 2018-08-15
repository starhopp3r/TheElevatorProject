#include <conio.h>
#include <stdio.h>
#include <windows.h>
#define Ubyte   unsigned char
#define Ushort  unsigned short int

// The addresses of the devices
#define DACPort   0x330
#define LEDPort   0x332
#define LcdPort   0x333
#define KbdPort   0x334
#define SMPort    0x335

/* Keypad Module */
Ubyte ScanKey();	// do a scan, returns key value 0 to 0xb
Ubyte KeyAny();	// returns 0 for key and ff for no key
void  KeyRelease(); // waits for key to be released
Ubyte KeyPressed(); // waits for key to be pressed

/* Speaker Module */
void SpOn();
void SpOff();
void BEEP(); // sounds a beep on speaker

/* LCD Module */
void LcdInit();	// initialise LCD to 4 bits format
void LcdCmd (Ubyte d);	// outputs a LCD command
void LcdData (Ubyte data); // outputs a LCD data
void LcdClear();	// clears the LCD
void LcdLine1();	// goto line 1
void LcdLine2();	// goto line 2
void LcdMsg(char *ptr); // display a string on LCD
void LedDisp(char c);	// display a hex value on LED

void PlaySong(const char *song);  // plays a song, see tunes.inc for instructions
double CalibrateTimer();
/* Delay Module */
void VarDelay(int tick);

#define CW 0   // define stepper directions
#define CCW 1
void  Spin(char dir, int steps, char time);
/* Choose dir as CW or CCW
		steps - no. of steps
		time - time between steps in milliseconds
		*/

