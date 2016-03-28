/*******************************************************************************
* 	Function prototypes for controlling and monitoring the operating
*	channel of the radio.
*******************************************************************************/



/*******************************************************************************
* Function Name: RadioSetChannel
********************************************************************************
* Summary:
*  Set the channel (frequency + 2MHz)
*
* Parameters:  
*  Channel:  Desired operating channel 
*
* Return: 
*  void 
*  
*******************************************************************************/
void RadioSetChannel(uint8 Channel);


/*******************************************************************************
* Function Name: RadioGetChannel
********************************************************************************
* Summary:
*  Get the channel
*
* Parameters:  
*  void
*
* Return: 
*  Operating Channel
*  
*******************************************************************************/
uint8 RadioGetChannel(void);
