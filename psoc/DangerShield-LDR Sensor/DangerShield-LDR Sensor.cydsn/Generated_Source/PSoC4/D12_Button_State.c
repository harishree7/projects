/*******************************************************************************
* File Name: D12_Button_State.c  
* Version 1.80
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "D12_Button_State.h"

#if !defined(D12_Button_State_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: D12_Button_State_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 D12_Button_State_Read(void) 
{ 
    return D12_Button_State_Status;
}


/*******************************************************************************
* Function Name: D12_Button_State_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void D12_Button_State_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    D12_Button_State_Status_Aux_Ctrl |= D12_Button_State_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: D12_Button_State_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void D12_Button_State_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    D12_Button_State_Status_Aux_Ctrl &= (uint8)(~D12_Button_State_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: D12_Button_State_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void D12_Button_State_WriteMask(uint8 mask) 
{
    #if(D12_Button_State_INPUTS < 8u)
    	mask &= (uint8)((((uint8)1u) << D12_Button_State_INPUTS) - 1u);
	#endif /* End D12_Button_State_INPUTS < 8u */
    D12_Button_State_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: D12_Button_State_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 D12_Button_State_ReadMask(void) 
{
    return D12_Button_State_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
