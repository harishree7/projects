#include <Enrf24.h>
//#include <nRF24L01.h>
#include <string.h>
#include <SPI.h>


Enrf24 radio(P2_0, P2_1, P2_2);
const uint8_t rxaddr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0x01 };

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(2,LOW);
  
  //NRF initialize
  
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  
  radio.begin();  // Defaults 1Mbps, channel 0, max TX power

  radio.setRXaddress((void*)rxaddr);   

  radio.enableRX();  // Start listening
}


void loop()
{
//  Serial.print("RECEIVING");
char str1[15];
//String val;
 
 // put your main code here, to run repeatedly:
  
  while (!radio.available(true))
   ;

if(radio.read(str1)){


int j=strlen(str1);  
 pinMode(2,HIGH);


 
 
Serial.print(str1[j-3]);
Serial.println(str1[j-2]);
//Serial.println(strlen(str1));
delay(500);
}
}
