/****************************************************************/
/* Lcd module                                                   */
/****************************************************************/
#include "Header.h"

void LcdInit()
{
	_outp(LcdPort,0x00);
	Sleep(1);
    
    /* Initialize the Lcd */
    LcdCmd(0x33);     /* Initialise */
    LcdCmd(0x33);     /* Twice! */
    LcdCmd(0x32);     /* 4 bit mode */
    LcdCmd(0x28);     /* 4 bit, 2 lines font 0 */
    LcdCmd(0x08);     /* Display off */
    LcdCmd(0x0C);     /* Display on */
    LcdCmd(0x06);     /* entry mode set, incr, cursor move */
    LcdCmd(0x80);     /* cursor at 00H */
    LcdCmd(0x0F);     /* blink it */
	LcdCmd(0x01);
	return;
}

/* Pin layout: 7  6  5  4  3  2  1  0
			   D7 D6 D5 D4 X  E R/W RS */

/* Outputs a Lcd command */            
void LcdOut(Ubyte data)
{
	_outp(LcdPort,data);
/*    Sleep(1);*/
}
            
void LcdData(Ubyte dval)
{
	Ubyte c;
	/* OUTPUT UPPER NIBBLE DATA */
	c = dval & 0xf0;
	c = c | 0x01;	/* RS = 1 */
	LcdOut(c);
	c = c | 0x04;	/* E = 1 */
	LcdOut(c);
	c = c & 0xfb;	/* E = 0 */
	LcdOut(c);

	/* OUTPUT LOWER NIBBLE DATA */
	c = dval;
	c <<= 4;
	c = c | 0x01;	/* RS = 1 */
	LcdOut(c);
	c = c | 0x04;	/* E = 1 */
	LcdOut(c);
	c = c & 0xfb;	/* E = 0 */
	LcdOut(c);
    Sleep(1);
}

void LcdCmd(Ubyte d)
{
	Ubyte c;
	/* OUTPUT UPPER NIBBLE DATA */
	c = d & 0xf0;	/* RS = 0 */		
	LcdOut(c);
	c = c | 0x04;	/* E = 1 */	
	LcdOut(c);
	c = c & 0xfb;	/* E = 0 */
	LcdOut(c);
	/* OUTPUT LOWER NIBBLE DATA */
	d <<= 4;
	c = d & 0xf0;	/* RS = 0 */
	LcdOut(c);
	c = c | 0x04;	/* E = 1 */
	LcdOut(c);
	c = c & 0xfb;	/* E = 0 */
	LcdOut(c);
    Sleep(1);
}

void LcdClear()
{
	LcdCmd(0x01);
	return;
}

/* Go to Lcd Line 1 */
void LcdLine1()
{
	LcdCmd(0x80);
	return;
}

/* Go to Lcd Line 2 */
void LcdLine2()
{
	LcdCmd(0xC0);
	return;
}

void LcdMsg(char *ptr)
{
    while(*ptr)
    {
	LcdData(*ptr);
	++ptr;
    }
    return;
}

// 7 Segment LED  display
const Ubyte     Bin2LED[] =
/*  0    1    2    3   */
{0xC0, 0x79, 0x24, 0x30,
/*   4    5    6    7   */
    0x19, 0x12, 0x02, 0x78,
/*   8    9    A    B   */
    0x00, 0x18, 0x08, 0x03,
/*   C    D    E    F   */
0x46, 0x21, 0x06, 0x0E};

void LedDisp(char c) // LedDisp(0) to LedDisp(0xf);
{
	if(c<=0xf)
    _outp(LEDPort, Bin2LED[c]);
	else 
	_outp(LEDPort, 0x3f);
}
