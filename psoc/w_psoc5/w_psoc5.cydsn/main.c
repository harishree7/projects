#include <device.h>
#include <lpregs.h>
#include <RadioSpi.h>
#include <Radio.h>

void test_lcd (void);


#define	 CMD_SINGLE_READ	0x00
#define  CMD_SINGLE_WRITE	0x80
#define  CMD_BURST__READ	0x40
#define  CMD_BURST__WRITE	0xC0

void main()
{	
	uint8 Payload;
	
    LCD_Start(); 
	SPIM_Start();
	
	MyRadioHWReset();	//MyRadioWrite(0x1D,0x00); //Reset in SW
	CyDelay(100); 
	LCD_Position(0,0);
	LCD_PrintString("PSoC3+WirelessRX");
	MyRadioInit();
	//Receive length
	MyRadioWrite(TX_LENGTH_ADR,0x01);
	
	
	
	
    for(;;)
    {	
		unsigned char RxState;
		//////////////////////////////////////////
		MyRadioStartReceive();
		//CyDelay(100);//wait
	
		RxState = MyRadioGetReceiveState();

        if (RxState & RXC_IRQ) // Receive operation completed
        {
            if (MyRadioEndReceive(RxState)) // Retrieve packet from radio
            {
				Payload = MyRadioRead(RX_BUFFER_ADR);
				//MyRadioWrite(RX_CTRL_ADR,RX_CLR);//TX_CTRL_ADR,clear TX_BUFFER
				
				LCD_Position(1,10);
				LCD_PrintString("     ");
				LCD_Position(1,0);LCD_PrintInt8(Payload);
			}
			
			else
			{
//				LCD_Position(1,10);
//				LCD_PrintString("Error");
			}
			}
	
    
	}


}

