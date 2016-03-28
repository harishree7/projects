/*******************************************************************************
* File Name: RadioController_IntClock.h
* Version 1.60
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_CLOCK_RadioController_IntClock_H)
#define CY_CLOCK_RadioController_IntClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void RadioController_IntClock_Start(void) ;
void RadioController_IntClock_Stop(void) ;

#if(!(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3 && \
    CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_3A_ES2) && \
	!(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5 && \
	CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_5A_ES1))
void RadioController_IntClock_StopBlock(void) ;
#endif

void RadioController_IntClock_StandbyPower(uint8 state) ;
void RadioController_IntClock_SetDividerRegister(uint16 clkDivider, uint8 reset) ;
uint16 RadioController_IntClock_GetDividerRegister(void) ;
void RadioController_IntClock_SetModeRegister(uint8 modeBitMask) ;
void RadioController_IntClock_ClearModeRegister(uint8 modeBitMask) ;
uint8 RadioController_IntClock_GetModeRegister(void) ;
void RadioController_IntClock_SetSourceRegister(uint8 clkSource) ;
uint8 RadioController_IntClock_GetSourceRegister(void) ;
#if defined(RadioController_IntClock__CFG3)
void RadioController_IntClock_SetPhaseRegister(uint8 clkPhase) ;
uint8 RadioController_IntClock_GetPhaseRegister(void) ;
#endif

#define RadioController_IntClock_Enable()                       RadioController_IntClock_Start()
#define RadioController_IntClock_Disable()                      RadioController_IntClock_Stop()
#define RadioController_IntClock_SetDivider(clkDivider)         RadioController_IntClock_SetDividerRegister(clkDivider, 1)
#define RadioController_IntClock_SetDividerValue(clkDivider)    RadioController_IntClock_SetDividerRegister((clkDivider) - 1, 1)
#define RadioController_IntClock_SetMode(clkMode)               RadioController_IntClock_SetModeRegister(clkMode)
#define RadioController_IntClock_SetSource(clkSource)           RadioController_IntClock_SetSourceRegister(clkSource)
#if defined(RadioController_IntClock__CFG3)
#define RadioController_IntClock_SetPhase(clkPhase)             RadioController_IntClock_SetPhaseRegister(clkPhase)
#define RadioController_IntClock_SetPhaseValue(clkPhase)        RadioController_IntClock_SetPhaseRegister((clkPhase) + 1)
#endif


/***************************************
*           API Constants
***************************************/

/* Constants SetPhase(), clkPhase parameter. Only valid for PSoC 3 ES2 and earlier. See datasheet for details. */
#if CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3 && \
   (CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_3A_ES1 || \
    CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_3A_ES2)
#define CYCLK_2_5NS             0x01 /* 2.5 ns delay. */
#define CYCLK_3_5NS             0x02 /* 3.5 ns delay. */
#define CYCLK_4_5NS             0x03 /* 4.5 ns delay. */
#define CYCLK_5_5NS             0x04 /* 5.5 ns delay. */
#define CYCLK_6_5NS             0x05 /* 6.5 ns delay. */
#define CYCLK_7_5NS             0x06 /* 7.5 ns delay. */
#define CYCLK_8_5NS             0x07 /* 8.5 ns delay. */
#define CYCLK_9_5NS             0x08 /* 9.5 ns delay. */
#define CYCLK_10_5NS            0x09 /* 10.5 ns delay. */
#define CYCLK_11_5NS            0x0A /* 11.5 ns delay. */
#define CYCLK_12_5NS            0x0B /* 12.5 ns delay. */
#endif


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define RadioController_IntClock_CLKEN              (* (reg8 *) RadioController_IntClock__PM_ACT_CFG)
#define RadioController_IntClock_CLKEN_PTR          ((reg8 *) RadioController_IntClock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define RadioController_IntClock_CLKSTBY            (* (reg8 *) RadioController_IntClock__PM_STBY_CFG)
#define RadioController_IntClock_CLKSTBY_PTR        ((reg8 *) RadioController_IntClock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define RadioController_IntClock_DIV_LSB            (* (reg8 *) RadioController_IntClock__CFG0)
#define RadioController_IntClock_DIV_LSB_PTR        ((reg8 *) RadioController_IntClock__CFG0)
#define RadioController_IntClock_DIV_PTR            ((reg16 *) RadioController_IntClock__CFG0)

/* Clock MSB divider configuration register. */
#define RadioController_IntClock_DIV_MSB            (* (reg8 *) RadioController_IntClock__CFG1)
#define RadioController_IntClock_DIV_MSB_PTR        ((reg8 *) RadioController_IntClock__CFG1)

/* Mode and source configuration register */
#define RadioController_IntClock_MOD_SRC            (* (reg8 *) RadioController_IntClock__CFG2)
#define RadioController_IntClock_MOD_SRC_PTR        ((reg8 *) RadioController_IntClock__CFG2)

#if defined(RadioController_IntClock__CFG3)
/* Analog clock phase configuration register */
#define RadioController_IntClock_PHASE              (* (reg8 *) RadioController_IntClock__CFG3)
#define RadioController_IntClock_PHASE_PTR          ((reg8 *) RadioController_IntClock__CFG3)
#endif


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define RadioController_IntClock_CLKEN_MASK         RadioController_IntClock__PM_ACT_MSK
#define RadioController_IntClock_CLKSTBY_MASK       RadioController_IntClock__PM_STBY_MSK

/* CFG2 field masks */
#define RadioController_IntClock_SRC_SEL_MSK        RadioController_IntClock__CFG2_SRC_SEL_MASK
#define RadioController_IntClock_MODE_MASK          (~(RadioController_IntClock_SRC_SEL_MSK))

#if defined(RadioController_IntClock__CFG3)
/* CFG3 phase mask */
#define RadioController_IntClock_PHASE_MASK         RadioController_IntClock__CFG3_PHASE_DLY_MASK
#endif

#endif /* CY_CLOCK_RadioController_IntClock_H */


/* [] END OF FILE */
