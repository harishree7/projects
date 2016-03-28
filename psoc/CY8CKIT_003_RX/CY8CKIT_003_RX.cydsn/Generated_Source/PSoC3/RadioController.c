/*******************************************************************************
* File Name: RadioController.c
* Version 2.21
*
* Description:
*  This file provides all API functionality of the SPI Master component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "CyLib.h"
#include "RadioController.h"

#if(RadioController_InternalClockUsed)
    #include "RadioController_IntClock.h"   
#endif /* RadioController_InternalClockUsed */

#if (RadioController_TXBUFFERSIZE > 4u)

    volatile uint8 RadioController_TXBUFFER[RadioController_TXBUFFERSIZE] = {0u};
    volatile uint8 RadioController_txBufferRead = 0u;
    volatile uint8 RadioController_txBufferWrite = 0u;
    volatile uint8 RadioController_txBufferFull = 0u;
    
#endif /* RadioController_TXBUFFERSIZE > 4u */

#if (RadioController_RXBUFFERSIZE > 4u)

    volatile uint8 RadioController_RXBUFFER[RadioController_RXBUFFERSIZE] = {0u};
    volatile uint8 RadioController_rxBufferRead = 0u;
    volatile uint8 RadioController_rxBufferWrite = 0u;
    volatile uint8 RadioController_rxBufferFull = 0u;
    
#endif /* RadioController_RXBUFFERSIZE > 4u */

uint8 RadioController_initVar = 0u;

extern volatile uint8 RadioController_swStatusTx;
extern volatile uint8 RadioController_swStatusRx;


/*******************************************************************************
* Function Name: RadioController_Init
********************************************************************************
*
* Summary:
*  Inits/Restores default SPIM configuration provided with customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  When this function is called it initializes all of the necessary parameters
*  for execution. i.e. setting the initial interrupt mask, configuring the 
*  interrupt service routine, configuring the bit-counter parameters and 
*  clearing the FIFO and Status Register.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RadioController_Init(void) 
{    
    /* Initialize the Bit counter */
    RadioController_COUNTER_PERIOD_REG = RadioController_BITCTR_INIT;
    
    /* ISR initialization  */  
    #if(RadioController_InternalTxInterruptEnabled)
    
        CyIntDisable(RadioController_TX_ISR_NUMBER);

        /* Set the ISR to point to the RadioController_isr Interrupt. */
        CyIntSetVector(RadioController_TX_ISR_NUMBER, RadioController_TX_ISR);

        /* Set the priority. */
        CyIntSetPriority(RadioController_TX_ISR_NUMBER, RadioController_TX_ISR_PRIORITY);
        
    #endif /* RadioController_InternalTxInterruptEnabled */                                
    
    #if(RadioController_InternalRxInterruptEnabled)
    
        CyIntDisable(RadioController_RX_ISR_NUMBER);

        /* Set the ISR to point to the RadioController_isr Interrupt. */
        CyIntSetVector(RadioController_RX_ISR_NUMBER, RadioController_RX_ISR);

        /* Set the priority. */
        CyIntSetPriority(RadioController_RX_ISR_NUMBER, RadioController_RX_ISR_PRIORITY);
        
    #endif /* RadioController_InternalRxInterruptEnabled */
    
    /* Clear any stray data from the RX and TX FIFO */    
	RadioController_ClearFIFO();
	
	#if(RadioController_RXBUFFERSIZE > 4u)
    
        RadioController_rxBufferRead = 0u;
        RadioController_rxBufferWrite = 0u;

    #endif /* RadioController_RXBUFFERSIZE > 4u */
	
    #if(RadioController_TXBUFFERSIZE > 4u)
    
        RadioController_txBufferRead = 0u;
        RadioController_txBufferWrite = 0u;

    #endif /* RadioController_TXBUFFERSIZE > 4u */
    
    (void) RadioController_ReadTxStatus(); /* Clear any pending status bits */
    (void) RadioController_ReadRxStatus(); /* Clear any pending status bits */
	
	/* Configure the Initial interrupt mask */
    #if (RadioController_TXBUFFERSIZE > 4u)
        RadioController_TX_STATUS_MASK_REG  = RadioController_TX_INIT_INTERRUPTS_MASK & 
                                                ~RadioController_STS_TX_FIFO_NOT_FULL;                    
	#else /* RadioController_TXBUFFERSIZE < 4u */    
        RadioController_TX_STATUS_MASK_REG  = RadioController_TX_INIT_INTERRUPTS_MASK;       
	#endif /* RadioController_TXBUFFERSIZE > 4u */
    
    RadioController_RX_STATUS_MASK_REG  = RadioController_RX_INIT_INTERRUPTS_MASK; 
}
  
    
/*******************************************************************************
* Function Name: RadioController_Enable
********************************************************************************
*
* Summary:
*  Enable SPIM component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RadioController_Enable(void) 
{             
    uint8 enableInterrupts = 0u;    
    
    enableInterrupts = CyEnterCriticalSection();
    
    RadioController_COUNTER_CONTROL_REG |= RadioController_CNTR_ENABLE;
    RadioController_TX_STATUS_ACTL_REG |= RadioController_INT_ENABLE;
    RadioController_RX_STATUS_ACTL_REG |= RadioController_INT_ENABLE;
    
    CyExitCriticalSection(enableInterrupts);
    
    #if(RadioController_InternalClockUsed)    
        RadioController_IntClock_Enable();        
    #endif /* RadioController_InternalClockUsed */
    
    #if(RadioController_InternalTxInterruptEnabled)    
        CyIntEnable(RadioController_TX_ISR_NUMBER);        
    #endif /* RadioController_InternalTxInterruptEnabled */
    
    #if(RadioController_InternalRxInterruptEnabled)    
        CyIntEnable(RadioController_RX_ISR_NUMBER);        
    #endif /* RadioController_InternalRxInterruptEnabled */
}


/*******************************************************************************
* Function Name: RadioController_Start
********************************************************************************
*
* Summary:
*  Initialize and Enable the SPI Master component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  RadioController_initVar - used to check initial configuration, modified on
*  first function call.
*
* Theory:
*  Enable the clock input to enable operation.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RadioController_Start(void) 
{       
    if(RadioController_initVar == 0u)
    {               
        RadioController_Init();
        RadioController_initVar = 1u; 
    }                       
        
    RadioController_Enable();        
}


/*******************************************************************************
* Function Name: RadioController_Stop
********************************************************************************
*
* Summary:
*  Disable the SPI Master component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the clock input to enable operation.
*
*******************************************************************************/
void RadioController_Stop(void) 
{
    uint8 enableInterrupts = 0u;    
    
    enableInterrupts = CyEnterCriticalSection();
    
    RadioController_TX_STATUS_ACTL_REG &= ~RadioController_INT_ENABLE;
    RadioController_RX_STATUS_ACTL_REG &= ~RadioController_INT_ENABLE;
    
    CyExitCriticalSection(enableInterrupts);
    
    #if(RadioController_InternalClockUsed)    
        RadioController_IntClock_Disable();        
    #endif /* RadioController_InternalClockUsed */
    
    #if(RadioController_InternalTxInterruptEnabled)    
        CyIntDisable(RadioController_TX_ISR_NUMBER);        
    #endif /* RadioController_InternalTxInterruptEnabled */
    
    #if(RadioController_InternalRxInterruptEnabled)    
        CyIntDisable(RadioController_RX_ISR_NUMBER);        
    #endif /* RadioController_InternalRxInterruptEnabled */
}


/*******************************************************************************
* Function Name: RadioController_EnableTxInt
********************************************************************************
*
* Summary:
*  Enable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void RadioController_EnableTxInt(void) 
{       
    #if(RadioController_InternalTxInterruptEnabled)    
        CyIntEnable(RadioController_TX_ISR_NUMBER);
    #endif /* RadioController_InternalTxInterruptEnabled */     
}


/*******************************************************************************
* Function Name: RadioController_EnableRxInt
********************************************************************************
*
* Summary:
*  Enable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void RadioController_EnableRxInt(void) 
{       
    #if(RadioController_InternalRxInterruptEnabled)            
        CyIntEnable(RadioController_RX_ISR_NUMBER);
    #endif /* RadioController_InternalRxInterruptEnabled */     
}


/*******************************************************************************
* Function Name: RadioController_DisableTxInt
********************************************************************************
*
* Summary:
*  Disable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void RadioController_DisableTxInt(void) 
{
    #if(RadioController_InternalTxInterruptEnabled)    
        CyIntDisable(RadioController_TX_ISR_NUMBER);        
    #endif /* RadioController_InternalTxInterruptEnabled */
}


/*******************************************************************************
* Function Name: RadioController_DisableRxInt
********************************************************************************
*
* Summary:
*  Disable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void RadioController_DisableRxInt(void) 
{
    #if(RadioController_InternalRxInterruptEnabled)    
        CyIntDisable(RadioController_RX_ISR_NUMBER);        
    #endif /* RadioController_InternalRxInterruptEnabled */
}


/*******************************************************************************
* Function Name: RadioController_SetTxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the 
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void RadioController_SetTxInterruptMode(uint8 intSrc) 
{
    RadioController_TX_STATUS_MASK_REG  = intSrc;    
}


/*******************************************************************************
* Function Name: RadioController_SetRxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the 
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void RadioController_SetRxInterruptMode(uint8 intSrc) 
{
    RadioController_RX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: RadioController_ReadTxStatus
********************************************************************************
*
* Summary:
*  Read the Tx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Tx status register.
*
* Global variables:
*  RadioController_swStatusTx - used to store in software status register, 
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Tx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 RadioController_ReadTxStatus(void) 
{
    uint8 tmpStatus = 0u;
        
    #if (RadioController_TXBUFFERSIZE > 4u)
    
        RadioController_DisableTxInt();
        
        tmpStatus = RadioController_GET_STATUS_TX(RadioController_swStatusTx);                    
        
        RadioController_swStatusTx = 0u;        
        
        /* Enable Interrupts */
        RadioController_EnableTxInt();
        
    #else /* (RadioController_TXBUFFERSIZE < 4u) */
    
        tmpStatus = RadioController_TX_STATUS_REG;
        
    #endif /* (RadioController_TXBUFFERSIZE > 4u) */
    
    return(tmpStatus);
}


/*******************************************************************************
* Function Name: RadioController_ReadRxStatus
********************************************************************************
*
* Summary:
*  Read the Rx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Rx status register.
*
* Global variables:
*  RadioController_swStatusRx - used to store in software Rx status register, 
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Rx status register for error 
*  detection and flow control.
*
* Side Effects:
*  Clear Rx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 RadioController_ReadRxStatus(void) 
{
    uint8 tmpStatus = 0u;
        
    #if (RadioController_RXBUFFERSIZE > 4u)
    
        RadioController_DisableRxInt();
        
        tmpStatus = RadioController_GET_STATUS_RX(RadioController_swStatusRx);
               
        RadioController_swStatusRx = 0u;
        
        /* Enable Interrupts */
        RadioController_EnableRxInt();
        
    #else /* (RadioController_RXBUFFERSIZE < 4u) */
    
        tmpStatus = RadioController_RX_STATUS_REG;
        
    #endif /* (RadioController_RXBUFFERSIZE > 4u) */
    
    return(tmpStatus);
}


/*******************************************************************************
* Function Name: RadioController_WriteTxData
********************************************************************************
*
* Summary:
*  Write a byte of data to be sent across the SPI.
*
* Parameters:
*  txDataByte: The data value to send across the SPI.
*
* Return:
*  None.
*
* Global variables:
*  RadioController_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call if TX Software Buffer is used.
*  RadioController_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*  RadioController_TXBUFFER[RadioController_TXBUFFERSIZE] - used to store
*  data to sending, modified every function call if TX Software Buffer is used.
*
* Theory:
*  Allows the user to transmit any byte of data in a single transfer.
*
* Side Effects:
*  If this function is called again before the previous byte is finished then
*  the next byte will be appended to the transfer with no time between
*  the byte transfers. Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RadioController_WriteTxData(uint8 txData) 
{    
    #if(RadioController_TXBUFFERSIZE > 4u)

        int16 tmpTxBufferRead = 0u;
                
        /* Block if buffer is full, so we don't overwrite. */
        do
        {
            tmpTxBufferRead = RadioController_txBufferRead - 1u;
            if (tmpTxBufferRead < 0u)
            {
                tmpTxBufferRead = RadioController_TXBUFFERSIZE - 1u;        
            }    
        } while(tmpTxBufferRead == RadioController_txBufferWrite);               
                   
        /* Disable Interrupt to protect variables that could change on interrupt. */
        RadioController_DisableTxInt();
        
        RadioController_swStatusTx = RadioController_GET_STATUS_TX(RadioController_swStatusTx);
        
        if((RadioController_txBufferRead == RadioController_txBufferWrite) &&
            ((RadioController_swStatusTx & RadioController_STS_TX_FIFO_NOT_FULL) != 0u))
        {
            /* Add directly to the FIFO. */
            CY_SET_REG8(RadioController_TXDATA_PTR, txData);
        }
        else
        {
            /* Add to the software buffer. */
            RadioController_txBufferWrite++;
            if(RadioController_txBufferWrite >= RadioController_TXBUFFERSIZE)
            {
                RadioController_txBufferWrite = 0u;
            }   
                      
            if(RadioController_txBufferWrite == RadioController_txBufferRead)
            {
                RadioController_txBufferRead++;
                if(RadioController_txBufferRead >= RadioController_RXBUFFERSIZE)
                {
                    RadioController_txBufferRead = 0u;
                }
                RadioController_txBufferFull = 1u;
            }
            
            RadioController_TXBUFFER[RadioController_txBufferWrite] = txData;
            
            RadioController_TX_STATUS_MASK_REG |= RadioController_STS_TX_FIFO_NOT_FULL;            
        }                         
        
        /* Enable Interrupt. */
        RadioController_EnableTxInt();                        

    #else /* RadioController_TXBUFFERSIZE <= 4u */

        /* Block while FIFO is full */
        while((RadioController_TX_STATUS_REG & RadioController_STS_TX_FIFO_NOT_FULL) == 0u);
        
        /* Then write the byte */
        CY_SET_REG8(RadioController_TXDATA_PTR, txData);

    #endif /* RadioController_TXBUFFERSIZE > 4u */
}


/*******************************************************************************
* Function Name: RadioController_ReadRxData
********************************************************************************
*
* Summary:
*  Read the next byte of data received across the SPI.
*
* Parameters:
*  None.
*
* Return:
*  The next byte of data read from the FIFO.
*
* Global variables:
*  RadioController_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  RadioController_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function
*  call if RX Software Buffer is used.
*  RadioController_RXBUFFER[RadioController_RXBUFFERSIZE] - used to store
*  received data.
*
* Theory:
*  Allows the user to read a byte of data received.
*
* Side Effects:
*  Will return invalid data if the FIFO is empty. The user should Call 
*  GetRxBufferSize() and if it returns a non-zero value then it is safe to call 
*  ReadByte() function.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 RadioController_ReadRxData(void) 
{
    uint8 rxData = 0u;

    #if(RadioController_RXBUFFERSIZE > 4u)
    
        /* Disable Interrupt to protect variables that could change on interrupt. */
        RadioController_DisableRxInt();
        
        if(RadioController_rxBufferRead != RadioController_rxBufferWrite)
        {      
            if(RadioController_rxBufferFull == 0u)
            {
                RadioController_rxBufferRead++;
                if(RadioController_rxBufferRead >= RadioController_RXBUFFERSIZE)
                {
                    RadioController_rxBufferRead = 0u;
                }
            }
            else
            {
                RadioController_rxBufferFull = 0u;
            }
        }    
        
        rxData = RadioController_RXBUFFER[RadioController_rxBufferRead];
                           
        /* Enable Interrupt. */
        RadioController_EnableRxInt();
    
    #else /* RadioController_RXBUFFERSIZE <= 4u */
    
        rxData = CY_GET_REG8(RadioController_RXDATA_PTR);
    
    #endif /* RadioController_RXBUFFERSIZE > 4u */

	return (rxData);
    
}


/*******************************************************************************
* Function Name: RadioController_GetRxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the RX buffer.
*  If RX Software Buffer not used then function return 0 if FIFO empty or 1 if 
*  FIFO not empty. In another case function return size of RX Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the RX buffer.
*
* Global variables:
*  RadioController_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  RadioController_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8 RadioController_GetRxBufferSize(void) 
{
    uint8 size = 0u;

    #if(RadioController_RXBUFFERSIZE > 4u)
    
        /* Disable Interrupt to protect variables that could change on interrupt. */
        RadioController_DisableRxInt();
    
        if(RadioController_rxBufferRead == RadioController_rxBufferWrite)
        {
            size = 0u; /* No data in RX buffer */
        }
        else if(RadioController_rxBufferRead < RadioController_rxBufferWrite)
        {
            size = (RadioController_rxBufferWrite - RadioController_rxBufferRead);
        }
        else
        {
            size = (RadioController_RXBUFFERSIZE - RadioController_rxBufferRead) + RadioController_rxBufferWrite;
        }
    
        /* Enable interrupt. */
        RadioController_EnableRxInt();
    
    #else /* RadioController_RXBUFFERSIZE <= 4u */
    
        /* We can only know if there is data in the fifo. */
        size = ((RadioController_RX_STATUS_REG & RadioController_STS_RX_FIFO_NOT_EMPTY) == 
                 RadioController_STS_RX_FIFO_NOT_EMPTY) ? 1u : 0u;
    
    #endif /* RadioController_RXBUFFERSIZE < 4u */

    return (size);
}


/*******************************************************************************
* Function Name: RadioController_GetTxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the TX buffer.
*  If TX Software Buffer not used then function return 0 - if FIFO empty, 1 - if 
*  FIFO not full, 4 - if FIFO full. In another case function return size of TX
*  Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the TX buffer.
*
* Global variables:
*  RadioController_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  RadioController_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8  RadioController_GetTxBufferSize(void) 
{
    uint8 size = 0u;

    #if(RadioController_TXBUFFERSIZE > 4u)
    
        /* Disable Interrupt to protect variables that could change on interrupt. */
        RadioController_DisableTxInt();
    
        if(RadioController_txBufferRead == RadioController_txBufferWrite)
        {
            size = 0u;
        }
        else if(RadioController_txBufferRead < RadioController_txBufferWrite)
        {
            size = (RadioController_txBufferWrite - RadioController_txBufferRead);
        }
        else
        {
            size = (RadioController_TXBUFFERSIZE - RadioController_txBufferRead) + RadioController_txBufferWrite;
        }
    
        /* Enable Interrupt. */
        RadioController_EnableTxInt();
    
    #else /* RadioController_TXBUFFERSIZE <= 4u */
    
        size = RadioController_TX_STATUS_REG;
    
        /* Is the fifo is full. */
        if((size & RadioController_STS_TX_FIFO_EMPTY) == RadioController_STS_TX_FIFO_EMPTY)
        {
            size = 0u;
        }
        else if((size & RadioController_STS_TX_FIFO_NOT_FULL) == RadioController_STS_TX_FIFO_NOT_FULL)
        {
            size = 1u;
        }
        else
        {
            /* We only know there is data in the fifo. */
            size = 4u;
        }
    
    #endif /* RadioController_TXBUFFERSIZE > 4u */

    return (size);
}


/*******************************************************************************
* Function Name: RadioController_ClearRxBuffer
********************************************************************************
*
* Summary:
*  Clear the RX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  RadioController_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer, modified every function 
*  call - resets to zero.
*  RadioController_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to 
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any received data not read from the RAM buffer will be lost when overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RadioController_ClearRxBuffer(void) 
{
	/* Clear Hardware RX FIFO */
    while((!(RadioController_RX_STATUS_REG & RadioController_STS_RX_FIFO_NOT_EMPTY)) == 0u)
    {
        CY_GET_REG8(RadioController_RXDATA_PTR);
    }
	
    #if(RadioController_RXBUFFERSIZE > 4u)
    
        /* Disable interrupt to protect variables that could change on interrupt. */        
        RadioController_DisableRxInt();
    
        RadioController_rxBufferRead = 0u;
        RadioController_rxBufferWrite = 0u;
    
        /* Enable Rx interrupt. */
        RadioController_EnableRxInt();
        
    #endif /* RadioController_RXBUFFERSIZE > 4u */
}


/*******************************************************************************
* Function Name: RadioController_ClearTxBuffer
********************************************************************************
*
* Summary:
*  Clear the TX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  RadioController_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call - resets to zero.
*  RadioController_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to 
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any data not yet transmitted from the RAM buffer will be lost when 
*  overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RadioController_ClearTxBuffer(void) 
{
    uint8 enableInterrupts = 0u;
    
    /* Clear Hardware TX FIFO */       
    enableInterrupts = CyEnterCriticalSection();
    
    #if(RadioController_DataWidth <= 8u)
    
        /* Clear TX FIFO */
        RadioController_AUX_CONTROL_DP0_REG |= RadioController_FIFO_CLR;
        RadioController_AUX_CONTROL_DP0_REG &= ~RadioController_FIFO_CLR;
    
    #else
    
        /* Clear TX FIFO */
        RadioController_AUX_CONTROL_DP0_REG |= RadioController_FIFO_CLR;
        RadioController_AUX_CONTROL_DP0_REG &= ~RadioController_FIFO_CLR;
        RadioController_AUX_CONTROL_DP1_REG |= RadioController_FIFO_CLR;
        RadioController_AUX_CONTROL_DP1_REG &= ~RadioController_FIFO_CLR;
        
    #endif /* RadioController_DataWidth > 8u */
    
    CyExitCriticalSection(enableInterrupts);
	
    #if(RadioController_TXBUFFERSIZE > 4u)
    
        /* Disable Interrupt to protect variables that could change on interrupt. */
        RadioController_DisableTxInt();
    
        RadioController_txBufferRead = 0u;
        RadioController_txBufferWrite = 0u;
    
        /* If Buffer is empty then disable TX FIFO status interrupt */
        RadioController_TX_STATUS_MASK_REG &= ~RadioController_STS_TX_FIFO_NOT_FULL;

        /* Enable Interrupt. */
        RadioController_EnableTxInt();
    
    #endif /* RadioController_TXBUFFERSIZE > 4u */
}


#if (RadioController_BidirectionalMode == 1u)

    /*******************************************************************************
    * Function Name: RadioController_TxEnable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI master is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to transmit.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void RadioController_TxEnable(void) 
    {
        RadioController_CONTROL_REG |= RadioController_CTRL_TX_SIGNAL_EN;
    }
    
    
    /*******************************************************************************
    * Function Name: RadioController_TxDisable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI master is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to receive.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void RadioController_TxDisable(void) 
    {
        RadioController_CONTROL_REG &= ~RadioController_CTRL_TX_SIGNAL_EN;
    }
    
#endif /* RadioController_BidirectionalMode == 1u */


/*******************************************************************************
* Function Name: RadioController_PutArray
********************************************************************************                       
*
* Summary:
*  Write available data from ROM/RAM to the TX buffer while space is available 
*  in the TX buffer. Keep trying until all data is passed to the TX buffer.
*
* Parameters:
*  *buffer: Pointer to the location in RAM containing the data to send
*  byteCount: The number of bytes to move to the transmit buffer.
*
* Return:
*  None.
*
* Side Effects:
*  Will stay in this routine until all data has been sent.  May get locked in
*  this loop if data is not being initiated by the master if there is not
*  enough room in the TX FIFO.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RadioController_PutArray(uint8 *buffer, uint8 byteCount) 
{
    while(byteCount > 0u)
    {
        RadioController_WriteTxData(*buffer++);
        byteCount--;
    }
}


/*******************************************************************************
* Function Name: RadioController_ClearFIFO
********************************************************************************
*
* Summary:
*  Clear the RX and TX FIFO's of all data for a fresh start.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
void RadioController_ClearFIFO(void) 
{
    uint8 enableInterrupts = 0u;
    
    while((!(RadioController_RX_STATUS_REG & RadioController_STS_RX_FIFO_NOT_EMPTY)) == 0u)
    {
        CY_GET_REG8(RadioController_RXDATA_PTR);
    }
    
    enableInterrupts = CyEnterCriticalSection();
    
    #if(RadioController_DataWidth <= 8u)
    
        /* Clear TX FIFO */
        RadioController_AUX_CONTROL_DP0_REG |= RadioController_FIFO_CLR;
        RadioController_AUX_CONTROL_DP0_REG &= ~RadioController_FIFO_CLR;
    
    #else
    
        /* Clear TX FIFO */
        RadioController_AUX_CONTROL_DP0_REG |= RadioController_FIFO_CLR;
        RadioController_AUX_CONTROL_DP0_REG &= ~RadioController_FIFO_CLR;
        RadioController_AUX_CONTROL_DP1_REG |= RadioController_FIFO_CLR;
        RadioController_AUX_CONTROL_DP1_REG &= ~RadioController_FIFO_CLR;
        
    #endif /* RadioController_DataWidth > 8u */
    
    CyExitCriticalSection(enableInterrupts);
}


/* Following functions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects.
*/

/*******************************************************************************
* Function Name: RadioController_EnableInt
********************************************************************************
*
* Summary:
*  Enable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void RadioController_EnableInt(void) 
{       
    #if(RadioController_InternalTxInterruptEnabled)    
        CyIntEnable(RadioController_TX_ISR_NUMBER);
    #endif /* RadioController_InternalTxInterruptEnabled */                                
    
    #if(RadioController_InternalRxInterruptEnabled)           
        CyIntEnable(RadioController_RX_ISR_NUMBER);
    #endif /* RadioController_InternalRxInterruptEnabled */     
}


/*******************************************************************************
* Function Name: RadioController_DisableInt
********************************************************************************
*
* Summary:
*  Disable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void RadioController_DisableInt(void) 
{
    #if(RadioController_InternalTxInterruptEnabled)    
        CyIntDisable(RadioController_TX_ISR_NUMBER);
    #endif /* RadioController_InternalTxInterruptEnabled */
    
    #if(RadioController_InternalRxInterruptEnabled)           
        CyIntDisable(RadioController_RX_ISR_NUMBER);
    #endif /* RadioController_InternalRxInterruptEnabled */
}


/*******************************************************************************
* Function Name: RadioController_SetInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the 
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void RadioController_SetInterruptMode(uint8 intSrc) 
{
    RadioController_TX_STATUS_MASK_REG  = intSrc & ~(1u << RadioController_STS_SPI_IDLE_SHIFT);
    RadioController_RX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: RadioController_ReadStatus
********************************************************************************
*
* Summary:
*  Read the status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the status register.
*
* Global variables:
*  RadioController_swStatus - used to store in software status register, 
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the status register for error detection
*  and flow control.
*
* Side Effects:
*  Clear status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 RadioController_ReadStatus(void) 
{
    uint8 tmpStatus;
        
    #if ((RadioController_TXBUFFERSIZE > 4u) || (RadioController_RXBUFFERSIZE > 4u))
    
        RadioController_DisableInt();
        
        tmpStatus = (RadioController_GET_STATUS_TX(RadioController_swStatusTx) & 
                      ~(1u << RadioController_STS_SPI_IDLE_SHIFT)) | 
                      RadioController_GET_STATUS_RX(RadioController_swStatusRx);
        
        RadioController_swStatusTx = 0u;
        RadioController_swStatusRx = 0u;
        
        /* Enable Interrupts */
        RadioController_EnableInt();
        
    #else /* (RadioController_TXBUFFERSIZE < 4u) && (RadioController_RXBUFFERSIZE < 4u) */
    
        tmpStatus = (RadioController_TX_STATUS_REG & ~(1u << RadioController_STS_SPI_IDLE_SHIFT)) |
                     RadioController_RX_STATUS_REG;
        
    #endif /* (RadioController_TXBUFFERSIZE > 4u) || (RadioController_RXBUFFERSIZE > 4u) */
    
    return(tmpStatus);
}


/* [] END OF FILE */
