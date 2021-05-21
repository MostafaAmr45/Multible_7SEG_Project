/*********************************************************************************/
/* Author    : Mostafa Amr                                                       */
/* Version   : V01                                                               */
/* Date      : 21 May 2021                                                       */
/*********************************************************************************/
#include "DIO_Cfg.h"
const DIO_ConfigParamType DIO_ConfigParam[DIO_NUM_OF_CHANNELS] =
{
    {/*Display 1 Enable*/
     0,
     0x01,
     0xff,
     0x00
    },
    {/*Display Data pin A*/
     0,
     0x02,
     0xff,
     0x00
    },
    {/*Display Data pin B*/
     0,
     0x04,
     0xff,
     0x00
    },
    {/*Display Data pin C*/
     0,
     0x08,
     0xff,
     0x00
    },
    {/*Display Data pin D*/
     0,
     0x10,
     0xff,
     0x00
    },
    {/*Display Data pin E*/
     0,
     0x20,
     0xff,
     0x00
    },
    {/*Display Data pin F*/
     0,
     0x40,
     0xff,
     0x00
    },
    {/*Display Data pin G*/
     0,
     0x80,
     0xff,
     0x00
    },
    {/*Display 2 Enable*/
     1,
     0x01,
     0xff,
     0x00
    },
};
