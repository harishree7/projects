
#include <device.h>
#include "RadioRegs.h"
#include "RadioControl.h"
#include "UserParameters.h"

uint8 temp = 0x00;

void RadioInit()
{
	// Reset through the SPI (soft reset).
    RadioWrite( MODE_OVERRIDE_ADR, RST );
	
	// Force the RXF clock on in the streaming driver.
	// Not necessary for nonstreaming driver but harmless.
	RadioWrite( CLK_EN_ADR, RXF );

    // Set up to use auto-cal for VCO. Register 0x34 is left at its default value
	// to allow auto-cal to be used.
    RadioWrite( AUTO_CAL_TIME_ADR, AUTO_CAL_TIME_MAX ); // Extend autoCal time to max.
    RadioWrite( AUTO_CAL_OFFSET_ADR, AUTO_CAL_OFFSET_MINUS_4 ); // AutoCal offset to -4.

    // User may have changed IO_CFG_ADR in RadioReset
 	// Set IRQ polarity to positive. (Some have asked that this be
  	// left at the default negative.)
	RadioWrite( IO_CFG_ADR, (RadioRead(IO_CFG_ADR) | IRQ_POL) );
	 
	CyDelay(1);
    
	// Set the XTAL Startup delay to 150uSec to handle warm restarts of the XTAL. 
    RadioWrite( XTAL_CFG_ADR, 0x08 );

	// Configure XACT_CFG_ADR register using user parameters
	// Wait for Force End State bit to clear
	if (ENABLE_ACK) {
		RadioWrite( XACT_CFG_ADR, (ACK_EN | FRC_END_STATE | END_STATE | ACK_TIMEOUT) );
	} else {
		RadioWrite( XACT_CFG_ADR, (END_STATE & FRC_END_STATE) );
	}
	while(RadioRead( XACT_CFG_ADR ) & FRC_END_STATE);
	
	// Configure FRAMING_CFG_ADR and EOP_CTRL_ADR registers using user parameters
	// Typical values of SOP_TSH are 0x04 for SOP32 and 0x0E for SOP64
	// Default value for FRAMING_CFG_ADR is 0xA5
	if ( !(DATA_MODE & 0x18) ) { 
		// Handle GFSK mode initialization
		RadioWrite( ANALOG_CTRL_ADR, ALL_SLOW ); // Set ALL_SLOW bit
		// must set LEN_EN bit in FRAMING_CFG_ADR register
	} else if (DATA_MODE & 0x10) {
		RadioWrite( ANALOG_CTRL_ADR, ANALOG_CTRL_RST );
		if (DATA_MODE & 0x08) {
			// Handle SDR mode initialization
			RadioWrite( FRAMING_CFG_ADR, 0x20 );
			RadioWrite( EOP_CTRL_ADR, EOP_CTRL_RST );
		} else {
			// Handle DDR mode initialization
			if (!(SOP_LENGTH & DATCODE_LEN_64)) {
				RadioWrite( FRAMING_CFG_ADR, ((SOP_EN | LEN_EN | (DAT32_THRESH_MSK & SOP_TSH)) & ~SOP_LEN) );
			} else {
				RadioWrite( FRAMING_CFG_ADR, (SOP_EN | SOP_LEN | LEN_EN | (DAT64_THRESH_MSK & DEF_64_THOLD)) );
			}
		}
	} else {
		// Handle 8DR mode initialization
		RadioWrite( ANALOG_CTRL_ADR, ANALOG_CTRL_RST );
		if (!(SOP_LENGTH & DATCODE_LEN_64)) {
			RadioWrite( FRAMING_CFG_ADR, ((SOP_EN | LEN_EN | (DAT32_THRESH_MSK & SOP_TSH)) & ~SOP_LEN) );
		} else {
			RadioWrite( FRAMING_CFG_ADR, (SOP_EN | SOP_LEN | LEN_EN | (DAT64_THRESH_MSK & DEF_64_THOLD)) );
		}
	}
	// Configure the TX_CFG_ADR register using user parameters
	RadioWrite( TX_CFG_ADR, (SOP_LENGTH | DATA_MODE | PA_VAL) );	
	
	// Disable the CRC16 field
	//RadioWrite( TX_OVERRIDE_ADR, 0x0C );

    // Enable HiLo for quick-turn-around. Use low side injection for receive -
    // this should result in non-inverted data, so no need to hit the invert
    // bit. Turn off AGC and force the LNA on.	
    RadioWrite( RX_CFG_ADR, ((RX_CFG_RST | FASTTURN_EN | LNA_EN ) & ~( HI | RXOW_EN | AUTO_AGC_EN)) );

    // Set the TX Offset to +1MHz.
    // THIS MEANS THE ACTUAL TRANSMIT CARRIER WILL BE 1MHz ABOVE THE PLL
    // FREQUENCY PROGRAMMED IN THE CHANNEL OR A & N REGISTERS.
    // RadioSetFrequency COMPENSATES FOR THIS OFFSET.
    RadioWrite( TX_OFFSET_LSB_ADR, 0x55 );
    RadioWrite( TX_OFFSET_MSB_ADR, 0x05 );

	// Set Data Threshold 64
	RadioWrite( DATA64_THOLD_ADR, DEF_64_THOLD );
	
	// Set Data Threshold 32
	RadioWrite( DATA32_THOLD_ADR, DEF_32_THOLD );
	
	// Set Preamble Count (Default for this register is fine)
	// PREAMBLE_ADR is a 3 byte file:
	// 1st byte is # of repetitions
	// 2nd byte is least significant 8 chips of sequence
	// 3rd byte is most significant 8 chips of sequence
	// Default value is 0x333302 which means the preamble sequence in binary is
	// 0011_0011_0011_0011, repeated twice.
	// If a different preamble sequence is desired, first write the
	// number of repetitions, and then write a combination of alternating
	// 1's and 0's to the 2nd and 3rd bytes. Or to leave the existing 0x3333 as
	// the sequence, perform 2 junk reads of the register after writing the desired
	// number of repetitions.
	// RadioWrite(PREAMBLE_ADR, DEF_PREAMBLE_CNT);
	// RadioWrite(PREAMBLE_ADR, DEF_PR_SEQ_LSB); // Or use RadioRead(PREAMBLE_ADR);
	// RadioWrite(PREAMBLE_ADR, DEF_PR_SEQ_MSB); // Or use RadioRead(PREAMBLE_ADR);
	CyDelay(100);
	
	// Assign 16-bit starting value for the CRC16 calculation
	RadioWrite( CRC_SEED_MSB_ADR, CRC_POLY_MSB );
	RadioWrite( CRC_SEED_LSB_ADR, CRC_POLY_LSB );
	
	// Disable the DIS_CRC0 bit in RX_OVERRIDE_ADR
	RadioWrite( RX_OVERRIDE_ADR, ( RX_OVERRIDE_RST | DIS_CRC0) );
}