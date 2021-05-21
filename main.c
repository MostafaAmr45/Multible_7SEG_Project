/*********************************************************************************/
/* Author    : Mostafa Amr                                                       */
/* Version   : V01                                                               */
/* Date      : 21 May 2021                                                       */
/*********************************************************************************/
#include "DISP.h"
#include "DIO.h"
#define F_CPU 16000000ul
#define MAX_COUNT ((unsigned char)100)
#define DECIMAL_BASE ((unsigned char)10)
#define DELAY_COUNT ((unsigned char)100)
#include <util/delay.h>
int main(void)
{
    unsigned char num;
    unsigned char Temp;
    unsigned char loop;

    DIO_Init();

    while (1)
    {
        for (num = 0; num < MAX_COUNT; num++)
        {
            for (loop = (unsigned char)0; loop < DELAY_COUNT; loop++)
            {
                Temp = num % DECIMAL_BASE;
                DISP_Disable(1);
                DISP_WriteData(0, Temp);
                DISP_Enable(0);
                _delay_ms(10);
                Temp = num / DECIMAL_BASE;
                DISP_Disable(0);
                DISP_WriteData(1, Temp);
                DISP_Enable(1);
                _delay_ms(10);
            }
        }
    }
    return 0;
}
