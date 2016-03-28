//--------------------------------------------------------------------------
//
//  Filename:    radio.c
//
//  Description: radio driver routines
//
//--------------------------------------------------------------------------
#include <device.h>
#include <lpregs.h>
#include <radio.h>

#define	 CMD_SINGLE_READ	0x00
#define  CMD_SINGLE_WRITE	0x80
#define  CMD_BURST__READ	0x40
#define  CMD_BURST__WRITE	0xC0

#define		SS_Lo	SS_Write(0)
#define		SS_Hi	SS_Write(1)
#define	   RST_Lo	RST_Write(0)
#define	   RST_Hi	RST_Write(1)

//
static 		RxData;

void SPIsend(uint8 bDataSend)
{
	while (!( SPIM_ReadStatus() & SPIM_STS_TX_FIFO_EMPTY ));
	SPIM_WriteByte(bDataSend);
    while (!( SPIM_ReadStatus() & SPIM_STS_BYTE_COMPLETE ));
	RxData = SPIM_ReadByte();
}

uint8 MyRadioRead(uint8 Address)
{	
	uint8  bMasterRxData;
	SS_Lo;
	SPIsend(CMD_SINGLE_READ|Address);
	SPIsend(0x00);
	CyDelay(1);
	bMasterRxData = RxData;
	SS_Hi;
	
	SPIM_ClearFIFO();
	return bMasterRxData;
}

void Burst_READ(uint8 Address,uint8 *pData,uint8 Length)
{
	uint8 loop;
	SS_Lo;
	SPIM_WriteByte(CMD_BURST__READ|Address);
    while (!( SPIM_ReadStatus() & SPIM_STS_BYTE_COMPLETE ));
	for (loop = 0; loop < Length; ++loop)
		{
			SPIM_WriteByte(0xFF);
			while (!( SPIM_ReadStatus() & SPIM_STS_BYTE_COMPLETE ));
			*pData++ = SPIM_ReadByte() ;
		}
	SS_Hi;
}

void MyRadioWrite(uint8 Address, uint8 Data)
{
		SS_Lo;
    	SPIsend(CMD_SINGLE_WRITE|Address);
		SPIsend(Data); 
		SS_Hi;
		SPIM_ClearFIFO();
}

void Burst_WRITE(uint8 Address,uint8 *pData,uint8 Length)
{	
	uint8 loop;
	SS_Lo;
	pData += (Length-1);
	SPIM_WriteByte (CMD_BURST__WRITE|Address);
    while (!( SPIM_ReadStatus() & SPIM_STS_BYTE_COMPLETE ));
	for (loop = 0; loop < Length; ++loop)
		{
			SPIM_WriteByte(*pData--);
			while (!( SPIM_ReadStatus() & SPIM_STS_BYTE_COMPLETE ));
		}
	SS_Hi;
}
