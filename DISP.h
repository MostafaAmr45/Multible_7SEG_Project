/*********************************************************************************/
/* Author    : Mostafa Amr                                                       */
/* Version   : V01                                                               */
/* Date      : 21 May 2021                                                       */
/*********************************************************************************/
#ifndef DSIP_H_INCLUDED
#define DSIP_H_INCLUDED

#define DISP_OK ((unsigned char)0)
#define DISP_NOK ((unsigned char)1)
typedef unsigned char DISP_CheckType;
DISP_CheckType DISP_WriteData(unsigned char DispId,unsigned char Data);
DISP_CheckType DISP_Enable(unsigned char DispId);
DISP_CheckType DISP_Disable(unsigned char DispId);
#endif // DSIP_H_INCLUDED
