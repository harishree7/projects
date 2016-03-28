/*******************************************************************************
* File Name: RadioController_INT.c
* Version 2.21
*
* Description:
*  This file provides all Interrupt Service Routine (ISR) for the SPI Master
*  component.
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

#include "RadioController.h"

#if (RadioController_RXBUFFERSIZE > 4u)

    extern volatile uint8 RadioController_RXBUFFER[];
    extern volatile uint8 RadioController_rxBufferRead;
    extern volatile uint8 RadioController_rxBufferWrite;
    extern volatile uint8 RadioController_rxBufferFull;
    
#endif /* RadioController_RXBUFFERSIZE > 4u */

#if (RadioController_TXBUFFERSIZE > 4u)

    extern volatile uint8 RadioController_TXBUFFER[];
    extern volatile uint8 RadioController_txBufferRead;
    extern volatile uint8 RadioController_txBufferWrite;
    extern volatile uint8 RadioController_txBufferFull;

#endif /* RadioController_TXBUFFERSIZE > 4u */

volatile uint8 RadioController_swStatusTx = 0u;
volatile uint8 RadioController_swStatusRx = 0u;

/* User code required at start of ISR */
/* `#START RadioController_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: RadioController_TX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for TX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  RadioController_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  RadioController_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to 
*  sending and FIFO Not Full.
*  RadioController_TXBUFFER[RadioController_TXBUFFERSIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(RadioController_TX_ISR)
{     
    /* User code required at start of ISR */
    /* `#START RadioController_TX_ISR_START` */

    /* `#END` */
    
    #if((RadioController_InternalTxInterruptEnabled) && (RadioController_TXBUFFERSIZE > 4u))
                         
        /* See if TX data buffer is not empty and there is space in TX FIFO */
        while(RadioController_txBufferRead != RadioController_txBufferWrite)
        {
            RadioController_swStatusTx = RadioController_GET_STATUS_TX(RadioController_swStatusTx);
            
            if ((RadioController_swStatusTx & RadioController_STS_TX_FIFO_NOT_FULL) != 0u)
            {            
                if(RadioController_txBufferFull == 0u)
                {
                   RadioController_txBufferRead++;

                    if(RadioController_txBufferRead >= RadioController_TXBUFFERSIZE)
                    {
                        RadioController_txBufferRead = 0u;
                    }
                }
                else
                {
                    RadioController_txBufferFull = 0u;
                }
            
                /* Move data from the Buffer to the FIFO */
                CY_SET_REG8(RadioController_TXDATA_PTR,
                    RadioController_TXBUFFER[RadioController_txBufferRead]);
            }
            else
            {
                break;
            }            
        }
            
        /* Disable Interrupt on TX_fifo_not_empty if BUFFER is empty */
        if(RadioController_txBufferRead == RadioController_txBufferWrite)
        {
            RadioController_TX_STATUS_MASK_REG  &= ~RadioController_STS_TX_FIFO_NOT_FULL; 
        }                       
        
	#endif /* RadioController_InternalTxInterruptEnabled && (RadioController_TXBUFFERSIZE > 4u) */
    
    /* User code required at end of ISR (Optional) */
    /* `#START RadioController_TX_ISR_END` */

    /* `#END` */
    
    #ifdef RadioController_TxInternalInterrupt__ES2_PATCH
        #if(RadioController_PSOC3_ES2 && (RadioController_TxInternalInterrupt__ES2_PATCH))
            RadioController_TX_ISR_PATCH();
        #endif /* End PSOC3_ES2 */
    #endif /* RadioController_TxInternalInterrupt__ES2_PATCH */    
}


/*******************************************************************************
* Function Name: RadioController_RX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for RX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  RadioController_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  RadioController_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  RadioController_RXBUFFER[RadioController_RXBUFFERSIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(RadioController_RX_ISR)
{     
    #if((RadioController_InternalRxInterruptEnabled) && (RadioController_RXBUFFERSIZE > 4u))
        uint8 rxData = 0u; 
    #endif /* RadioController_InternalRxInterruptEnabled */  
    
    /* User code required at start of ISR */
    /* `#START RadioController_RX_ISR_START` */

    /* `#END` */
    
    #if((RadioController_InternalRxInterruptEnabled) && (RadioController_RXBUFFERSIZE > 4u))
         
        RadioController_swStatusRx = RadioController_GET_STATUS_RX(RadioController_swStatusRx);          
        
        /* See if RX data FIFO has some data and if it can be moved to the RX Buffer */
        while((RadioController_swStatusRx & RadioController_STS_RX_FIFO_NOT_EMPTY) == 
                                                                                RadioController_STS_RX_FIFO_NOT_EMPTY)
        {
            rxData = CY_GET_REG8(RadioController_RXDATA_PTR);
            
            /* Set next pointer. */
            RadioController_rxBufferWrite++;
            if(RadioController_rxBufferWrite >= RadioController_RXBUFFERSIZE)
            {
                RadioController_rxBufferWrite = 0u;
            }
            
            if(RadioController_rxBufferWrite == RadioController_rxBufferRead)
            {
                RadioController_rxBufferRead++;
                if(RadioController_rxBufferRead >= RadioController_RXBUFFERSIZE)
                {
                    RadioController_rxBufferRead = 0u;
                }
                RadioController_rxBufferFull = 1u;
            }
            
            /* Move data from the FIFO to the Buffer */
            RadioController_RXBUFFER[RadioController_rxBufferWrite] = rxData;
                
            RadioController_swStatusRx = RadioController_GET_STATUS_RX(RadioController_swStatusRx);
        }                    
        
	#endif /* RadioController_InternalRxInterruptEnabled  && (RadioController_RXBUFFERSIZE > 4u) */        
    
    /* User code required at end of ISR (Optional) */
    /* `#START RadioController_RX_ISR_END` */

    /* `#END` */
    
    #ifdef RadioController_RxInternalInterrupt__ES2_PATCH
        #if(RadioController_PSOC3_ES2 && (RadioController_RxInternalInterrupt__ES2_PATCH))
            RadioController_RX_ISR_PATCH();
        #endif /* End PSOC3_ES2 */  
    #endif /* RadioController_RxInternalInterrupt__ES2_PATCH */       
}

/* [] END OF FILE */
