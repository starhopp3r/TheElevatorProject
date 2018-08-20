/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
// dialog.hpp - Example dialog window using signals.
//
// Author: Kenneth G. Maxwell
//
// Date: 12/30/97
//
// Version: 1.00
//
// Copyright (c) 1993-1998 Swell Software 
//              All Rights Reserved.
//
// Unauthorized redistribution of this source code, in whole or part,
// without the express written permission of Swell Software
// is strictly prohibited.
//
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/

class EcsPic : public PegThing
{
	public:
    EcsPic();
    SIGNED Message(const PegMessage &Mesg);
	void Draw(void);

	private:
	PegBitmap *mpBitmap;
	SIGNED miCurrent;
	SIGNED miDir;
	BOOL mbMoveMode;
	PegPoint mStartMove;

	void DrawToBitmap(void);
};
