/*******************************************************************************
* File Name: MOSI.c  
* Version 1.60
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
#include "MOSI.h"


/*******************************************************************************
* Function Name: MOSI_Write
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
void MOSI_Write(uint8 value) 
{
    uint8 staticBits = MOSI_DR & ~MOSI_MASK;
    MOSI_DR = staticBits | ((value << MOSI_SHIFT) & MOSI_MASK);
}


/*******************************************************************************
* Function Name: MOSI_SetDriveMode
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
void MOSI_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(MOSI_0, mode);
}


/*******************************************************************************
* Function Name: MOSI_Read
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
*  Macro MOSI_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MOSI_Read(void) 
{
    return (MOSI_PS & MOSI_MASK) >> MOSI_SHIFT;
}


/*******************************************************************************
* Function Name: MOSI_ReadDataReg
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
uint8 MOSI_ReadDataReg(void) 
{
    return (MOSI_DR & MOSI_MASK) >> MOSI_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MOSI_INTSTAT) 

    /*******************************************************************************
    * Function Name: MOSI_ClearInterrupt
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
    uint8 MOSI_ClearInterrupt(void) 
    {
        return (MOSI_INTSTAT & MOSI_MASK) >> MOSI_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
