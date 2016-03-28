/*******************************************************************************
* File Name: RST.c  
* Version 1.50
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "RST.h"


/*******************************************************************************
* Function Name: RST_Write
********************************************************************************
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  void 
*  
*******************************************************************************/
void RST_Write(uint8 value) 
{
    uint8 staticBits = RST_DR & ~RST_MASK;
    RST_DR = staticBits | ((value << RST_SHIFT) & RST_MASK);
}


/*******************************************************************************
* Function Name: RST_SetDriveMode
********************************************************************************
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  void
*
*******************************************************************************/
void RST_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(RST_0, mode);
}


/*******************************************************************************
* Function Name: RST_Read
********************************************************************************
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro RST_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 RST_Read(void) 
{
    return (RST_PS & RST_MASK) >> RST_SHIFT;
}


/*******************************************************************************
* Function Name: RST_ReadDataReg
********************************************************************************
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 RST_ReadDataReg(void) 
{
    return (RST_DR & RST_MASK) >> RST_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(RST_INTSTAT) 

    /*******************************************************************************
    * Function Name: RST_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  void 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 RST_ClearInterrupt(void) 
    {
        return (RST_INTSTAT & RST_MASK) >> RST_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
