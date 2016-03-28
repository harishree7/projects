/*******************************************************************************
* File Name: Switch_Clock.h
* Version 2.0
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Switch_Clock_H)
#define CY_CLOCK_Switch_Clock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void Switch_Clock_Start(void);
void Switch_Clock_Stop(void);

void Switch_Clock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Switch_Clock_GetDividerRegister(void);
uint8  Switch_Clock_GetFractionalDividerRegister(void);

#define Switch_Clock_Enable()                         Switch_Clock_Start()
#define Switch_Clock_Disable()                        Switch_Clock_Stop()
#define Switch_Clock_SetDividerRegister(clkDivider, reset)  \
                        Switch_Clock_SetFractionalDividerRegister((clkDivider), 0)
#define Switch_Clock_SetDivider(clkDivider)           Switch_Clock_SetDividerRegister((clkDivider), 1)
#define Switch_Clock_SetDividerValue(clkDivider)      Switch_Clock_SetDividerRegister((clkDivider) - 1, 1)


/***************************************
*             Registers
***************************************/

#define Switch_Clock_DIV_REG    (*(reg32 *)Switch_Clock__REGISTER)
#define Switch_Clock_ENABLE_REG Switch_Clock_DIV_REG

#endif /* !defined(CY_CLOCK_Switch_Clock_H) */

/* [] END OF FILE */
