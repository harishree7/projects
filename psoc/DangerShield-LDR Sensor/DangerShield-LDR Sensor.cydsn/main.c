/******************************************************************************
* Project Name		: DangerShield-LDR Sensor
* File Name			: main.c
* Version 			: 1.0
* Device Used		: CY8C4245AXI-483
* Software Used		: PSoC Creator 2.2 SP1
* Compiler    		: ARMGCC 4.4.1
* Related Hardware	: CY8CKIT-042 PSoC 4 Pioneer Kit 
*
******************************************************************************
* ========================================
*
The following firmware was developed by Cypress Semiconductor
This work is licensed under a Creative Commons Attribution 3.0 Unported License.
http://creativecommons.org/licenses/by/3.0/deed.en_US
You are free to:
-To Share — to copy, distribute and transmit the work 
-To Remix — to adapt the work 
-To make commercial use of the work
* ========================================
*
******************************************************************************
*                           THEORY OF OPERATION
* This project demonstrates the use of the LDR light sensor on the SparkFun.com
* Danger Shield. Additionally, this project also uses the D12 digital switch to 
* run a calibration routine and then uses the D5 and D6 LED outputs to indicate
* the light intensity measured (high or low). Further, a UART interface communicates
* status and debug messages across the USB-UART bridge available on the PSoC 4 Pioneer
* Kit.
* 
* UART is configured with
* UART Basic
* 	Mode: Standard
* 	Direction: TX+RX
* 	Baud rate (kbps): 9600
* 	Data bits: 8 bits
* 	Parity: None
* 	Stop bits: 1 bit
* 	Physical connections needed:
* 	TX: Jumper between P0[5] and PSoC 5LP Header J8 P12[6]
*	RX: Jumper between P0[4] and PSoC 5LP Header J8 P12[7]
*
* UART Advanced
* 	RX buffer size: 8
* 	TX buffer size: 8
* 	Interrupt: None
*
* Physical Connetion
* Connect jumper wire from the UART RX (P0[4]) of PSoC 4 to J8_10 (P12[7]) of PSoC 5LP
* Connect jumper wire from the UART TX (P0[5]) of PSoC 4 to J8_9 (P12[6]) of PSoC 5LP
*
* SparkFun Danger Shield (https://www.sparkfun.com/products/10570)
* The SparkFun Danger Shield is configured as detailed on the SparkFun product page.
* The Danger Shield then simply connects using the standard Arduino headers on the 
* PSoC 4 Pioneer Kit.
* ******************************************************************************/ 
#include <device.h>

#define LOOPDELAY 500 //Imposed delay (in msec) for the main loop 

// Function prototype for converting an Integer to a string for the UART Debug interface
char * intString(char * str,  int16  num);

// Required for the Integer to String conversion routine
char hex[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};


//
// Main application
//

void main()
{   
	uint16 LDR_Low = 0; //Low mV calibration variable
	uint16 LDR_High = 0; //High mV calibration variable
	char tmpstr[32];  // Working string buffer for UART print string functions
	uint8 buttonstate = 0; //Digital switch variable for monitoring the D12 switch

	//Start the D12 switch debouncer clock peripheral
	Switch_Clock_Start();
	
	//Start the ADC peripheral and begin conversions
	ADC_SAR_Seq_1_Start();
	ADC_SAR_Seq_1_StartConvert();
	
    // Start SCB UART TX+RX operation    
    UART_Start(); 
    
	// Transmit String through UART TX Line
	UART_UartPutString("Danger Shield: LDR Sensor Project");
	UART_UartPutCRLF(0);
	
	//***********************
	// LDR calibration routine
	//
	// Theory of operation:
	// This section of the main application code calibrates two light levels: low and high
	// The D12 switch is used to set the calibration levels and the Yellow and Red LEDs indicate
	// which mode is currently under calibration. Additionally, UART outputs provide additional 
	// data regarding the current state and values measured during the calibration routine.
	//
	// The first calibration step is for the low light value with a blinking Red LED as an indicator.
	//
	// The second calibration step is for the high light value with a blinking Yellow LED as an indicator. 
	//
	//***********************
	
	//Begin low light calibration
	
	//Until we get a button press, signify we're in low calibration mode--blink the red LED
	UART_UartPutString("Calibrating LDR Sensor: low light");
	D5_Yellow_Write(0); //Turn off the Yellow LED
	while (!(buttonstate=D12_Button_State_Read())) { //Waiting for the D12 button press
		D6_Red_Write(1); //Turn on the Red LED
		CyDelay(100); //100msec delay 
		D6_Red_Write(0); //Turn off the Red LED
	}
	
	//Once the button is pressed, wait for the ADC conversion to complete and capture the low light calibration value
	if (ADC_SAR_Seq_1_IsEndConversion(ADC_SAR_Seq_1_WAIT_FOR_RESULT)) {
		LDR_Low = ADC_SAR_Seq_1_CountsTo_mVolts(0,ADC_SAR_Seq_1_GetResult16(0));
	}
	
	//UART outputs for debug messages
	intString(tmpstr,LDR_Low); //Convert the low light value to a string
	UART_UartPutString(": ");
	UART_UartPutString(tmpstr); //Output the low light value through the UART interface
	UART_UartPutCRLF(0); //Carriage return
	
	//End low light calibration
	
	//Begin bright light calibration
	
	//Until we get a button press, signify we're in low calibration mode--blink the yellow LED
	UART_UartPutString("Calibrating LDR Sensor: bright light");
	D6_Red_Write(0); //Turn off the Red LED
	while (!(buttonstate=D12_Button_State_Read())) { //Waiting for the D12 button press
		D5_Yellow_Write(1); //Turn on the Yellow LED
		CyDelay(100); //100msec delay
		D5_Yellow_Write(0); //Turn off the Yellow LED
	}
	
	//Once the button is pressed, wait for the ADC conversion to complete and capture the bright light calibration value
	if (ADC_SAR_Seq_1_IsEndConversion(ADC_SAR_Seq_1_WAIT_FOR_RESULT)) {
		LDR_High = ADC_SAR_Seq_1_CountsTo_mVolts(0,ADC_SAR_Seq_1_GetResult16(0));
	} 
	
	//UART outputs for debug messages
	intString(tmpstr,LDR_High); //Convert the bright light value to a string
	UART_UartPutString(": ");
	UART_UartPutString(tmpstr); //Output the bright light value through the UART interface
	UART_UartPutCRLF(0); //Carriage return

	//End bright light calibration
	
	//End LDR calibration
	
	
	// Main application loop
	
    for(;;)
    {
		uint16 LDR_Result = 0; //Local variable for capturing the current LDR Sensor value
		
		//Wait for the ADC conversion to complete and capture the current LDR sensor value
		if (ADC_SAR_Seq_1_IsEndConversion(ADC_SAR_Seq_1_WAIT_FOR_RESULT)) {
			LDR_Result = ADC_SAR_Seq_1_CountsTo_mVolts(0,ADC_SAR_Seq_1_GetResult16(0));
		}
		
		//UART outputs for debug messages
		UART_UartPutString("LDR Result: ");
		intString(tmpstr,LDR_Result); //Conver the current LDR sensor value to a string
		UART_UartPutString(tmpstr); //Output the sensor value through the UART interface
		
		//Determine if the LDR sensor value is more bright or low
		if (LDR_Result>=(((LDR_High-LDR_Low)/2)+LDR_Low)) { //If the LDR sensor detects more bright light than low light

			//Indicate bright light detected--turn on the Red LED and output the debug message through the UART interface
			D6_Red_Write(1); //Turn on the red LED
			D5_Yellow_Write(0); //Turn off the yellow LED
			UART_UartPutString(": Bright Light Detected"); //Output the result to the UART interface
			
		} else {
		
			//Indicate low light detected--turn on the Yellow LED and output the debug message through the UART interface 
			D6_Red_Write(0); //Turn off the red LED
			D5_Yellow_Write(1); //Turn on the yellow LED
			UART_UartPutString(": Low Light Detected"); //Output the result to the UART interface
		}
		
		UART_UartPutCRLF(0); //Carriage return

		CyDelay(LOOPDELAY); //Delay the main loop (in msec)
        
    }
}

//
// intString Function
//
// This function converts a signed 16-bit value to an ASCII string
// 
// Inputs: 
//   char *str: Pointer to the start of the character array with reserved memory to store the result
//   int16 num: 16bit signed integer to be converted
//
// Returns: Pointer to the start of the character array with the stored result
// 	 

char * intString(char * str, int16  num)
{

	//Local variables for the intString function
    int16  value;
    int16  mag = 10000;
    int16  cnt;
    int16  digit;
    
	//Prepend a negative or positive sign to the string return value 
    if(num < 0) {
        value = -num;
        str[0] = '-';
    } else {
        value = (int32)num;
        str[0] = '+';
    }
     
    //Loop throught the 6 possible characters in the return string and place the 
	//character values for each numerical value one place at a time.
    for(cnt = 0; cnt < 6; cnt++) {
        digit = value/mag; 
        str[cnt+1] = hex[digit];
        value = value - (mag*digit);
        mag = mag/10;
    }

	str[6] = 0u; //null string output to indicate the end of the string
    return(str); //return the pointer to the start of the character array
}