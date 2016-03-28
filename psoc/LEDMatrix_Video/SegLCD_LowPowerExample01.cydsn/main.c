/*******************************************************************************
* File Name: main.c
*
* Version: 4.0
*
* Description:
*  This is source code for SegLCD_LowPowerExamle Example project.
*
*  This example project demonstrates:
*   - Component Low power mode usage (using 1K ILO)
*   - 14 Segment helper operation.
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <device.h>
#include <cyPm.h>


uint8 str[44u] = "     LCD LOW POWER UPDATE SEQUENCE WORKING \0";
uint8 strRet[8u];


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  1. Starts Segment LCD component.
*  2. Generates and outputs a "running" string to be displayed on the 14 Segment
*     portion of LCD.
*  3. Puts the chip into the Sleep mode and wait for the wakeup from SegLCD 
*     Timer.     
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
int main()
{
    uint8 position = 0u;
    uint16 delayCnt = 0u;

    CyGlobalIntEnable;  /* Enable global interrupts. */
    
    (void) LCD_Start();
    LCD_EnableInt();
    
    for(;;)
    {  

        /* This if() ... else stratement implements a delay */
        if(delayCnt == 550u)
        {
            delayCnt = 0u;
                         
            if(position != 42u)       
            {
                /* This will be the position in the string from which the
                * current chunk will begin. 
                */
                position++;
            }
            else
            {
                position = 0u;
            }
            
            /* memcpy() used to create running string */
            memcpy(strRet, &str[position], 8u);
            
            /* LCD_WriteString14Seg_2() will display the running string */    
            LCD_WriteString14Seg_2(strRet, 0u);
        }
        else
        {
            delayCnt++;
        }
        
        /* Put the part into a Sleep mode, the LCD Timer will wake up the device. */
        CyPmSleep(PM_SLEEP_TIME_NONE, PM_SLEEP_SRC_LCD);
    }
}


/* [] END OF FILE */
