/*******************************************************************************
* File Name: LED_1.c  
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
#include "LED_1.h"


/*******************************************************************************
* Function Name: LED_1_Write
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
void LED_1_Write(uint8 value) 
{
    uint8 staticBits = LED_1_DR & ~LED_1_MASK;
    LED_1_DR = staticBits | ((value << LED_1_SHIFT) & LED_1_MASK);
}


/*******************************************************************************
* Function Name: LED_1_SetDriveMode
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
void LED_1_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LED_1_0, mode);
}


/*******************************************************************************
* Function Name: LED_1_Read
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
*  Macro LED_1_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LED_1_Read(void) 
{
    return (LED_1_PS & LED_1_MASK) >> LED_1_SHIFT;
}


/*******************************************************************************
* Function Name: LED_1_ReadDataReg
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
uint8 LED_1_ReadDataReg(void) 
{
    return (LED_1_DR & LED_1_MASK) >> LED_1_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LED_1_INTSTAT) 

    /*******************************************************************************
    * Function Name: LED_1_ClearInterrupt
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
    uint8 LED_1_ClearInterrupt(void) 
    {
        return (LED_1_INTSTAT & LED_1_MASK) >> LED_1_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
