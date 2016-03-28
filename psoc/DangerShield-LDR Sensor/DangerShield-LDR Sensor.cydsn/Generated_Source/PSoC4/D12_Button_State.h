/*******************************************************************************
* File Name: D12_Button_State.h  
* Version 1.80
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_D12_Button_State_H) /* CY_STATUS_REG_D12_Button_State_H */
#define CY_STATUS_REG_D12_Button_State_H

#include "cytypes.h"
#include "CyLib.h"


/***************************************
*        Function Prototypes
***************************************/

uint8 D12_Button_State_Read(void) ;
void D12_Button_State_InterruptEnable(void) ;
void D12_Button_State_InterruptDisable(void) ;
void D12_Button_State_WriteMask(uint8 mask) ;
uint8 D12_Button_State_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define D12_Button_State_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define D12_Button_State_INPUTS              1


/***************************************
*             Registers
***************************************/

/* Status Register */
#define D12_Button_State_Status             (* (reg8 *) D12_Button_State_sts_sts_reg__STATUS_REG )
#define D12_Button_State_Status_PTR         (  (reg8 *) D12_Button_State_sts_sts_reg__STATUS_REG )
#define D12_Button_State_Status_Mask        (* (reg8 *) D12_Button_State_sts_sts_reg__MASK_REG )
#define D12_Button_State_Status_Aux_Ctrl    (* (reg8 *) D12_Button_State_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_D12_Button_State_H */


/* [] END OF FILE */
