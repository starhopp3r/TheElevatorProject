/****************************************************************/
/* Keypad module                                                */
/****************************************************************/
#include "Header.h"

const Ubyte ColScan[4] =
/*  Col7,Col6,Col5,Col4 */
{   0x7f,0xBF,0xDF,0xEF};
const Ubyte ScanTable[12] = 
/*   0    1    2    3   */
{   0x7D,0xEB,0xED,0xEE,
/*   4    5    6    7   */
	0xDB,0xDD,0xDE,0xBB,
/*   8    9    A    B   */      
	0xBD,0xBE,0x7B,0x7E};

Ubyte KeyPressed()
{
	Ubyte key;
	key = ScanKey();
	return key;
}


void KeyRelease()
{
while (ScanKey() != 0xff);
}

Ubyte KeyAny()
{
		
	_outp(KbdPort,0x0F);         /* All columns to zero */
		
	if ((_inp(KbdPort) & 0x07) == 0x07)
	return( 0xFF);
	else 
	return (0x00);

}
Ubyte ProcKey(Ubyte c)
{
	Ubyte i;

	for(i=0;i<=12;i++)
	    if(c == ScanTable[i]) return i;
    
    if(i==12)
	return 0xff;    /* if not found, return 0xFF */
return 0 ;

}
Ubyte ScanKey()
{
    Ushort z; Ubyte c;
	_outp(KbdPort,0x0F);         /* All columns to zero */
  
    for(z=0;z<4;z++)
    {
	_outp(KbdPort,ColScan[z]);       /* Scan column by column */
	c = _inp(KbdPort);             /* Read */

	c |= 0xF0;               /* High nybble to 1 */
	c &= ColScan[z]; /* AND back scan value */

	if(c != ColScan[z])
		return ProcKey(c);
    }
    
    return 0xFF;
}

