
#include <device.h>
#include <lpregs.h>
#include <Radio.h>
#include <RadioSpi.h>


#define		SS_Lo	SS_Write(0)
#define		SS_Hi	SS_Write(1)
#define	   RST_Lo	RST_Write(0)
#define	   RST_Hi	RST_Write(1)

//uint8		gu8DataMode = DATMODE_64SDR;

void MyRadioHWReset(void)
{
    // Hard Reset the Radio - Delay for 3.7us (waiting for characterization)
		RST_Hi;
		CyDelay(100); //using 1ms delay :P
		RST_Lo;
}

void MyRadioSetChannel(uint8 Channel)
{
	Channel +=  2;				
	
	if (Channel > 0)
		--Channel;				//compensate the TX OFFSET 

	// Set the channel.
	MyRadioWrite(CHANNEL_ADR, Channel );
}

uint8 MyRadioGetChannel(void)
{
	return (MyRadioRead(CHANNEL_ADR) -1);
}

void MyRadioInit()
{
// Reset the LP through the SPI (soft reset).
    MyRadioWrite(MODE_OVERRIDE_ADR, RST);

    // Set up to use auto-cal for VCO.
    MyRadioWrite(AUTO_CAL_TIME_ADR, AUTO_CAL_TIME_MAX); // Extend autoCal time to max.

    MyRadioWrite(AUTO_CAL_OFFSET_ADR, AUTO_CAL_OFFSET_MINUS_4); // AutoCal offset to -4.

    // Set IRQ polarity to positive.
    //MyRadioWrite(IO_CFG_ADR,IRQ_OD );
	MyRadioWrite(IO_CFG_ADR, IRQ_POL);
	 
	CyDelay(1);
    // Set the XTAL Startup delay to 150uSec to handle warm restarts of the XTAL. 
	 MyRadioWrite(XTAL_CFG_ADR, 0x08);

    // Enable HiLo for quick-turn-around. Use low side injection for receive -
    // this should result in non-inverted data, so no need to hit the invert
    // bit. Turn off AGC and force the LNA on.
    MyRadioWrite(RX_CFG_ADR,
                 ((RX_CFG_RST | FASTTURN_EN | LNA_EN ) & ~( HI | RXOW_EN | AUTO_AGC_EN)));

    // Set the TX Offset to +1MHz.
    // THIS MEANS THE ACTUAL TRANSMIT CARRIER WILL BE 1MHz ABOVE THE PLL
    // FREQUENCY PROGRAMMED IN THE CHANNEL OR A & N REGISTERS.
    // RadioSetFrequency COMPENSATES FOR THIS OFFSET.
    MyRadioWrite(TX_OFFSET_LSB_ADR, 0x55);
    MyRadioWrite(TX_OFFSET_MSB_ADR, 0x05);

    // Set Data Mode to 250kbps
    MyRadioWrite(TX_CFG_ADR, TX_CFG_RST |  DATMODE_8DR );







}

unsigned char MyRadioEndReceive(unsigned char RadioState)
{
    unsigned char Count;

    Count = MyRadioRead(RX_COUNT_ADR);

    if (RadioState & RXE_IRQ) // If we had a buffer error...
    {
        unsigned char index;

        // burp the buffer
        for (index = 15; index; --index)
        {
            MyRadioRead(RX_BUFFER_ADR);
        }

        Count = 0; // Packet was bad.
    }

			//	Data = MyRadioRead(RX_BUFFER_ADR); // Read the single byte that was transmitted

    // Abort by writing the FRC_END_STATE bit in the XACT_CFG register.
    MyRadioWrite(XACT_CFG_ADR, MyRadioRead(XACT_CFG_ADR) | FRC_END_STATE);

    // Wait for the FRC_END_STATE bit in the XACT_CFG register to clear
    // indicating the force has completed.
    while(MyRadioRead( XACT_CFG_ADR) &  FRC_END_STATE) {};

    return Count;
}

unsigned char MyRadioGetReceiveState()
{
    unsigned char Status = 0;

//    //if (LP_IRQ_DR & LP_IRQ_MASK)
//    if (LP_IRQ_Read() & LP_IRQ_MASK)
//	
//	{
//        
		// This register needs to be debounced.
       Status  = MyRadioRead(RX_IRQ_STATUS_ADR);
//       	Status  = MyRadioRead(0x07);
		//Status |= MyRadioRead(0x07);
	Status |= MyRadioRead(RX_IRQ_STATUS_ADR);

        if (Status & (RXBERR_IRQ | RXE_IRQ))
        {
             // If overflow, set the completion bit to force the end of packet.
            Status |= (RXC_IRQ | RXE_IRQ);	
		}
//    }
return Status;
}

void WritePayloadToRadio(uint8 Payload)
{
	MyRadioWrite(TX_BUFFER_ADR,Payload);
}


void MyRadioStartReceive(void)
{
	if( !(MyRadioRead(RX_CTRL_ADR) & RX_GO) )	
	    MyRadioWrite(RX_CTRL_ADR, (RX_GO | RXC_IRQ | RXE_IRQ));

    // Clear RSSI
    MyRadioRead(RSSI_ADR);
}