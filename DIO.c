/*********************************************************************************/
/* Author    : Mostafa Amr                                                       */
/* Version   : V01                                                               */
/* Date      : 21 May 2021                                                       */
/*********************************************************************************/
#include "DIO.h"
#include "DIO_Cfg.h"
#include "MACROS.h"
/*start address of each port*/
#define PORTA_BASE_ADDRESS ((unsigned char)0x3B)
#define PORTB_BASE_ADDRESS ((unsigned char)0x38)
#define PORTC_BASE_ADDRESS ((unsigned char)0x35)
#define PORTD_BASE_ADDRESS ((unsigned char)0x32)

/*Port subsystem registers offset*/
#define PORT_REG_OFFSET ((unsigned char)0)
#define DDR_REG_OFFSET ((unsigned char)1)
#define PIN_REG_OFFSET ((unsigned char)2)

#define NUM_OF_PORTS ((unsigned char)4)

/*Registers definitions*/
#define PORT_REG(PORT_ID) (*((volatile  unsigned char*const)(PortBaseAddresses[PORT_ID] - PORT_REG_OFFSET)))
#define DDR_REG(PORT_ID) (*((volatile  unsigned char*const)(PortBaseAddresses[PORT_ID] - DDR_REG_OFFSET)))
#define PIN_REG(PORT_ID) (*((volatile  unsigned char*const)(PortBaseAddresses[PORT_ID] - PIN_REG_OFFSET)))

/*base address lookup table*/
const unsigned char PortBaseAddresses[NUM_OF_PORTS] =
{PORTA_BASE_ADDRESS,
 PORTB_BASE_ADDRESS,
 PORTC_BASE_ADDRESS,
 PORTD_BASE_ADDRESS};

DIO_CheckType DIO_Init(void)
 {
     unsigned char Loop;
     DIO_CheckType Result;
     for(Loop = (unsigned char)0; Loop < DIO_NUM_OF_CHANNELS; Loop++)
     {
         unsigned char PortId;
         /*read the port Id from link time configuration*/
         PortId = DIO_ConfigParam[Loop].PortId;
         /*verify Port Id*/
         if(PortId < NUM_OF_PORTS)
         {
             /*init port direction for the masked pins*/
             DDR_REG(PortId) &= ~(DIO_ConfigParam[Loop].PortMask);
             DDR_REG(PortId) |=  DIO_ConfigParam[Loop].PortMask & DIO_ConfigParam[Loop].PortDirection;
             /*init pull up resistor in case of input direction only*/
             PORT_REG(PortId) &= (~(DIO_ConfigParam[Loop].PortMask)) | (DIO_ConfigParam[Loop].PortDirection);
             PORT_REG(PortId) |= DIO_ConfigParam[Loop].PortMask & ((~DIO_ConfigParam[Loop].PortDirection) & DIO_ConfigParam[Loop].IsPullupResistorUsed);
             Result = DIO_OK;

         }
         else
         {
             /*invalid port*/
             Result = DIO_NOK;
             break;
         }
     }
     return Result;
 }

/*Function shall do the following:
1- To Validate Channel ID
2- To get the port ID from configuration based on the Channel ID
3- To write port for the masked pins with the passed data value
4- Data shall be written only for the output pins*/
DIO_CheckType DIO_ChannelWrite(unsigned char ChannelId, unsigned char Data)
{
	DIO_CheckType Result;	
	unsigned char PortId;
	unsigned char PortMask;
	unsigned char ShiftedData;
	
	/*verify channel Id*/
	if(ChannelId < DIO_NUM_OF_CHANNELS)
	{
		/*read the port Id for the given channel Id*/
		PortId= DIO_ConfigParam[ChannelId].PortId;
		/*verify Port Id*/
		if (PortId < NUM_OF_PORTS)
		{
			/*read the port mask for the given channel Id*/
			PortMask= DIO_ConfigParam[ChannelId].PortMask;
			/*Make sure that channel Id is between 0 and 7*/
			ChannelId = ChannelId % 8;
			/*Shift data value to the target pin*/
			ShiftedData = SHIFT(Data, ChannelId);
			/*mask the port to write the data value only on the target pin*/
			PORT_REG(PortId) &= ~(PortMask);
			/*write the data value on the target pin*/
			PORT_REG(PortId) |= ShiftedData & PortMask;
			Result= DIO_OK;
		}
		else
		{
            /*invalid port*/
            Result = DIO_NOK;			
		}

	 
	}
	else
	{
		/*invalid channel Id*/
		Result = DIO_NOK;
	}
	return Result; 
}

/*Function shall do the following:
1- To Validate Channel ID
2- To get the port ID from configuration based on the Channel ID
3- To read port for the masked pins and other pins shall be returned by 0
4- Data shall be read only for the input pins*/

DIO_CheckType DIO_ChannelRead(unsigned char ChannelId, unsigned char *DataPtr)
{
	DIO_CheckType Result;
	unsigned char PortId;
	unsigned char PortMask;
	
	/*verify channel Id*/
	if(ChannelId < DIO_NUM_OF_CHANNELS)
	{
		/*read the port Id for the given channel Id*/
		PortId= DIO_ConfigParam[ChannelId].PortId;
		/*verify Port Id*/
		if (PortId < NUM_OF_PORTS)
		{
			/*read the port mask for the given channel Id*/
			PortMask= DIO_ConfigParam[ChannelId].PortMask;
			/*mask the port to read the data value only for the target pin*/
			*DataPtr = (PIN_REG(PortId) & PortMask);
			Result= DIO_OK;
		}
		else
		{
			/*invalid port*/
			Result = DIO_NOK;
		}

		
	}
	else
	{
		/*invalid channel Id*/
		Result = DIO_NOK;
	}
	return Result;
}
