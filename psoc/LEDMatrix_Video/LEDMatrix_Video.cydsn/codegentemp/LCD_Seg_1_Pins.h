/*******************************************************************************
* File Name: LCD_Seg_1_Pins.h
* Version 3.40
*
* Description:
*  This header file contains definitions associated with the Segment LCD
*  Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SEGLCD_LCD_Seg_1_PINS_H)
#define CY_SEGLCD_LCD_Seg_1_PINS_H

#include <cypins.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void LCD_Seg_1_SegPort_SetDriveMode(uint8 mode) ;
void LCD_Seg_1_ComPort_SetDriveMode(uint8 mode) ;


/***************************************
*              Constants
***************************************/
#define LCD_Seg_1_DM_ALG_HIZ         (PIN_DM_ALG_HIZ)
#define LCD_Seg_1_DM_DIG_HIZ         (PIN_DM_DIG_HIZ)
#define LCD_Seg_1_DM_RES_UP          (PIN_DM_RES_UP)
#define LCD_Seg_1_DM_RES_DWN         (PIN_DM_RES_DWN)
#define LCD_Seg_1_DM_OD_LO           (PIN_DM_OD_LO)
#define LCD_Seg_1_DM_OD_HI           (PIN_DM_OD_HI)
#define LCD_Seg_1_DM_STRONG          (PIN_DM_STRONG)
#define LCD_Seg_1_DM_RES_UPDWN       (PIN_DM_RES_UPDWN)

#define LCD_Seg_1_SegPort_0            LCD_Seg_1_Seg__0__PC
#define LCD_Seg_1_SegPort_1            LCD_Seg_1_Seg__1__PC
#define LCD_Seg_1_SegPort_2            LCD_Seg_1_Seg__2__PC
#define LCD_Seg_1_SegPort_3            LCD_Seg_1_Seg__3__PC
#define LCD_Seg_1_SegPort_4            LCD_Seg_1_Seg__4__PC
#define LCD_Seg_1_SegPort_5            LCD_Seg_1_Seg__5__PC
#define LCD_Seg_1_SegPort_6            LCD_Seg_1_Seg__6__PC
#define LCD_Seg_1_ComPort_0            LCD_Seg_1_Com__0__PC
#define LCD_Seg_1_ComPort_1            LCD_Seg_1_Com__1__PC
#define LCD_Seg_1_ComPort_2            LCD_Seg_1_Com__2__PC
#define LCD_Seg_1_ComPort_3            LCD_Seg_1_Com__3__PC
#define LCD_Seg_1_ComPort_4            LCD_Seg_1_Com__4__PC


#endif/* CY_SEGLCD_LCD_Seg_1_PINS_H */

/* [] END OF FILE */
