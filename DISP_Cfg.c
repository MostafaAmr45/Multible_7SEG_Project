/*********************************************************************************/
/* Author    : Mostafa Amr                                                       */
/* Version   : V01                                                               */
/* Date      : 21 May 2021                                                       */
/*********************************************************************************/
#include "DISP_Cfg.h"
const DISP_ConfigParamType DISP_ConfigParam[DISP_NUM_OF_DISPLAYS] =
{
    {/*Display 1 Configuration*/
        0, /*Display 1 Enable DIO group*/
        {
            1,2,3,4,5,6,7 /*Display 1 data DIO groups*/
        }

    },
    {/*Display 2 Configuration*/
        8, /*Display 2 Enable DIO group*/
        {
            1,2,3,4,5,6,7 /*Display 2 data DIO groups*/
        }

    }
};
