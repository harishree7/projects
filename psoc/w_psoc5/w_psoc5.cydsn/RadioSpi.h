//--------------------------------------------------------------------------
//
//  Filename:     radio.h
//
//  Description:  header file of radio driver
//				  
//				  
//--------------------------------------------------------------------------
#ifndef _RADIO_H_
#define _RADIO_H_

//-------inlcude files-------------------------
#include <device.h>
#include <lpregs.h>


//-------- functions prototype ----------------

void 		SPIsend(uint8 bDataSend);
uint8 		MyRadioRead(uint8 Address);
void 		MyRadioWrite(uint8 Address, uint8 Data);
void 		Burst_WRITE(uint8 Address,uint8 *pData,uint8 Length);
void 		Burst_READ(uint8 Address,uint8 *pData,uint8 Length);

#endif
