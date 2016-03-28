/*******************************************************************************
* 	This file contains the main function which initializes the radio and 
*	implements the receive functionality of the device.
*******************************************************************************/

#include <device.h>
#include "RadioRegs.h"
#include "RadioControl.h"
#include "RadioChannel.h"
#include "RadioInit.h"

void StartUp (void);
void Receive (void);

uint8 Payload;
uint16 RxBytes= 0;
uint8 i;

void main() {
	StartUp();
		
    while(1) {
		Receive();
		if(Button_Read()) {
			// Handle reset
			StartUp();
			CyDelay(250);
		}
	}
}

void StartUp (void) {

	LED_Control_Reg_Write(0xFF);
//  LCD_Start(); 
	RadioController_Start();
	CyDelay(100); 
	
	RadioInit();
	LED_Control_Reg_Write(0x00);
	// Set packet length to 1 byte
	RadioWrite(TX_LENGTH_ADR,0x01);
}

void Receive (void) {
	
	uint8 state = 0;
	
	// RX_GO bit must never be set until it self clears
	// Firmware must never clear this bit
	if( !(RadioRead(RX_CTRL_ADR) & RX_GO) ) {
	    RadioWrite(RX_CTRL_ADR, RX_GO);
	}
    
	// RF signal strength can be measured
	// A "dummy read" of this register is not necessary unless 
	// measuring signal strength prior to packet reception
	// LCD_Position(0,14);
	// LCD_PrintHexUint8( (RadioRead(RSSI_ADR) & 0x1F) );	

	// Debounce the status reg
	// May need to play with the number of times this
	// register is read for proper functionality
	state  = RadioRead(RX_IRQ_STATUS_ADR);
	for ( i=0; i<3; i++ ) { 
		state |= RadioRead(RX_IRQ_STATUS_ADR);
	}
	
	if (state & (RXBERR_IRQ | RXE_IRQ))
    {
        // Handle RX error
		// End transaction
        state |= (RXC_IRQ | RXE_IRQ);	
	}

    if (state & RXC_IRQ) {
	// Transaction complete
	    if (state & RXE_IRQ) {
			// Handle RX error

	        // clear RX buffer contents
	        for (i = 0; i<16; i++) {
	            RadioRead(RX_BUFFER_ADR);
	        }

    		// Abort transaction and wait for FRC_END_STATE bit to clear
    		RadioWrite(XACT_CFG_ADR, RadioRead(XACT_CFG_ADR) | FRC_END_STATE);
			while(RadioRead( XACT_CFG_ADR) &  FRC_END_STATE);
	    }
		
		// Handle successful reception
		Payload = RadioRead(RX_BUFFER_ADR);
		LED_Control_Reg_Write(Payload);
	}
}