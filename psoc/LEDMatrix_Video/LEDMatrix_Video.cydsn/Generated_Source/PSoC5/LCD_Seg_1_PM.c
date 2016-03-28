/*******************************************************************************
* File Name: LCD_Seg_1_PM.c
* Version 3.40
*
* Description:
*  This file provides the API source code for Power Management of the Segment
*  LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "LCD_Seg_1.h"



static LCD_Seg_1_BACKUP_STRUCT LCD_Seg_1_backup;


/*******************************************************************************
* Function Name: LCD_Seg_1_SaveConfig
********************************************************************************
*
* Summary:
*  Stores user data. This function is called by the LCD_Seg_1_Sleep()
*  function prior entering to a Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void LCD_Seg_1_SaveConfig(void) 
{
    /* Nothing to save for current version of the component */

    /* Optional user code */
    /*`#START` SAVE_CONFIG_USER_CODE */

    /*`#END`*/

    #ifdef LCD_Seg_1_SAVE_CONFIG_CALLBACK
        LCD_Seg_1_SaveConfig_Callback();
    #endif /* LCD_Seg_1_SAVE_CONFIG_CALLBACK */
}


/*******************************************************************************
* Function Name: LCD_Seg_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores user data. This function is called by the LCD_Seg_1_Wakeup()
*  function after resuming from a Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void LCD_Seg_1_RestoreConfig(void) 
{
    /* Nothing to restore for current version of the component */

    /* Optional user code */
    /*`#START RESTORE_CONFIG_USER_CODE` */

    /*`#END`*/

    #ifdef LCD_Seg_1_RESTORE_CONFIG_CALLBACK
        LCD_Seg_1_RestoreConfig_Callback();
    #endif /* LCD_Seg_1_RESTORE_CONFIG_CALLBACK */
}


/*******************************************************************************
* Function Name: LCD_Seg_1_Sleep
********************************************************************************
*
* Summary:
*  Prepare the component to enter into a Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  LCD_Seg_1_backup - stores the state of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void LCD_Seg_1_Sleep(void) 
{
    if((LCD_Seg_1_CONTROL_REG & LCD_Seg_1_CNTL_CLK_EN) == LCD_Seg_1_CNTL_CLK_EN)
    {
        LCD_Seg_1_backup.enableState = LCD_Seg_1_LCD_STATE_ENABLED;
    }
    else
    {
        LCD_Seg_1_backup.enableState = LCD_Seg_1_LCD_STATE_DISABLED;
    }

    LCD_Seg_1_Stop();
    LCD_Seg_1_SaveConfig();
}


/*******************************************************************************
* Function Name: LCD_Seg_1_Wakeup
********************************************************************************
*
* Summary:
*  Wakes up components from a Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  Status one of standard status for PSoC3 Component:
*      CYRET_SUCCESS - Function completed successfully.
*      CYRET_LOCKED - The object was locked, already in use. Some of TDs or a
*                     channel already in use or the component was turned off by
*                     the user before entering to a sleep.
*
* Global variables:
*  LCD_Seg_1_backup - this API fetch the component state from the
*  structure to analyze and decide if the component should be enabled or not
*  after waking from a Sleep mode.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 LCD_Seg_1_Wakeup(void) 
{
    uint8 status;

    LCD_Seg_1_RestoreConfig();

    if(LCD_Seg_1_backup.enableState == LCD_Seg_1_LCD_STATE_ENABLED)
    {
        status = LCD_Seg_1_Enable();
    }
    else
    {
        status = CYRET_LOCKED;
    }

    return(status);
}


/* [] END OF FILE */
