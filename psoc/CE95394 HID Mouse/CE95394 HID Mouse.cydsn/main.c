/******************************************************************************
* Project Name		: CE95394 HID Mouse
* File Name			: main.c
* Version 			: **
* Device Used		: CY8C5888LTI-LP097
* Software Used		: PSoC Creator 3.1 SP2
* Compiler    		: ARM GCC 4.8.4, ARM RVDS Generic, ARM MDK Generic
* Related Hardware	: CY8CKIT059 PSoC 5 LP Prototyping Kit 
* Owner				: KLMZ
*
********************************************************************************
* Copyright (2015), Cypress Semiconductor Corporation. All Rights Reserved.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress)
* and is protected by and subject to worldwide patent protection (United
* States and foreign), United States copyright laws and international treaty
* provisions. Cypress hereby grants to licensee a personal, non-exclusive,
* non-transferable license to copy, use, modify, create derivative works of,
* and compile the Cypress Source Code and derivative works for the sole
* purpose of creating custom software in support of licensee product to be
* used only in conjunction with a Cypress integrated circuit as specified in
* the applicable agreement. Any reproduction, modification, translation,
* compilation, or representation of this software except as specified above 
* is prohibited without the express written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH 
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the 
* materials described herein. Cypress does not assume any liability arising out 
* of the application or use of any product or circuit described herein. Cypress 
* does not authorize its products for use as critical components in life-support 
* systems where a malfunction or failure may reasonably be expected to result in 
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of 
* such use and in doing so indemnifies Cypress against all charges. 
*
* Use of this Software may be limited by and subject to the applicable Cypress
* software license agreement. 
*******************************************************************************/


#include <device.h>

static int8 Mouse_Data[3] = {0, 0, 0}; /* [0] = Buttons, [1] = X-Axis, [2] = Y-Axis */
static uint16 Delay = 0;

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  main() performs following functions:
*  1: Enumerates the PSoC as a HID Mouse.
*  2: Updates Mouse movement data.
*  3: Updates Mouse left click with status of P2[2]
*  4: Waits for ACK from host and then loads new data into EP1.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/

void main()
{
	CYGlobalIntEnable;                        		/* Enable Global Interrupts */
	USBFS_1_Start(0, USBFS_1_DWR_VDDD_OPERATION);   /* Start USBFS Operation/device 0 and with 5V operation */ 	
	while(!USBFS_1_bGetConfiguration());      		/* Wait for Device to enumerate */
    USBFS_1_LoadInEP(1, (uint8 *)Mouse_Data, 3); 	/* Loads an inital value into EP1 and sends it out to the PC */
	
	for(;;)
    {
        while(!USBFS_1_bGetEPAckState(1));  			/* Wait for ACK before loading data */
		USBFS_1_LoadInEP(1, (uint8 *)Mouse_Data, 3); 	/* Load latest mouse data into EP1 and send to PC */
	  
		switch (Delay){									/* Switch statement creates a state machine for mouse movement */
			case 128:	
                Mouse_Data[1] = 5;  			/* Moves mouse to right */
				Mouse_Data[2] = 0;  			/* Keeps Y static */
				break;
			case 256:	
                Mouse_Data[1] = 0; 				/* Keeps X static */
				Mouse_Data[2] = 5; 				/* Moves mouse down */
				break;
			case 384:	
                Mouse_Data[1] = -5; 			/* Moves mouse to left */
				Mouse_Data[2] = 0;  			/* Keeps Y static */
				break;
			case 512:	
                Mouse_Data[1] = 0;  			/* Keeps X static */
			    Mouse_Data[2] = -5; 			/* Moves mouse up */
				Delay=0;
				break;  
			default:	
                break;  
        }
        
        if(Button_1_Read() == 0)    /* Check the button state and load the report with the curren status */
        {
            Mouse_Data[0] = 0x01;   /* Report button 1 is pressed */
        }
        else
        {
            Mouse_Data[0] = 0x00;   /* Report button 1 is not pressed */
        }
        
		Delay++;
	}
}
/* End of File */


