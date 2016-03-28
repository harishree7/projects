/*******************************************************************************
* File Name: SCK.h  
* Version 1.60
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PINS_SCK_H) /* Pins SCK_H */
#define CY_PINS_SCK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SCK_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5 &&\
     CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_5A_PRODUCTION &&\
	 SCK__PORT == 15 && (SCK__MASK & 0xC0))

/***************************************
*        Function Prototypes             
***************************************/    

void    SCK_Write(uint8 value) ;
void    SCK_SetDriveMode(uint8 mode) ;
uint8   SCK_ReadDataReg(void) ;
uint8   SCK_Read(void) ;
uint8   SCK_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SCK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SCK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SCK_DM_RES_UP          PIN_DM_RES_UP
#define SCK_DM_RES_DWN         PIN_DM_RES_DWN
#define SCK_DM_OD_LO           PIN_DM_OD_LO
#define SCK_DM_OD_HI           PIN_DM_OD_HI
#define SCK_DM_STRONG          PIN_DM_STRONG
#define SCK_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SCK_MASK               SCK__MASK
#define SCK_SHIFT              SCK__SHIFT
#define SCK_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SCK_PS                     (* (reg8 *) SCK__PS)
/* Data Register */
#define SCK_DR                     (* (reg8 *) SCK__DR)
/* Port Number */
#define SCK_PRT_NUM                (* (reg8 *) SCK__PRT) 
/* Connect to Analog Globals */                                                  
#define SCK_AG                     (* (reg8 *) SCK__AG)                       
/* Analog MUX bux enable */
#define SCK_AMUX                   (* (reg8 *) SCK__AMUX) 
/* Bidirectional Enable */                                                        
#define SCK_BIE                    (* (reg8 *) SCK__BIE)
/* Bit-mask for Aliased Register Access */
#define SCK_BIT_MASK               (* (reg8 *) SCK__BIT_MASK)
/* Bypass Enable */
#define SCK_BYP                    (* (reg8 *) SCK__BYP)
/* Port wide control signals */                                                   
#define SCK_CTL                    (* (reg8 *) SCK__CTL)
/* Drive Modes */
#define SCK_DM0                    (* (reg8 *) SCK__DM0) 
#define SCK_DM1                    (* (reg8 *) SCK__DM1)
#define SCK_DM2                    (* (reg8 *) SCK__DM2) 
/* Input Buffer Disable Override */
#define SCK_INP_DIS                (* (reg8 *) SCK__INP_DIS)
/* LCD Common or Segment Drive */
#define SCK_LCD_COM_SEG            (* (reg8 *) SCK__LCD_COM_SEG)
/* Enable Segment LCD */
#define SCK_LCD_EN                 (* (reg8 *) SCK__LCD_EN)
/* Slew Rate Control */
#define SCK_SLW                    (* (reg8 *) SCK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SCK_PRTDSI__CAPS_SEL       (* (reg8 *) SCK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SCK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SCK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SCK_PRTDSI__OE_SEL0        (* (reg8 *) SCK__PRTDSI__OE_SEL0) 
#define SCK_PRTDSI__OE_SEL1        (* (reg8 *) SCK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SCK_PRTDSI__OUT_SEL0       (* (reg8 *) SCK__PRTDSI__OUT_SEL0) 
#define SCK_PRTDSI__OUT_SEL1       (* (reg8 *) SCK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SCK_PRTDSI__SYNC_OUT       (* (reg8 *) SCK__PRTDSI__SYNC_OUT) 


#if defined(SCK__INTSTAT)  /* Interrupt Registers */

    #define SCK_INTSTAT                (* (reg8 *) SCK__INTSTAT)
    #define SCK_SNAP                   (* (reg8 *) SCK__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins SCK_H */

#endif
/* [] END OF FILE */
