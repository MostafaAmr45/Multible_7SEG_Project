/*********************************************************************************/
/* Author    : Mostafa Amr                                                       */
/* Version   : V01                                                               */
/* Date      : 21 May 2021                                                       */
/*********************************************************************************/
#include "DIO.h"
#include "DISP.h"
#include "DISP_Cfg.h"
#include "MACROS.h"
#define MAX_BCD_VALUE ((unsigned char)9)
#define MAX_NUM_OF_DIGITS ((unsigned char)10)
static const unsigned char BcdTo7SegmentFormat[MAX_NUM_OF_DIGITS] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
	
/*Function shall do the following:
1- To validate the Display ID
2- To validate that data doesn't exceed the maximum BCD value
3- To convert from Decimal to BCD format
4- To use the DIO write function to write each pin data based on the configuration*/
DISP_CheckType DISP_WriteData(unsigned char DispId, unsigned char Data)
{
	unsigned char Loop;
	DISP_CheckType Result;
	unsigned char ChannelId;
	unsigned char BcdData;
	
	/*verify Display Id and that data doesn't exceed the maximum BCD value*/
	if(DispId < DISP_NUM_OF_DISPLAYS || Data < MAX_BCD_VALUE)
	{
		for(Loop = (unsigned char)0; Loop < 7; Loop++)
		{
			ChannelId = DISP_ConfigParam[DispId].DataPinsChannel[Loop];
			/*convert from Decimal to BCD format*/
			BcdData = GET_BIT( BcdTo7SegmentFormat[Data] , Loop);
			/*use the DIO write function to write each pin data based on the configuration*/
			Result = DIO_ChannelWrite(ChannelId , BcdData);
			
			if (Result == DIO_NOK)
			{
				/*DIO write didn't run properly*/
				break;
			}
				
		}
	}
	else
	{	
		/*invalid Display Id*/
		Result = DISP_NOK;
	}
	return Result;
}

/*Function shall do the following:
1- To validate the Disp ID
2- To use the DIO write function to write 0 to the Disp enable pin*/
DISP_CheckType DISP_Enable(unsigned char DispId)
{
	DISP_CheckType Result;
	/*verify Display Id*/
	if(DispId < DISP_NUM_OF_DISPLAYS)
	{
		Result = DIO_ChannelWrite(DISP_ConfigParam[DispId].EnablePinChannel , 0);	
	}
	else
	{
		/*invalid Display Id*/
		Result= DISP_NOK;
	}
	return Result;
}

/*Function shall do the following:
1- To validate the Disp ID
2- To use the DIO write function to write 1 to the Disp enable pin*/
DISP_CheckType DISP_Disable(unsigned char DispId)
{
   	DISP_CheckType Result;
	/*verify Display Id*/
   	if(DispId < DISP_NUM_OF_DISPLAYS)
   	{
		Result =	DIO_ChannelWrite(DISP_ConfigParam[DispId].EnablePinChannel , 1);
   	}
   	else
   	{
		/*invalid Display Id*/
	   	Result= DISP_NOK;
   	}
	return Result;
}
