/*******************************************************************************
* File Name: RST.h  
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

#if !defined(CY_PINS_RST_H) /* Pins RST_H */
#define CY_PINS_RST_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RST_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5 &&\
     CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_5A_PRODUCTION &&\
	 RST__PORT == 15 && (RST__MASK & 0xC0))

/***************************************
*        Function Prototypes             
***************************************/    

void    RST_Write(uint8 value) ;
void    RST_SetDriveMode(uint8 mode) ;
uint8   RST_ReadDataReg(void) ;
uint8   RST_Read(void) ;
uint8   RST_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RST_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RST_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RST_DM_RES_UP          PIN_DM_RES_UP
#define RST_DM_RES_DWN         PIN_DM_RES_DWN
#define RST_DM_OD_LO           PIN_DM_OD_LO
#define RST_DM_OD_HI           PIN_DM_OD_HI
#define RST_DM_STRONG          PIN_DM_STRONG
#define RST_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RST_MASK               RST__MASK
#define RST_SHIFT              RST__SHIFT
#define RST_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RST_PS                     (* (reg8 *) RST__PS)
/* Data Register */
#define RST_DR                     (* (reg8 *) RST__DR)
/* Port Number */
#define RST_PRT_NUM                (* (reg8 *) RST__PRT) 
/* Connect to Analog Globals */                                                  
#define RST_AG                     (* (reg8 *) RST__AG)                       
/* Analog MUX bux enable */
#define RST_AMUX                   (* (reg8 *) RST__AMUX) 
/* Bidirectional Enable */                                                        
#define RST_BIE                    (* (reg8 *) RST__BIE)
/* Bit-mask for Aliased Register Access */
#define RST_BIT_MASK               (* (reg8 *) RST__BIT_MASK)
/* Bypass Enable */
#define RST_BYP                    (* (reg8 *) RST__BYP)
/* Port wide control signals */                                                   
#define RST_CTL                    (* (reg8 *) RST__CTL)
/* Drive Modes */
#define RST_DM0                    (* (reg8 *) RST__DM0) 
#define RST_DM1                    (* (reg8 *) RST__DM1)
#define RST_DM2                    (* (reg8 *) RST__DM2) 
/* Input Buffer Disable Override */
#define RST_INP_DIS                (* (reg8 *) RST__INP_DIS)
/* LCD Common or Segment Drive */
#define RST_LCD_COM_SEG            (* (reg8 *) RST__LCD_COM_SEG)
/* Enable Segment LCD */
#define RST_LCD_EN                 (* (reg8 *) RST__LCD_EN)
/* Slew Rate Control */
#define RST_SLW                    (* (reg8 *) RST__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RST_PRTDSI__CAPS_SEL       (* (reg8 *) RST__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RST_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RST__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RST_PRTDSI__OE_SEL0        (* (reg8 *) RST__PRTDSI__OE_SEL0) 
#define RST_PRTDSI__OE_SEL1        (* (reg8 *) RST__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RST_PRTDSI__OUT_SEL0       (* (reg8 *) RST__PRTDSI__OUT_SEL0) 
#define RST_PRTDSI__OUT_SEL1       (* (reg8 *) RST__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RST_PRTDSI__SYNC_OUT       (* (reg8 *) RST__PRTDSI__SYNC_OUT) 


#if defined(RST__INTSTAT)  /* Interrupt Registers */

    #define RST_INTSTAT                (* (reg8 *) RST__INTSTAT)
    #define RST_SNAP                   (* (reg8 *) RST__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins RST_H */

#endif
/* [] END OF FILE */
