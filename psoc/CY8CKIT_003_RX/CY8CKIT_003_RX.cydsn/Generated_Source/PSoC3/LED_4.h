/*******************************************************************************
* File Name: LED_4.h  
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

#if !defined(CY_PINS_LED_4_H) /* Pins LED_4_H */
#define CY_PINS_LED_4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LED_4_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED_4_Write(uint8 value) ;
void    LED_4_SetDriveMode(uint8 mode) ;
uint8   LED_4_ReadDataReg(void) ;
uint8   LED_4_Read(void) ;
uint8   LED_4_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED_4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LED_4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LED_4_DM_RES_UP          PIN_DM_RES_UP
#define LED_4_DM_RES_DWN         PIN_DM_RES_DWN
#define LED_4_DM_OD_LO           PIN_DM_OD_LO
#define LED_4_DM_OD_HI           PIN_DM_OD_HI
#define LED_4_DM_STRONG          PIN_DM_STRONG
#define LED_4_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LED_4_MASK               LED_4__MASK
#define LED_4_SHIFT              LED_4__SHIFT
#define LED_4_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED_4_PS                     (* (reg8 *) LED_4__PS)
/* Data Register */
#define LED_4_DR                     (* (reg8 *) LED_4__DR)
/* Port Number */
#define LED_4_PRT_NUM                (* (reg8 *) LED_4__PRT) 
/* Connect to Analog Globals */                                                  
#define LED_4_AG                     (* (reg8 *) LED_4__AG)                       
/* Analog MUX bux enable */
#define LED_4_AMUX                   (* (reg8 *) LED_4__AMUX) 
/* Bidirectional Enable */                                                        
#define LED_4_BIE                    (* (reg8 *) LED_4__BIE)
/* Bit-mask for Aliased Register Access */
#define LED_4_BIT_MASK               (* (reg8 *) LED_4__BIT_MASK)
/* Bypass Enable */
#define LED_4_BYP                    (* (reg8 *) LED_4__BYP)
/* Port wide control signals */                                                   
#define LED_4_CTL                    (* (reg8 *) LED_4__CTL)
/* Drive Modes */
#define LED_4_DM0                    (* (reg8 *) LED_4__DM0) 
#define LED_4_DM1                    (* (reg8 *) LED_4__DM1)
#define LED_4_DM2                    (* (reg8 *) LED_4__DM2) 
/* Input Buffer Disable Override */
#define LED_4_INP_DIS                (* (reg8 *) LED_4__INP_DIS)
/* LCD Common or Segment Drive */
#define LED_4_LCD_COM_SEG            (* (reg8 *) LED_4__LCD_COM_SEG)
/* Enable Segment LCD */
#define LED_4_LCD_EN                 (* (reg8 *) LED_4__LCD_EN)
/* Slew Rate Control */
#define LED_4_SLW                    (* (reg8 *) LED_4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LED_4_PRTDSI__CAPS_SEL       (* (reg8 *) LED_4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LED_4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LED_4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LED_4_PRTDSI__OE_SEL0        (* (reg8 *) LED_4__PRTDSI__OE_SEL0) 
#define LED_4_PRTDSI__OE_SEL1        (* (reg8 *) LED_4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LED_4_PRTDSI__OUT_SEL0       (* (reg8 *) LED_4__PRTDSI__OUT_SEL0) 
#define LED_4_PRTDSI__OUT_SEL1       (* (reg8 *) LED_4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LED_4_PRTDSI__SYNC_OUT       (* (reg8 *) LED_4__PRTDSI__SYNC_OUT) 


#if defined(LED_4__INTSTAT)  /* Interrupt Registers */

    #define LED_4_INTSTAT                (* (reg8 *) LED_4__INTSTAT)
    #define LED_4_SNAP                   (* (reg8 *) LED_4__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins LED_4_H */


/* [] END OF FILE */
