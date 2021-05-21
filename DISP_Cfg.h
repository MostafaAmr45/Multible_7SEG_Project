/*********************************************************************************/
/* Author    : Mostafa Amr                                                       */
/* Version   : V01                                                               */
/* Date      : 21 May 2021                                                       */
/*********************************************************************************/
#ifndef DISP_CFG_H_INCLUDED
#define DISP_CFG_H_INCLUDED

#define DISP_NUM_OF_DISPLAYS ((unsigned char)2)
#define DISP_NUM_OF_DATA_PINS ((unsigned char)7)
typedef struct
{
    unsigned char EnablePinChannel;
    unsigned char DataPinsChannel[DISP_NUM_OF_DATA_PINS];
}DISP_ConfigParamType;
extern const DISP_ConfigParamType DISP_ConfigParam[DISP_NUM_OF_DISPLAYS];
#endif // DISP_CFG_H_INCLUDED
