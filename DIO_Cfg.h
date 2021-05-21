/*********************************************************************************/
/* Author    : Mostafa Amr                                                       */
/* Version   : V01                                                               */
/* Date      : 21 May 2021                                                       */
/*********************************************************************************/
#ifndef DIO_CFG_H_INCLUDED
#define DIO_CFG_H_INCLUDED
#define DIO_NUM_OF_CHANNELS ((unsigned char)9)
typedef struct
{
    unsigned char PortId;
    unsigned char PortMask;
    unsigned char PortDirection;
    unsigned char IsPullupResistorUsed;
}DIO_ConfigParamType;
extern const DIO_ConfigParamType DIO_ConfigParam[DIO_NUM_OF_CHANNELS];


#endif // DIO_CFG_H_INCLUDED
