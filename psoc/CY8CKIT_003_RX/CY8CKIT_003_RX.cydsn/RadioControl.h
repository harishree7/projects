/*******************************************************************************
* 	Function prototypes for sending Read/Write commands to the radio using 
*	SPI protocol.
*******************************************************************************/


/*******************************************************************************
* Function Name: RadioRead
********************************************************************************
* Summary:
*  Read the 8-bit value stored in the specified radio register
*
* Parameters:  
*  Address:		Address of the register to be read
*
* Return: 
*  8-bit value stored in the register
*  
*******************************************************************************/
uint8 RadioRead(uint8 Address);

/*******************************************************************************
* Function Name: RadioWrite
********************************************************************************
* Summary:
*  Write a single byte to the specified radio register
*
* Parameters:  
*  Address:		Address of the register to be written to
*  Data:		8-bit data value to be written to the register
*
* Return: 
*  void
*  
*******************************************************************************/
void RadioWrite(uint8 Address, uint8 Data);