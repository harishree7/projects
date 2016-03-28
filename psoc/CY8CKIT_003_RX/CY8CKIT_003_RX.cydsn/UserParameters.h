////////////////////////////////////////////////////////////////////
// The purpose of this file is for the user to enter in desired
// parameters for the radio, much like you would in the User Module
// Parameters window in PSoC Designer.
////////////////////////////////////////////////////////////////////

#include "RadioRegs.h"

// Define Data Mode
// This will determine the wireless data rate
// See AWM24xxL Register Details document for details
// The Data Mode field exists in the middle of the TX_CFG_ADR register.
// If Integer Value is used, must bit-shift 3 places to place value in
// the correct bit-field of TX_CFG_ADR.
// Pre-Defined Value		Description
// DATMODE_1MBPS 			1-Mbps GFSK
// DATMODE_8DR   			8DR Mode
// DATMODE_DDR 				DDR Mode
// DATMODE_SDR   			SDR Mode
#define DATA_MODE			DATMODE_8DR

// Assign the power amplifier strength for the radio signal
// Pre-Defined Value		Description
// PA_N30_DBM 				-30 dBm
// PA_N25_DBM				-25 dBm
// PA_N20_DBM				-20 dBm
// PA_N15_DBM				-15 dBm
// PA_N10_DBM				-10 dBm
// PA_N5_DBM 			 	 -5 dBm	
// PA_0_DBM  				  0 dBm	
// PA_4_DBM  				 +4 dBm
#define PA_VAL				PA_4_DBM

// Define SOP Length
// This determines the chip code length and is used to detect 
// Start of Packet bits. This value is ignored when in GFSK mode.
// Pre-defined Value		Description
// DATCODE_LEN_64			64 Chip Codes
// DATCODE_LEN_32			32 Chip Codes
#define SOP_LENGTH 			DATCODE_LEN_32

// Set the Preamble Count
// This determines how many times the preamble sequence is repeated
// Default value is 2
#define DEF_PREAMBLE_CNT	2

// Define the END_STATE for the radio. This is the state the
// device will return to once a transaction is complete.
// Pre-defined Value		Description
// END_STATE_SLEEP   		Sleep mode
// END_STATE_IDLE    		Idle mode	
// END_STATE_TXSYNTH 		TX_synth mode	
// END_STATE_RXSYNTH 		RX_synth mode
// END_STATE_RX      		RX mode
#define END_STATE			END_STATE_IDLE

// Enable/Disable ACK during transactions
// Integer Value			Description
// 0  						Disable	
// 1  						Enable	
#define ENABLE_ACK			1

// Define the ACK Timeout period
// Timeout period is calculated by:
// 	 if SOP_LEN bit is set in FRAMING_CFG_ADR register, then the
// 	 value set here is multiplied by 64us. If SOP_LEN is cleared,
// 	 then the value set here is multiplied by 32us. 
// Pre-defined Value		Description
// ACK_TO_4X 				4x
// ACK_TO_8X 			  	8x
// ACK_TO_12X			 	12x
// ACK_TO_15X			 	15x
#define ACK_TIMEOUT		ACK_TO_8X

// Enable/Disable MUX IRQ on MOSI line
// When SS line is high (deactivate slave), MOSI pin on MCU operates as an IRQ input.
// When SS line is low (activate slave), MOSI pin on MCU operates as strong drive output.

// ...This functionality has not been implemented yet...

// Integer Value			Description
// 0						Disable
// 1						Enable
//#define EN_MUX_IRQ_ON_MOSI	0














