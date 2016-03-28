/*******************************************************************************
* File Name: A3.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_A3_H) /* Pins A3_H */
#define CY_PINS_A3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "A3_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    A3_Write(uint8 value) ;
void    A3_SetDriveMode(uint8 mode) ;
uint8   A3_ReadDataReg(void) ;
uint8   A3_Read(void) ;
uint8   A3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define A3_DRIVE_MODE_BITS        (3)
#define A3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - A3_DRIVE_MODE_BITS))
#define A3_DRIVE_MODE_SHIFT       (0x00u)
#define A3_DRIVE_MODE_MASK        (0x07u << A3_DRIVE_MODE_SHIFT)

#define A3_DM_ALG_HIZ         (0x00u << A3_DRIVE_MODE_SHIFT)
#define A3_DM_DIG_HIZ         (0x01u << A3_DRIVE_MODE_SHIFT)
#define A3_DM_RES_UP          (0x02u << A3_DRIVE_MODE_SHIFT)
#define A3_DM_RES_DWN         (0x03u << A3_DRIVE_MODE_SHIFT)
#define A3_DM_OD_LO           (0x04u << A3_DRIVE_MODE_SHIFT)
#define A3_DM_OD_HI           (0x05u << A3_DRIVE_MODE_SHIFT)
#define A3_DM_STRONG          (0x06u << A3_DRIVE_MODE_SHIFT)
#define A3_DM_RES_UPDWN       (0x07u << A3_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define A3_MASK               A3__MASK
#define A3_SHIFT              A3__SHIFT
#define A3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define A3_PS                     (* (reg32 *) A3__PS)
/* Port Configuration */
#define A3_PC                     (* (reg32 *) A3__PC)
/* Data Register */
#define A3_DR                     (* (reg32 *) A3__DR)
/* Input Buffer Disable Override */
#define A3_INP_DIS                (* (reg32 *) A3__PC2)


#if defined(A3__INTSTAT)  /* Interrupt Registers */

    #define A3_INTSTAT                (* (reg32 *) A3__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins A3_H */


/* [] END OF FILE */
