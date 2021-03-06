/*******************************************************************************
* File Name: SPIM_1_IntClock.h
* Version 1.50
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

#if !defined(CY_CLOCK_SPIM_1_IntClock_H)
#define CY_CLOCK_SPIM_1_IntClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void SPIM_1_IntClock_Start(void) ;
void SPIM_1_IntClock_Stop(void) ;

#if(!(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3 && \
    CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_3A_ES2) && \
	!(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5 && \
	CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_5A_ES1))
void SPIM_1_IntClock_StopBlock(void) ;
#endif

void SPIM_1_IntClock_StandbyPower(uint8 state) ;
void SPIM_1_IntClock_SetDividerRegister(uint16 clkDivider, uint8 reset) ;
uint16 SPIM_1_IntClock_GetDividerRegister(void) ;
void SPIM_1_IntClock_SetModeRegister(uint8 modeBitMask) ;
void SPIM_1_IntClock_ClearModeRegister(uint8 modeBitMask) ;
uint8 SPIM_1_IntClock_GetModeRegister(void) ;
void SPIM_1_IntClock_SetSourceRegister(uint8 clkSource) ;
uint8 SPIM_1_IntClock_GetSourceRegister(void) ;
#if defined(SPIM_1_IntClock__CFG3)
void SPIM_1_IntClock_SetPhaseRegister(uint8 clkPhase) ;
uint8 SPIM_1_IntClock_GetPhaseRegister(void) ;
#endif

#define SPIM_1_IntClock_Enable()                       SPIM_1_IntClock_Start()
#define SPIM_1_IntClock_Disable()                      SPIM_1_IntClock_Stop()
#define SPIM_1_IntClock_SetDivider(clkDivider)         SPIM_1_IntClock_SetDividerRegister(clkDivider, 1)
#define SPIM_1_IntClock_SetDividerValue(clkDivider)    SPIM_1_IntClock_SetDividerRegister((clkDivider) - 1, 1)
#define SPIM_1_IntClock_SetMode(clkMode)               SPIM_1_IntClock_SetModeRegister(clkMode)
#define SPIM_1_IntClock_SetSource(clkSource)           SPIM_1_IntClock_SetSourceRegister(clkSource)
#if defined(SPIM_1_IntClock__CFG3)
#define SPIM_1_IntClock_SetPhase(clkPhase)             SPIM_1_IntClock_SetPhaseRegister(clkPhase)
#define SPIM_1_IntClock_SetPhaseValue(clkPhase)        SPIM_1_IntClock_SetPhaseRegister((clkPhase) + 1)
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
#define SPIM_1_IntClock_CLKEN              (* (reg8 *) SPIM_1_IntClock__PM_ACT_CFG)
#define SPIM_1_IntClock_CLKEN_PTR          ((reg8 *) SPIM_1_IntClock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define SPIM_1_IntClock_CLKSTBY            (* (reg8 *) SPIM_1_IntClock__PM_STBY_CFG)
#define SPIM_1_IntClock_CLKSTBY_PTR        ((reg8 *) SPIM_1_IntClock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define SPIM_1_IntClock_DIV_LSB            (* (reg8 *) SPIM_1_IntClock__CFG0)
#define SPIM_1_IntClock_DIV_LSB_PTR        ((reg8 *) SPIM_1_IntClock__CFG0)
#define SPIM_1_IntClock_DIV_PTR            ((reg16 *) SPIM_1_IntClock__CFG0)

/* Clock MSB divider configuration register. */
#define SPIM_1_IntClock_DIV_MSB            (* (reg8 *) SPIM_1_IntClock__CFG1)
#define SPIM_1_IntClock_DIV_MSB_PTR        ((reg8 *) SPIM_1_IntClock__CFG1)

/* Mode and source configuration register */
#define SPIM_1_IntClock_MOD_SRC            (* (reg8 *) SPIM_1_IntClock__CFG2)
#define SPIM_1_IntClock_MOD_SRC_PTR        ((reg8 *) SPIM_1_IntClock__CFG2)

#if defined(SPIM_1_IntClock__CFG3)
/* Analog clock phase configuration register */
#define SPIM_1_IntClock_PHASE              (* (reg8 *) SPIM_1_IntClock__CFG3)
#define SPIM_1_IntClock_PHASE_PTR          ((reg8 *) SPIM_1_IntClock__CFG3)
#endif


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define SPIM_1_IntClock_CLKEN_MASK         SPIM_1_IntClock__PM_ACT_MSK
#define SPIM_1_IntClock_CLKSTBY_MASK       SPIM_1_IntClock__PM_STBY_MSK

/* CFG2 field masks */
#define SPIM_1_IntClock_SRC_SEL_MSK        SPIM_1_IntClock__CFG2_SRC_SEL_MASK
#define SPIM_1_IntClock_MODE_MASK          (~(SPIM_1_IntClock_SRC_SEL_MSK))

#if defined(SPIM_1_IntClock__CFG3)
/* CFG3 phase mask */
#define SPIM_1_IntClock_PHASE_MASK         SPIM_1_IntClock__CFG3_PHASE_DLY_MASK
#endif

#endif /* CY_CLOCK_SPIM_1_IntClock_H */


/* [] END OF FILE */
