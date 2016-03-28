/*******************************************************************************
* File Name: D6_Red.h  
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

#if !defined(CY_PINS_D6_Red_H) /* Pins D6_Red_H */
#define CY_PINS_D6_Red_H

#include "cytypes.h"
#include "cyfitter.h"
#include "D6_Red_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    D6_Red_Write(uint8 value) ;
void    D6_Red_SetDriveMode(uint8 mode) ;
uint8   D6_Red_ReadDataReg(void) ;
uint8   D6_Red_Read(void) ;
uint8   D6_Red_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define D6_Red_DRIVE_MODE_BITS        (3)
#define D6_Red_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - D6_Red_DRIVE_MODE_BITS))
#define D6_Red_DRIVE_MODE_SHIFT       (0x00u)
#define D6_Red_DRIVE_MODE_MASK        (0x07u << D6_Red_DRIVE_MODE_SHIFT)

#define D6_Red_DM_ALG_HIZ         (0x00u << D6_Red_DRIVE_MODE_SHIFT)
#define D6_Red_DM_DIG_HIZ         (0x01u << D6_Red_DRIVE_MODE_SHIFT)
#define D6_Red_DM_RES_UP          (0x02u << D6_Red_DRIVE_MODE_SHIFT)
#define D6_Red_DM_RES_DWN         (0x03u << D6_Red_DRIVE_MODE_SHIFT)
#define D6_Red_DM_OD_LO           (0x04u << D6_Red_DRIVE_MODE_SHIFT)
#define D6_Red_DM_OD_HI           (0x05u << D6_Red_DRIVE_MODE_SHIFT)
#define D6_Red_DM_STRONG          (0x06u << D6_Red_DRIVE_MODE_SHIFT)
#define D6_Red_DM_RES_UPDWN       (0x07u << D6_Red_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define D6_Red_MASK               D6_Red__MASK
#define D6_Red_SHIFT              D6_Red__SHIFT
#define D6_Red_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define D6_Red_PS                     (* (reg32 *) D6_Red__PS)
/* Port Configuration */
#define D6_Red_PC                     (* (reg32 *) D6_Red__PC)
/* Data Register */
#define D6_Red_DR                     (* (reg32 *) D6_Red__DR)
/* Input Buffer Disable Override */
#define D6_Red_INP_DIS                (* (reg32 *) D6_Red__PC2)


#if defined(D6_Red__INTSTAT)  /* Interrupt Registers */

    #define D6_Red_INTSTAT                (* (reg32 *) D6_Red__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins D6_Red_H */


/* [] END OF FILE */
