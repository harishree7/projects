
#include <device.h>
#include "RadioRegs.h"
#include "RadioChannel.h"

void RadioWrite(uint8 Address, uint8 Data)
{
	//while(!Button_Read());
	
	SS_Write(0);		// Tell the Radio to listen for a command from the SPI Master device
	
//	LED_Control_Reg_Write(WRITE_ONE_BYTE | Address); // For troubleshooting
	
	while (!( RadioController_ReadStatus() & RadioController_STS_TX_FIFO_EMPTY )); // Wait for SPIM to become ready for Tx
	RadioController_WriteTxData(WRITE_ONE_BYTE | Address); 			 // The MSB must be set for a write command
															 // The 6 LSBs are the only bits used for the address
    while (!( RadioController_ReadStatus() & RadioController_STS_BYTE_COMPLETE ));
	RadioController_ReadRxData();			// Must read SPIM Rx buffer before continuing 
								// These are junk bits, but a read is still necessary to clear certain flags
	
	//LED_Control_Reg_Write(CyRadio_ReadRxData());
	CyDelay(1);
	
	//while(!Button_Read());
	
//	LED_Control_Reg_Write(Data);
	
	while (!( RadioController_ReadStatus() & RadioController_STS_TX_FIFO_EMPTY ));
	RadioController_WriteTxData(Data);		// Data byte must be written immediately after the address byte
    while (!( RadioController_ReadStatus() & RadioController_STS_BYTE_COMPLETE ));
	RadioController_ReadRxData();			// A junk read must be performed again before continuing
	
	SS_Write(1);		// Tell the radio that the master is done communicating for now
	
	//LED_Control_Reg_Write(CyRadio_ReadRxData());
	CyDelay(1);
}

uint8 RadioRead(uint8 Address)
{
	uint8 readBuffer = 0x00;
	
	//while(!Button_Read());
	//delay(4);
	
	SS_Write(0); 			// Tell the Radio to listen for a command from the SPI Master device
	
	while (!( RadioController_ReadStatus() & RadioController_STS_TX_FIFO_EMPTY ));
	RadioController_WriteTxData(READ_ONE_BYTE | Address); 	// The MSB must be cleared for a read command
    while (!( RadioController_ReadStatus() & RadioController_STS_BYTE_COMPLETE ));
	if( RadioController_GetRxBufferSize() > 0 )
	{
		RadioController_ReadRxData(); 			// Must read SPIM Rx buffer before continuing 
									// These are junk bits, but a read is still necessary to clear certain flags
	}
	
	//LED_Control_Reg_Write(CyRadio_ReadRxData());
	CyDelay(1);
	
	//while(!Button_Read());
	//delay(4);
	
	while (!( RadioController_ReadStatus() & RadioController_STS_TX_FIFO_EMPTY ));
	RadioController_WriteTxData(0x00);			// Must send something to the slave to initiate transfer
									// This is a junk byte and can be discarded
    while (!( RadioController_ReadStatus() & RadioController_STS_BYTE_COMPLETE ));
	if( RadioController_GetRxBufferSize() > 0 )
	{
		readBuffer = RadioController_ReadRxData();		// This is the data that is stored at the stated address.
	}
	SS_Write(1);
	
	//LED_Control_Reg_Write(CyRadio_ReadRxData());
	CyDelay(1);
	
	return readBuffer;
}