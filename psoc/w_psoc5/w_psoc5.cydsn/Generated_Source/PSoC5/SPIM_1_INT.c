/*******************************************************************************
* File Name: SPIM_1_INT.c
* Version 2.10
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

#include "SPIM_1.h"

#if (SPIM_1_RXBUFFERSIZE > 4u)

    extern volatile uint8 SPIM_1_RXBUFFER[];
    extern volatile uint8 SPIM_1_rxBufferRead;
    extern volatile uint8 SPIM_1_rxBufferWrite;
    extern volatile uint8 SPIM_1_rxBufferFull;
    
#endif /* SPIM_1_RXBUFFERSIZE > 4u */

#if (SPIM_1_TXBUFFERSIZE > 4u)

    extern volatile uint8 SPIM_1_TXBUFFER[];
    extern volatile uint8 SPIM_1_txBufferRead;
    extern volatile uint8 SPIM_1_txBufferWrite;
    extern volatile uint8 SPIM_1_txBufferFull;

#endif /* SPIM_1_TXBUFFERSIZE > 4u */

volatile uint8 SPIM_1_swStatusTx = 0u;
volatile uint8 SPIM_1_swStatusRx = 0u;

/* User code required at start of ISR */
/* `#START SPIM_1_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: SPIM_1_TX_ISR
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
*  SPIM_1_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPIM_1_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to 
*  sending and FIFO Not Full.
*  SPIM_1_TXBUFFER[SPIM_1_TXBUFFERSIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIM_1_TX_ISR)
{     
    /* User code required at start of ISR */
    /* `#START SPIM_1_TX_ISR_START` */

    /* `#END` */
    
    #if((SPIM_1_InternalTxInterruptEnabled) && (SPIM_1_TXBUFFERSIZE > 4u))
                         
        /* See if TX data buffer is not empty and there is space in TX FIFO */
        while(SPIM_1_txBufferRead != SPIM_1_txBufferWrite)
        {
            SPIM_1_swStatusTx = SPIM_1_GET_STATUS_TX(SPIM_1_swStatusTx);
            
            if ((SPIM_1_swStatusTx & SPIM_1_STS_TX_FIFO_NOT_FULL) != 0u)
            {            
                if(SPIM_1_txBufferFull == 0u)
                {
                   SPIM_1_txBufferRead++;

                    if(SPIM_1_txBufferRead >= SPIM_1_TXBUFFERSIZE)
                    {
                        SPIM_1_txBufferRead = 0u;
                    }
                }
                else
                {
                    SPIM_1_txBufferFull = 0u;
                }
            
                /* Move data from the Buffer to the FIFO */
                CY_SET_REG8(SPIM_1_TXDATA_PTR,
                    SPIM_1_TXBUFFER[SPIM_1_txBufferRead]);
            }
            else
            {
                break;
            }            
        }
            
        /* Disable Interrupt on TX_fifo_not_empty if BUFFER is empty */
        if(SPIM_1_txBufferRead == SPIM_1_txBufferWrite)
        {
            SPIM_1_TX_STATUS_MASK_REG  &= ~SPIM_1_STS_TX_FIFO_NOT_FULL; 
        }                       
        
	#endif /* SPIM_1_InternalTxInterruptEnabled && (SPIM_1_TXBUFFERSIZE > 4u) */
    
    /* User code required at end of ISR (Optional) */
    /* `#START SPIM_1_TX_ISR_END` */

    /* `#END` */
    
    #ifdef SPIM_1_TxInternalInterrupt__ES2_PATCH
        #if(SPIM_1_PSOC3_ES2 && (SPIM_1_TxInternalInterrupt__ES2_PATCH))
            SPIM_1_TX_ISR_PATCH();
        #endif /* End PSOC3_ES2 */
    #endif /* SPIM_1_TxInternalInterrupt__ES2_PATCH */    
}


/*******************************************************************************
* Function Name: SPIM_1_RX_ISR
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
*  SPIM_1_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  SPIM_1_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  SPIM_1_RXBUFFER[SPIM_1_RXBUFFERSIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIM_1_RX_ISR)
{     
    #if((SPIM_1_InternalRxInterruptEnabled) && (SPIM_1_RXBUFFERSIZE > 4u))
        uint8 rxData = 0u; 
    #endif /* SPIM_1_InternalRxInterruptEnabled */  
    
    /* User code required at start of ISR */
    /* `#START SPIM_1_RX_ISR_START` */

    /* `#END` */
    
    #if((SPIM_1_InternalRxInterruptEnabled) && (SPIM_1_RXBUFFERSIZE > 4u))
         
        SPIM_1_swStatusRx = SPIM_1_GET_STATUS_RX(SPIM_1_swStatusRx);          
        
        /* See if RX data FIFO has some data and if it can be moved to the RX Buffer */
        while((SPIM_1_swStatusRx & SPIM_1_STS_RX_FIFO_NOT_EMPTY) == 
                                                                                SPIM_1_STS_RX_FIFO_NOT_EMPTY)
        {
            rxData = CY_GET_REG8(SPIM_1_RXDATA_PTR);
            
            /* Set next pointer. */
            SPIM_1_rxBufferWrite++;
            if(SPIM_1_rxBufferWrite >= SPIM_1_RXBUFFERSIZE)
            {
                SPIM_1_rxBufferWrite = 0u;
            }
            
            if(SPIM_1_rxBufferWrite == SPIM_1_rxBufferRead)
            {
                SPIM_1_rxBufferRead++;
                if(SPIM_1_rxBufferRead >= SPIM_1_RXBUFFERSIZE)
                {
                    SPIM_1_rxBufferRead = 0u;
                }
                SPIM_1_rxBufferFull = 1u;
            }
            
            /* Move data from the FIFO to the Buffer */
            SPIM_1_RXBUFFER[SPIM_1_rxBufferWrite] = rxData;
                
            SPIM_1_swStatusRx = SPIM_1_GET_STATUS_RX(SPIM_1_swStatusRx);
        }                    
        
	#endif /* SPIM_1_InternalRxInterruptEnabled  && (SPIM_1_RXBUFFERSIZE > 4u) */        
    
    /* User code required at end of ISR (Optional) */
    /* `#START SPIM_1_RX_ISR_END` */

    /* `#END` */
    
    #ifdef SPIM_1_RxInternalInterrupt__ES2_PATCH
        #if(SPIM_1_PSOC3_ES2 && (SPIM_1_RxInternalInterrupt__ES2_PATCH))
            SPIM_1_RX_ISR_PATCH();
        #endif /* End PSOC3_ES2 */  
    #endif /* SPIM_1_RxInternalInterrupt__ES2_PATCH */       
}

/* [] END OF FILE */
