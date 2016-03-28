/*******************************************************************************
* File Name: .h
* Version 1.0
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in I2C mode.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_UART_H)
#define CY_SCB_PVT_UART_H

#include "UART.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define UART_SetI2CExtClkInterruptMode(interruptMask) UART_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define UART_ClearI2CExtClkInterruptSource(interruptMask) UART_CLEAR_INTR_I2C_EC(interruptMask)
#define UART_GetI2CExtClkInterruptSource()                (UART_INTR_I2C_EC_REG)
#define UART_GetI2CExtClkInterruptMode()                  (UART_INTR_I2C_EC_MASK_REG)
#define UART_GetI2CExtClkInterruptSourceMasked()          (UART_INTR_I2C_EC_MASKED_REG)

/* APIs to service INTR_SPI_EC register */
#define UART_SetSpiExtClkInterruptMode(interruptMask) UART_WRITE_INTR_SPI_EC_MASK(interruptMask)
#define UART_ClearSpiExtClkInterruptSource(interruptMask) UART_CLEAR_INTR_SPI_EC(interruptMask)
#define UART_GetExtSpiClkInterruptSource()                 (UART_INTR_SPI_EC_REG)
#define UART_GetExtSpiClkInterruptMode()                   (UART_INTR_SPI_EC_MASK_REG)
#define UART_GetExtSpiClkInterruptSourceMasked()           (UART_INTR_SPI_EC_MASKED_REG)

#if(UART_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void UART_SetPins(uint32 mode, uint32 subMode, uint32 uartTxRx);
#endif /* (UART_SCB_MODE_UNCONFIG_CONST_CFG) */

#endif /* (CY_SCB_PVT_UART_H) */


/* [] END OF FILE */
