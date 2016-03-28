/*******************************************************************************
* File Name: LCD_Seg_1_INT.c
* Version 3.40
*
* Description:
*  This file contains the Interrupt Service Routine (ISR) for the Segment LCD
*  Component.
*
********************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "LCD_Seg_1.h"


/*`#START START_USER_DECLARATIONS`*/

/*`#END`*/


/******************************************************************************
* Function Name: LCD_Seg_1_ISR
*******************************************************************************
*
* Summary:
*  This ISR is executed when the sub-frame completion event occurs. Both
*  global interrupts and component interrupts must be enabled to invoke this
*  ISR.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
******************************************************************************/
CY_ISR(LCD_Seg_1_ISR)
{
    #ifdef LCD_Seg_1_ISR_INTERRUPT_CALLBACK
        LCD_Seg_1_ISR_InterruptCallback();
    #endif /* LCD_Seg_1_ISR_INTERRUPT_CALLBACK */
    
    /* User code required for ISR */
    /*`#START START_ISR`*/

    /*`#END`*/
}


/******************************************************************************
* Function Name: LCD_Seg_1_WAKEUP_ISR
*******************************************************************************
*
* Summary:
*  This ISR is executed when LCD timer generates an wakeup interrupt. PSoC 5
*  core (Cortex M3) requires an ISR to be able to wakeup from Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
******************************************************************************/
CY_ISR(LCD_Seg_1_WAKEUP_ISR)
{
    #ifdef LCD_Seg_1_WAKEUP_ISR_INTERRUPT_CALLBACK
        LCD_Seg_1_WAKEUP_ISR_InterruptCallback();
    #endif /* LCD_Seg_1_WAKEUP_ISR_INTERRUPT_CALLBACK */

    /* User code required for ISR */
    /*`#START START_WAKEUP_ISR`*/

    /*`#END`*/
}


/* [] END OF FILE */
