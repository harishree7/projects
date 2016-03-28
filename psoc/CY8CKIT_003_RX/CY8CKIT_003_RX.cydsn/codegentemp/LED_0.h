/*******************************************************************************
* File Name: LED_0.h  
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

#if !defined(CY_PINS_LED_0_H) /* Pins LED_0_H */
#define CY_PINS_LED_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LED_0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED_0_Write(uint8 value) ;
void    LED_0_SetDriveMode(uint8 mode) ;
uint8   LED_0_ReadDataReg(void) ;
uint8   LED_0_Read(void) ;
uint8   LED_0_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED_0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LED_0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LED_0_DM_RES_UP          PIN_DM_RES_UP
#define LED_0_DM_RES_DWN         PIN_DM_RES_DWN
#define LED_0_DM_OD_LO           PIN_DM_OD_LO
#define LED_0_DM_OD_HI           PIN_DM_OD_HI
#define LED_0_DM_STRONG          PIN_DM_STRONG
#define LED_0_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LED_0_MASK               LED_0__MASK
#define LED_0_SHIFT              LED_0__SHIFT
#define LED_0_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED_0_PS                     (* (reg8 *) LED_0__PS)
/* Data Register */
#define LED_0_DR                     (* (reg8 *) LED_0__DR)
/* Port Number */
#define LED_0_PRT_NUM                (* (reg8 *) LED_0__PRT) 
/* Connect to Analog Globals */                                                  
#define LED_0_AG                     (* (reg8 *) LED_0__AG)                       
/* Analog MUX bux enable */
#define LED_0_AMUX                   (* (reg8 *) LED_0__AMUX) 
/* Bidirectional Enable */                                                        
#define LED_0_BIE                    (* (reg8 *) LED_0__BIE)
/* Bit-mask for Aliased Register Access */
#define LED_0_BIT_MASK               (* (reg8 *) LED_0__BIT_MASK)
/* Bypass Enable */
#define LED_0_BYP                    (* (reg8 *) LED_0__BYP)
/* Port wide control signals */                                                   
#define LED_0_CTL                    (* (reg8 *) LED_0__CTL)
/* Drive Modes */
#define LED_0_DM0                    (* (reg8 *) LED_0__DM0) 
#define LED_0_DM1                    (* (reg8 *) LED_0__DM1)
#define LED_0_DM2                    (* (reg8 *) LED_0__DM2) 
/* Input Buffer Disable Override */
#define LED_0_INP_DIS                (* (reg8 *) LED_0__INP_DIS)
/* LCD Common or Segment Drive */
#define LED_0_LCD_COM_SEG            (* (reg8 *) LED_0__LCD_COM_SEG)
/* Enable Segment LCD */
#define LED_0_LCD_EN                 (* (reg8 *) LED_0__LCD_EN)
/* Slew Rate Control */
#define LED_0_SLW                    (* (reg8 *) LED_0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LED_0_PRTDSI__CAPS_SEL       (* (reg8 *) LED_0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LED_0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LED_0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LED_0_PRTDSI__OE_SEL0        (* (reg8 *) LED_0__PRTDSI__OE_SEL0) 
#define LED_0_PRTDSI__OE_SEL1        (* (reg8 *) LED_0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LED_0_PRTDSI__OUT_SEL0       (* (reg8 *) LED_0__PRTDSI__OUT_SEL0) 
#define LED_0_PRTDSI__OUT_SEL1       (* (reg8 *) LED_0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LED_0_PRTDSI__SYNC_OUT       (* (reg8 *) LED_0__PRTDSI__SYNC_OUT) 


#if defined(LED_0__INTSTAT)  /* Interrupt Registers */

    #define LED_0_INTSTAT                (* (reg8 *) LED_0__INTSTAT)
    #define LED_0_SNAP                   (* (reg8 *) LED_0__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins LED_0_H */


/* [] END OF FILE */
