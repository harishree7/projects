/*******************************************************************************
* File Name: LED_7.h  
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

#if !defined(CY_PINS_LED_7_H) /* Pins LED_7_H */
#define CY_PINS_LED_7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LED_7_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED_7_Write(uint8 value) ;
void    LED_7_SetDriveMode(uint8 mode) ;
uint8   LED_7_ReadDataReg(void) ;
uint8   LED_7_Read(void) ;
uint8   LED_7_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED_7_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LED_7_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LED_7_DM_RES_UP          PIN_DM_RES_UP
#define LED_7_DM_RES_DWN         PIN_DM_RES_DWN
#define LED_7_DM_OD_LO           PIN_DM_OD_LO
#define LED_7_DM_OD_HI           PIN_DM_OD_HI
#define LED_7_DM_STRONG          PIN_DM_STRONG
#define LED_7_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LED_7_MASK               LED_7__MASK
#define LED_7_SHIFT              LED_7__SHIFT
#define LED_7_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED_7_PS                     (* (reg8 *) LED_7__PS)
/* Data Register */
#define LED_7_DR                     (* (reg8 *) LED_7__DR)
/* Port Number */
#define LED_7_PRT_NUM                (* (reg8 *) LED_7__PRT) 
/* Connect to Analog Globals */                                                  
#define LED_7_AG                     (* (reg8 *) LED_7__AG)                       
/* Analog MUX bux enable */
#define LED_7_AMUX                   (* (reg8 *) LED_7__AMUX) 
/* Bidirectional Enable */                                                        
#define LED_7_BIE                    (* (reg8 *) LED_7__BIE)
/* Bit-mask for Aliased Register Access */
#define LED_7_BIT_MASK               (* (reg8 *) LED_7__BIT_MASK)
/* Bypass Enable */
#define LED_7_BYP                    (* (reg8 *) LED_7__BYP)
/* Port wide control signals */                                                   
#define LED_7_CTL                    (* (reg8 *) LED_7__CTL)
/* Drive Modes */
#define LED_7_DM0                    (* (reg8 *) LED_7__DM0) 
#define LED_7_DM1                    (* (reg8 *) LED_7__DM1)
#define LED_7_DM2                    (* (reg8 *) LED_7__DM2) 
/* Input Buffer Disable Override */
#define LED_7_INP_DIS                (* (reg8 *) LED_7__INP_DIS)
/* LCD Common or Segment Drive */
#define LED_7_LCD_COM_SEG            (* (reg8 *) LED_7__LCD_COM_SEG)
/* Enable Segment LCD */
#define LED_7_LCD_EN                 (* (reg8 *) LED_7__LCD_EN)
/* Slew Rate Control */
#define LED_7_SLW                    (* (reg8 *) LED_7__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LED_7_PRTDSI__CAPS_SEL       (* (reg8 *) LED_7__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LED_7_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LED_7__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LED_7_PRTDSI__OE_SEL0        (* (reg8 *) LED_7__PRTDSI__OE_SEL0) 
#define LED_7_PRTDSI__OE_SEL1        (* (reg8 *) LED_7__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LED_7_PRTDSI__OUT_SEL0       (* (reg8 *) LED_7__PRTDSI__OUT_SEL0) 
#define LED_7_PRTDSI__OUT_SEL1       (* (reg8 *) LED_7__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LED_7_PRTDSI__SYNC_OUT       (* (reg8 *) LED_7__PRTDSI__SYNC_OUT) 


#if defined(LED_7__INTSTAT)  /* Interrupt Registers */

    #define LED_7_INTSTAT                (* (reg8 *) LED_7__INTSTAT)
    #define LED_7_SNAP                   (* (reg8 *) LED_7__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins LED_7_H */


/* [] END OF FILE */
