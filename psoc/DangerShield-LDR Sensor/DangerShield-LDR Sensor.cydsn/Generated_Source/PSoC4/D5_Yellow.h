/*******************************************************************************
* File Name: D5_Yellow.h  
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

#if !defined(CY_PINS_D5_Yellow_H) /* Pins D5_Yellow_H */
#define CY_PINS_D5_Yellow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "D5_Yellow_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    D5_Yellow_Write(uint8 value) ;
void    D5_Yellow_SetDriveMode(uint8 mode) ;
uint8   D5_Yellow_ReadDataReg(void) ;
uint8   D5_Yellow_Read(void) ;
uint8   D5_Yellow_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define D5_Yellow_DRIVE_MODE_BITS        (3)
#define D5_Yellow_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - D5_Yellow_DRIVE_MODE_BITS))
#define D5_Yellow_DRIVE_MODE_SHIFT       (0x00u)
#define D5_Yellow_DRIVE_MODE_MASK        (0x07u << D5_Yellow_DRIVE_MODE_SHIFT)

#define D5_Yellow_DM_ALG_HIZ         (0x00u << D5_Yellow_DRIVE_MODE_SHIFT)
#define D5_Yellow_DM_DIG_HIZ         (0x01u << D5_Yellow_DRIVE_MODE_SHIFT)
#define D5_Yellow_DM_RES_UP          (0x02u << D5_Yellow_DRIVE_MODE_SHIFT)
#define D5_Yellow_DM_RES_DWN         (0x03u << D5_Yellow_DRIVE_MODE_SHIFT)
#define D5_Yellow_DM_OD_LO           (0x04u << D5_Yellow_DRIVE_MODE_SHIFT)
#define D5_Yellow_DM_OD_HI           (0x05u << D5_Yellow_DRIVE_MODE_SHIFT)
#define D5_Yellow_DM_STRONG          (0x06u << D5_Yellow_DRIVE_MODE_SHIFT)
#define D5_Yellow_DM_RES_UPDWN       (0x07u << D5_Yellow_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define D5_Yellow_MASK               D5_Yellow__MASK
#define D5_Yellow_SHIFT              D5_Yellow__SHIFT
#define D5_Yellow_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define D5_Yellow_PS                     (* (reg32 *) D5_Yellow__PS)
/* Port Configuration */
#define D5_Yellow_PC                     (* (reg32 *) D5_Yellow__PC)
/* Data Register */
#define D5_Yellow_DR                     (* (reg32 *) D5_Yellow__DR)
/* Input Buffer Disable Override */
#define D5_Yellow_INP_DIS                (* (reg32 *) D5_Yellow__PC2)


#if defined(D5_Yellow__INTSTAT)  /* Interrupt Registers */

    #define D5_Yellow_INTSTAT                (* (reg32 *) D5_Yellow__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins D5_Yellow_H */


/* [] END OF FILE */
