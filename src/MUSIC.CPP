#include "Header.h"
/* Play songs routine */

/*******************/
/* Music constants */
/*******************/
/* Calculated in no of timer count */
/* Based on frequency of the note  */
/* For example: frequency of Middle C = 262 Hz */
const Ushort NoteHPeriod[]=
{
/*  C    C#   D    D#   E    F    F#   G    G#   A    A#   B   */  
	3817,3610,3401,3215,3030,2865,2703,2551,2410,2273,2146,2024,
/*  C'   C#'  D'   D#'  E'   F'   F#'  G'   G#'  A'   A#'  B'   C''*/
	1912,1805,1704,1608,1517,1433,1351,1276,1203,1136,1073,1012,955
};

/* Calculate the duration of notes */
/* 3 types are calculated: crotchet, quaver, semiquaver */
/* Note value => crotchet = 1, quaver = 2, semiquaver = 3 */
/* Basically, it's no of waves produced */
const Ushort Crotchet[]=
{
/*       C   C#  D   D#  E   F   F#  G   G#  A   A#  B  */      
	131,139,147,156,165,175,185,196,208,220,233,247,
/*   C'  C#' D'  D#' E'  F'  F#' G'  G#' A'  A#' B'  C''*/
	262,277,294,311,330,349,370,392,416,440,466,494,524
};

const Ushort Quaver[]=
{
/*       C   C#  D   D#  E   F   F#  G   G#  A   A#  B  */      
	66,  70, 74, 78, 83, 88, 93, 98, 104,110,117,124, 
/*   C'  C#' D'  D#' E'  F'  F#' G'  G#' A'  A#' B'  C''*/
	131,139,147,156,165,175,185,196,208,220,233,247,262
};

const Ushort SemiQuaver[]=
{
/*       0   1   2   3   4   5   6   7   8   9   10  11 */
/*       C   C#  D   D#  E   F   F#  G   G#  A   A#  B  */      
	33,  35, 37, 39, 42, 44, 47, 49, 52, 55, 59, 62,
/*   12  13  14  15  16  17  18  19  20  21  22  23  24 */ 
/*   C'  C#' D'  D#' E'  F'  F#' G'  G#' A'  A#' B'  C''*/
	66,  70, 74, 78, 83, 88, 93, 98,104,110,117,124,131
};

double		gTimeFact;      /* global variable */

/* Inputs a song as a string of notes */
//#include "string.h"
void            PlaySong(const char *song)
{
    Ushort		no, duration;
    int			note;       /* index of the note played currently */
	char		*substr;	/* ptr to substr */
	Ushort		loop;       /* value of the note played currently */
    Ushort      hperiod;    /* value of delay to generate the note */
    /* notes */
    char            notes[] =
    "C C#D D#E F F#G G#A A#B c c#d d#e f f#g g#a a#b H \0";
    char srchnote[3];
    no = 0;
     gTimeFact = CalibrateTimer();   /* needed for music routines */

    while (song[no])          /* play till null pointer */
    {
		if (KeyAny() == 0) return; /* stop if any key is press */
		srchnote[0]= song[no];
		no++;
        duration = song[no];
        /* next note is a sharp */
        if (duration == '#')
        {
			srchnote[1]= (char)duration;
			no++;
            duration = song[no];
        }
        else
			srchnote[1]= 0x20;

		srchnote[2]= 0;
        /* search for the note value among permitted notes */
		substr = strstr(notes, srchnote);
		if (substr == NULL)
		{
			printf("Not a valid note");
			break;	/* not valid note */
		}
		note = substr-notes;
		note = (note / 2);		/* make compatible with current */

        switch (duration)
            /* look for duration */
        {
        case 'c':
            loop = Crotchet[note];
            break;
        case 'q':
            loop = Quaver[note];
            break;
        case 's':
            loop = SemiQuaver[note];
            break;
        }

        hperiod = NoteHPeriod[note];

        while (loop != 0)
        {
            SpOn();
            VarDelay(hperiod);
            SpOff();
            VarDelay(hperiod);
            loop--;
        }
		no++;
    }
    return;
}

