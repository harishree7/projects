/*******************************************************************************
* File Name: A3.c  
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
#include "A3.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        A3_PC =   (A3_PC & \
                                (uint32)(~(uint32)(A3_DRIVE_MODE_IND_MASK << (A3_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (A3_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: A3_Write
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
void A3_Write(uint8 value) 
{
    uint8 drVal = (uint8)(A3_DR & (uint8)(~A3_MASK));
    drVal = (drVal | ((uint8)(value << A3_SHIFT) & A3_MASK));
    A3_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: A3_SetDriveMode
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
void A3_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(A3__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: A3_Read
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
*  Macro A3_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 A3_Read(void) 
{
    return (uint8)((A3_PS & A3_MASK) >> A3_SHIFT);
}


/*******************************************************************************
* Function Name: A3_ReadDataReg
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
uint8 A3_ReadDataReg(void) 
{
    return (uint8)((A3_DR & A3_MASK) >> A3_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(A3_INTSTAT) 

    /*******************************************************************************
    * Function Name: A3_ClearInterrupt
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
    uint8 A3_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(A3_INTSTAT & A3_MASK);
		A3_INTSTAT = maskedStatus;
        return maskedStatus >> A3_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
