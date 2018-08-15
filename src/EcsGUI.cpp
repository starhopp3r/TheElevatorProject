/* file for ECS GUI routines */
#include "peg.hpp"
#include "demo.h"
#include "math.h"
#include <embkern.h>
#include <embclib.h>
#include <malloc.h>
#include <video.h>
//#include <peg\pthing.hpp>

extern	char *gpECSBitmapfile;

//extern PegPresentationManager *pScrMgr;
//extern EcsPic *pEcsPic;
//extern HANDLE hGuiThread;
#pragma pack(1)
typedef struct BitmapFile
{
    BITMAPFILEHEADER header;
    BITMAPINFO      info;
}               BITMAPFILE;

/* display message to host console */
void EcsConsoleMsg(char *);
void EcsGuiQuit(EcsPic *pEcsPic);
void EcsGuiInit(HANDLE *hGuiThread,  HANDLE *hpScrMgr , HANDLE *hpEcsPic)
//void EcsGuiInit()
{
	PegRect         Rect;

	EcsPic *pEcsPic;
	PegPresentationManager *pScrMgr;
	EtsSelectFileSystem(ETS_FS_LOCAL);
/*    ShowDriveInfo("Target"); */

	EtsSelectFileSystem(ETS_FS_HOST);	/* have to do this first ! */
	*hGuiThread = EtsGUIStart();   /* start PEG thread */

	pScrMgr = EtsGUIPresentation();
	*hpScrMgr = (HANDLE *)pScrMgr;

	Rect.Set(0, 0, 320, 200);

	pEcsPic = new EcsPic();
	*hpEcsPic = (HANDLE *)pEcsPic;

	pScrMgr->Center(pEcsPic);
	pScrMgr->Add(pEcsPic, FALSE);
	pScrMgr->CapturePointer(pEcsPic);	/* hide mouse forever ?*/
	return;
}

char	EcsDrawBMP(char *fileptr, PegPresentationManager *pScrMgr)
{
	gpECSBitmapfile = fileptr;	/* string containing file name */
	pScrMgr->Invalidate(pScrMgr->mReal);
	pScrMgr->Draw();
	return 0;
}
void EcsGuiQuit(EcsPic *pEcsPic)
{
	PegMessage NewMessage;
	NewMessage.wType = PM_HIDE;		// PM_CLOSE;
//	NewMessage.wType = PM_DESTROY;
	NewMessage.pTarget = pEcsPic;
	NewMessage.pSource = pEcsPic;
    /*NewMessage.iData = PK_ESC;*/
	pEcsPic->MessageQueue()->Push(NewMessage);
/*	pScrMgr->Invalidate(pScrMgr->mReal);
	pScrMgr->Draw();*/

//	pPresentation->DispatchMessage(pEcsPic, (PegMessage) PM_EXIT);
//ScrMgr->Destroy(pEcsPic);
//	pPresentation->Destroy(pPresentation);
//	pPresentation->Message(PM_EXIT);
}

/*--------------------------------------------------------------------------*/
// DialogWin- example dialog window.
/*--------------------------------------------------------------------------*/
EcsPic::EcsPic():PegThing()
{
    // mReal.Set(0, 0, gbDialBitmap.wWidth -1, gbDialBitmap.wHeight - 1);
    mReal.Set(0, 0, 320 - 1, 240 - 1);
    mClient = mReal;
    mClip = mReal;
    miCurrent = 0;
    miDir = 2;
    mpBitmap = NULL;
    mbMoveMode = FALSE;
}

/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
SIGNED          EcsPic::Message(const PegMessage & Mesg)
{
    PegThing       *pTest;
    switch (Mesg.wType)
    {
    case PM_SHOW:
		PegThing::Message(Mesg);
        // SetTimer(1, ONE_SECOND/10, ONE_SECOND/10);
        break;

	case PM_HIDE:
		PegThing::Message(Mesg);
		delete mpBitmap->pStart;
		delete mpBitmap;
		Destroy(this);

//	KillTimer(1);
		break;


/*    case PM_LBUTTONDOWN:
    if (!mbMoveMode)
    {
        mbMoveMode = TRUE;
        Presentation()->CapturePointer(this);
        mStartMove = Mesg.Point;
    }
    break;*/

        /* case PM_LBUTTONUP: if (mbMoveMode) { mbMoveMode = FALSE;
         * Presentation()->ReleasePointer(this); PegRect NewSize = mReal;
         * NewSize.Shift(Mesg.Point.x - mStartMove.x, Mesg.Point.y -
         * mStartMove.y); Resize(NewSize); Parent()->Draw(); } break; */

    case PM_RBUTTONDOWN:
        // spawn a new instance of myself:
        Presentation()->Add(new EcsPic());
        break;

    case PM_KEY:
        if (Mesg.iData == PK_ESC)
        {
            pTest = Presentation()->First();
            while (pTest)
            {
                if (pTest != this)
                {
                    Destroy(pTest);
                    pTest = Presentation()->First();
                }
                else
                {
                    pTest = pTest->Next();
                }
            }
            Destroy(this);
			return(1);
        }
        break;
    case PM_EXIT:
		pTest = Presentation()->First();
        while (pTest)
        {
			if (pTest != this)
            {
				Destroy(pTest);
                pTest = Presentation()->First();
			}
            else
            {
				pTest = pTest->Next();
            }
		}
		/*delete mpBitmap->pStart;
		delete mpBitmap;*/

		Destroy(this);
		PegThing::Message(Mesg);

		return(1);

    default:
		PegThing::Message(Mesg);
		break;
    }
    return 0;
}


/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
void            EcsPic::Draw(void)
{
	#define  PAL8 256
    int             x, y;
    BITMAPFILE     *file;
    FILE           *fp;
    int             fileSize;
    unsigned char  *image, *palette;
    int             index = 0, indx4 = 0;
    unsigned char  *dest;
    unsigned char   PalData[3 * PAL8];  /* palette data structure */
    PegPoint        Put;


    EtsSelectFileSystem(ETS_FS_LOCAL);

    fp = fopen(gpECSBitmapfile, "rb");
    if (!fp)
	{	
		EcsConsoleMsg("Cannot open file\n");
        return;
	}

    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    file = (BITMAPFILE *) malloc(fileSize);
    image = (unsigned char *) file;

    if (!file)
    {
        fclose(fp);
		EcsConsoleMsg("Cannot create bitmap file\n");
        return;
    }

	EcsConsoleMsg("\nLoading bitmap...");
    fread(file, fileSize, 1, fp);
    printf("Done.\n");
    if (file->info.bmiHeader.biBitCount != 8)   /* 8bit bmp? */
	{
		EcsConsoleMsg("Not 8 bit.\n");
        return;
	}


		/* create a bitmap */
	if (!mpBitmap)
	{
		mpBitmap =
		 Screen()->CreateBitmap((short)file->info.bmiHeader.biWidth, 
		 (short)file->info.bmiHeader.biHeight);
		if (!mpBitmap)
		{
			EcsConsoleMsg("Cannot create display\n");
			return;
		}
	}

	/* image palette is just after BITMAPINFOHEADER */
    palette = image + sizeof(BITMAPFILEHEADER) + file->info.bmiHeader.biSize;
    index = 0;
    indx4 = 0;
    for (x = 0; x < PAL8; x++)  /* copy palette to PEG's */
    {
		PalData[index] = palette[indx4 + 2];
        PalData[index + 1] = palette[indx4 + 1];
        PalData[index + 2] = palette[indx4];
        index += 3;
        indx4 += 4;
	}

    Screen()->SetPalette(0, PAL8, (const UCHAR *) & PalData);   /* set PEG palette */

    image += file->header.bfOffBits;
    // Open the bitmap for drawing:

    Screen()->BeginDraw(this, mpBitmap);
    Put.x = Put.y = 0;

    index = 0;

    dest = (unsigned char *) mpBitmap->pStart;

    for (y = 0; y < file->info.bmiHeader.biHeight; y++)
    {
		for (x = 0; x < file->info.bmiHeader.biWidth; x++)
		{
            dest[x + ((file->info.bmiHeader.biHeight - y) - 1) * file->info.bmiHeader.biWidth] = (char)
                (image[index]);
            index++;
        }
    }

    mpBitmap->uFlags = BMF_RAW;
    mpBitmap->dTransColor = 0;
    mpBitmap->uBitsPix = 8;

	free(file);
    fclose(fp);

//	Add(new PegTitle(Title));
//	SetScrollMode(WSM_VSCROLL|WSM_HSCROLL|WSM_CONTINUOUS);

    Screen()->SetPointerType(PPT_VSIZE);
//    Screen()->HidePointer();
	Put.x = Put.y = -10;

    Screen()->SetPointer(Put);
	;
        // Close the bitmap for drawing:
    Screen()->EndDraw(mpBitmap);

    BeginDraw();
	//CapturePointer();
	Put.x = mReal.iLeft;
	Put.y = mReal.iTop + 20;
	Bitmap(Put, mpBitmap);
	EndDraw();
}


void            ShowDriveInfo(char *pWhere)
{
    char            curdir[256];
    DWORD           dwBytesSector, dwSectorsPerCluster, dwFreeClusters, dwClusters;
    EtsSelectConsole(ETS_CO_HOST);

    GetCurrentDirectory(sizeof(curdir), curdir);
    GetDiskFreeSpace(NULL, &dwSectorsPerCluster, &dwBytesSector,
                     &dwFreeClusters, &dwClusters);
    printf("Current Directory on %s is: %s\n", pWhere, curdir);
    printf("  Sector Size:     %d bytes\n", dwBytesSector);
    printf("  Cluster Size:    %d bytes\n",
           dwSectorsPerCluster * dwBytesSector);
    printf("  Available Space: %ld Kbytes\n",
           (dwFreeClusters * dwSectorsPerCluster) / (1024 / dwBytesSector));
}


