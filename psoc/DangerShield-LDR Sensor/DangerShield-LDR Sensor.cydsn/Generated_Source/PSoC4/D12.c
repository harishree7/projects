/*******************************************************************************
* File Name: D12.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "D12.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        D12_PC =   (D12_PC & \
                                (uint32)(~(uint32)(D12_DRIVE_MODE_IND_MASK << (D12_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (D12_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: D12_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void D12_Write(uint8 value) 
{
    uint8 drVal = (uint8)(D12_DR & (uint8)(~D12_MASK));
    drVal = (drVal | ((uint8)(value << D12_SHIFT) & D12_MASK));
    D12_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: D12_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void D12_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(D12__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: D12_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro D12_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 D12_Read(void) 
{
    return (uint8)((D12_PS & D12_MASK) >> D12_SHIFT);
}


/*******************************************************************************
* Function Name: D12_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 D12_ReadDataReg(void) 
{
    return (uint8)((D12_DR & D12_MASK) >> D12_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(D12_INTSTAT) 

    /*******************************************************************************
    * Function Name: D12_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 D12_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(D12_INTSTAT & D12_MASK);
		D12_INTSTAT = maskedStatus;
        return maskedStatus >> D12_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
