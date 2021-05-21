/*********************************************************************************/
/* Author    : Mostafa Amr                                                       */
/* Version   : V01                                                               */
/* Date      : 21 May 2021                                                       */
/*********************************************************************************/
#ifndef DIO_H_INCLUDED
#define DIO_H_INCLUDED

#define DIO_OK  ((unsigned char)0)
#define DIO_NOK ((unsigned char)1)

typedef unsigned char DIO_CheckType;
DIO_CheckType DIO_Init(void);
DIO_CheckType DIO_ChannelWrite(unsigned char ChannelId, unsigned char Data);
DIO_CheckType DIO_ChannelRead(unsigned char ChannelId, unsigned char *DataPtr);

#endif // DIO_H_INCLUDED
