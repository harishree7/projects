
#include <device.h>
#include "RadioRegs.h"
#include "RadioControl.h"


void RadioSetChannel(uint8 Channel)
{
	Channel +=  2;				
	
	// Need to compensate for TX OFFSET 
	if (Channel > 0) {
		--Channel;	
	} 
	
	RadioWrite(CHANNEL_ADR, Channel );
}

uint8 RadioGetChannel(void)
{
	return (RadioRead(CHANNEL_ADR) - 1);
}