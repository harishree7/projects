/*******************************************************************************
* File Name: RadioController_PM.c
* Version 2.21
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

#include "RadioController.h"

static RadioController_BACKUP_STRUCT RadioController_backup = {
                                        0u,
                                        RadioController_BITCTR_INIT,
                                        #if(RadioController_PSOC3_ES2 || RadioController_PSOC5_ES1)
                                            RadioController_TX_INIT_INTERRUPTS_MASK,
                                            RadioController_RX_INIT_INTERRUPTS_MASK
                                        #endif /* RadioController_PSOC3_ES2 || RadioController_PSOC5_ES1 */
                                        };

#if (RadioController_TXBUFFERSIZE > 4u)

    extern volatile uint8 RadioController_txBufferRead;
    extern volatile uint8 RadioController_txBufferWrite;
    
#endif /* RadioController_TXBUFFERSIZE > 4u */

#if (RadioController_RXBUFFERSIZE > 4u)

    extern volatile uint8 RadioController_rxBufferRead;
    extern volatile uint8 RadioController_rxBufferWrite;
    
#endif /* RadioController_RXBUFFERSIZE > 4u */


/*******************************************************************************
* Function Name: RadioController_SaveConfig
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
*  RadioController_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RadioController_SaveConfig(void) 
{
    /* Store Status Mask registers */
    #if (RadioController_PSOC3_ES2 || RadioController_PSOC5_ES1)     
    
       RadioController_backup.saveSrTxIntMask = RadioController_TX_STATUS_MASK_REG;
       RadioController_backup.saveSrRxIntMask = RadioController_RX_STATUS_MASK_REG;
       RadioController_backup.cntrPeriod = RadioController_COUNTER_PERIOD_REG;
       
    #endif /* (RadioController_PSOC3_ES2 || RadioController_PSOC5_ES1) */
}


/*******************************************************************************
* Function Name: RadioController_RestoreConfig
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
*  RadioController_backup - used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer: 
*  RadioController_STATUS_MASK_REG and RadioController_COUNTER_PERIOD_REG.
*
*******************************************************************************/
void RadioController_RestoreConfig(void) 
{
    /* Restore the data, saved by SaveConfig() function */
    #if (RadioController_PSOC3_ES2 || RadioController_PSOC5_ES1)
    
        RadioController_TX_STATUS_MASK_REG = RadioController_backup.saveSrTxIntMask;
        RadioController_RX_STATUS_MASK_REG = RadioController_backup.saveSrRxIntMask;
        RadioController_COUNTER_PERIOD_REG = RadioController_backup.cntrPeriod;
        
    #endif /* (RadioController_PSOC3_ES2 || RadioController_PSOC5_ES1) */
}


/*******************************************************************************
* Function Name: RadioController_Sleep
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
*  RadioController_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RadioController_Sleep(void) 
{
    /* Save components enable state */
    if ((RadioController_TX_STATUS_ACTL_REG & RadioController_INT_ENABLE) == RadioController_INT_ENABLE)
    {
        RadioController_backup.enableState = 1u;
    }
    else /* Components block is disabled */
    {
        RadioController_backup.enableState = 0u;
    }

    RadioController_Stop();

    RadioController_SaveConfig();
}


/*******************************************************************************
* Function Name: RadioController_Wakeup
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
*  RadioController_backup - used when non-retention registers are restored.
*  RadioController_txBufferWrite - modified every function call - resets to 
*  zero.
*  RadioController_txBufferRead - modified every function call - resets to 
*  zero.
*  RadioController_rxBufferWrite - modified every function call - resets to
*  zero.
*  RadioController_rxBufferRead - modified every function call - resets to
*  zero. 
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RadioController_Wakeup(void) 
{        
    RadioController_RestoreConfig();
         
    #if (RadioController_TXBUFFERSIZE > 4u)
    
        RadioController_txBufferRead = 0u;
        RadioController_txBufferWrite = 0u;
        
    #endif /* RadioController_TXBUFFERSIZE > 4u */
    
    #if (RadioController_RXBUFFERSIZE > 4u)    
    
        RadioController_rxBufferRead = 0u;
        RadioController_rxBufferWrite = 0u;
        
    #endif /* RadioController_RXBUFFERSIZE > 4u */ 
    
    RadioController_ClearFIFO();
    
    /* Restore components block enable state */
    if (RadioController_backup.enableState != 0u)
    {
         /* Components block was enabled */
         RadioController_Enable();
    } /* Do nothing if components block was disabled */
}


/* [] END OF FILE */
