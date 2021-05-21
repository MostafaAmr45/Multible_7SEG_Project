/*********************************************************************************/
/* Author    : Mostafa Amr                                                       */
/* Version   : V02                                                               */
/* Date      : 21 May 2021                                                       */
/*********************************************************************************/


#ifndef MACROS_H_
#define MACROS_H_
#define SET_BIT(Reg,Bit) (Reg|=(1<<Bit))
#define CLR_BIT(Reg,Bit) (Reg&=(~(1<<Bit)))
#define TOGGLE_BIT(Reg,Bit) (Reg^=(1<<Bit))
#define GET_BIT(Reg,Bit) ((Reg>>Bit)&(0x01))
#define SHIFT(DATA , SHIFTVAL) (DATA = (DATA << SHIFTVAL))



#endif /* MACROS_H_ */
