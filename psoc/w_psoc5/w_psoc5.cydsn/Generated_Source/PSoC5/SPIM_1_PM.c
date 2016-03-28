/*******************************************************************************
* File Name: SPIM_1_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control and status commands to support 
*  component operations in low power mode.  
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIM_1.h"

static SPIM_1_BACKUP_STRUCT SPIM_1_backup = {
                                        0u,
                                        SPIM_1_BITCTR_INIT,
                                        #if(SPIM_1_PSOC3_ES2 || SPIM_1_PSOC5_ES1)
                                            SPIM_1_TX_INIT_INTERRUPTS_MASK,
                                            SPIM_1_RX_INIT_INTERRUPTS_MASK
                                        #endif /* SPIM_1_PSOC3_ES2 || SPIM_1_PSOC5_ES1 */
                                        };

#if (SPIM_1_TXBUFFERSIZE > 4u)

    extern volatile uint8 SPIM_1_txBufferRead;
    extern volatile uint8 SPIM_1_txBufferWrite;
    
#endif /* SPIM_1_TXBUFFERSIZE > 4u */

#if (SPIM_1_RXBUFFERSIZE > 4u)

    extern volatile uint8 SPIM_1_rxBufferRead;
    extern volatile uint8 SPIM_1_rxBufferWrite;
    
#endif /* SPIM_1_RXBUFFERSIZE > 4u */


/*******************************************************************************
* Function Name: SPIM_1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves SPIM configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
* 
* Global Variables:
*  SPIM_1_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_1_SaveConfig(void)
{
    /* Store Status Mask registers */
    #if (SPIM_1_PSOC3_ES2 || SPIM_1_PSOC5_ES1)     
    
       SPIM_1_backup.saveSrTxIntMask = SPIM_1_TX_STATUS_MASK_REG;
       SPIM_1_backup.saveSrRxIntMask = SPIM_1_RX_STATUS_MASK_REG;
       SPIM_1_backup.cntrPeriod = SPIM_1_COUNTER_PERIOD_REG;
       
    #endif /* (SPIM_1_PSOC3_ES2 || SPIM_1_PSOC5_ES1) */
}


/*******************************************************************************
* Function Name: SPIM_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores SPIM configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIM_1_backup - used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer: 
*  SPIM_1_STATUS_MASK_REG and SPIM_1_COUNTER_PERIOD_REG.
*
*******************************************************************************/
void SPIM_1_RestoreConfig(void) 
{
    /* Restore the data, saved by SaveConfig() function */
    #if (SPIM_1_PSOC3_ES2 || SPIM_1_PSOC5_ES1)
    
        SPIM_1_TX_STATUS_MASK_REG = SPIM_1_backup.saveSrTxIntMask;
        SPIM_1_RX_STATUS_MASK_REG = SPIM_1_backup.saveSrRxIntMask;
        SPIM_1_COUNTER_PERIOD_REG = SPIM_1_backup.cntrPeriod;
        
    #endif /* (SPIM_1_PSOC3_ES2 || SPIM_1_PSOC5_ES1) */
}


/*******************************************************************************
* Function Name: SPIM_1_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:  
*  None.
*
* Return: 
*  None.
*
* Global Variables:
*  SPIM_1_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_1_Sleep(void)
{
    /* Save components enable state */
    if ((SPIM_1_TX_STATUS_ACTL_REG & SPIM_1_INT_ENABLE) == SPIM_1_INT_ENABLE)
    {
        SPIM_1_backup.enableState = 1u;
    }
    else /* Components block is disabled */
    {
        SPIM_1_backup.enableState = 0u;
    }

    SPIM_1_Stop();

    SPIM_1_SaveConfig();
}


/*******************************************************************************
* Function Name: SPIM_1_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:  
*  None.
*
* Return: 
*  None.
*
* Global Variables:
*  SPIM_1_backup - used when non-retention registers are restored.
*  SPIM_1_txBufferWrite - modified every function call - resets to 
*  zero.
*  SPIM_1_txBufferRead - modified every function call - resets to 
*  zero.
*  SPIM_1_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_1_rxBufferRead - modified every function call - resets to
*  zero. 
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_1_Wakeup(void)
{        
    SPIM_1_RestoreConfig();
         
    #if (SPIM_1_TXBUFFERSIZE > 4u)
    
        SPIM_1_txBufferRead = 0u;
        SPIM_1_txBufferWrite = 0u;
        
    #endif /* SPIM_1_TXBUFFERSIZE > 4u */
    
    #if (SPIM_1_RXBUFFERSIZE > 4u)    
    
        SPIM_1_rxBufferRead = 0u;
        SPIM_1_rxBufferWrite = 0u;
        
    #endif /* SPIM_1_RXBUFFERSIZE > 4u */ 
    
    SPIM_1_ClearFIFO();
    
    /* Restore components block enable state */
    if (SPIM_1_backup.enableState != 0u)
    {
         /* Components block was enabled */
         SPIM_1_Enable();
    } /* Do nothing if components block was disabled */
}


/* [] END OF FILE */
