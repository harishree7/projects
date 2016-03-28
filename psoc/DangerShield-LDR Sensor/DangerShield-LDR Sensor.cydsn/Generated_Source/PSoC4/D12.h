/*******************************************************************************
* File Name: D12.h  
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

#if !defined(CY_PINS_D12_H) /* Pins D12_H */
#define CY_PINS_D12_H

#include "cytypes.h"
#include "cyfitter.h"
#include "D12_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    D12_Write(uint8 value) ;
void    D12_SetDriveMode(uint8 mode) ;
uint8   D12_ReadDataReg(void) ;
uint8   D12_Read(void) ;
uint8   D12_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define D12_DRIVE_MODE_BITS        (3)
#define D12_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - D12_DRIVE_MODE_BITS))
#define D12_DRIVE_MODE_SHIFT       (0x00u)
#define D12_DRIVE_MODE_MASK        (0x07u << D12_DRIVE_MODE_SHIFT)

#define D12_DM_ALG_HIZ         (0x00u << D12_DRIVE_MODE_SHIFT)
#define D12_DM_DIG_HIZ         (0x01u << D12_DRIVE_MODE_SHIFT)
#define D12_DM_RES_UP          (0x02u << D12_DRIVE_MODE_SHIFT)
#define D12_DM_RES_DWN         (0x03u << D12_DRIVE_MODE_SHIFT)
#define D12_DM_OD_LO           (0x04u << D12_DRIVE_MODE_SHIFT)
#define D12_DM_OD_HI           (0x05u << D12_DRIVE_MODE_SHIFT)
#define D12_DM_STRONG          (0x06u << D12_DRIVE_MODE_SHIFT)
#define D12_DM_RES_UPDWN       (0x07u << D12_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define D12_MASK               D12__MASK
#define D12_SHIFT              D12__SHIFT
#define D12_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define D12_PS                     (* (reg32 *) D12__PS)
/* Port Configuration */
#define D12_PC                     (* (reg32 *) D12__PC)
/* Data Register */
#define D12_DR                     (* (reg32 *) D12__DR)
/* Input Buffer Disable Override */
#define D12_INP_DIS                (* (reg32 *) D12__PC2)


#if defined(D12__INTSTAT)  /* Interrupt Registers */

    #define D12_INTSTAT                (* (reg32 *) D12__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins D12_H */


/* [] END OF FILE */
