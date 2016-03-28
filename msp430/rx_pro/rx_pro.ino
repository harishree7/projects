/************************************************
      Receiving data through nRF
*************************************************/

#include<Enrf24.h>
#include<nRF24L01.h>
#include<string.h>
#include<SPI.h>

Enrf24 radio(P2_0, P2_1,P2_2);  //CE,CSN,IRQ respectively
const uint8_t rxaddr[]={0xDE, 0xAD, 0xBE, 0xEF,0x01};


void setup()
{
  Serial.begin(9600);
  
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  
  radio.begin();
  radio.setRXaddress((void*)rxaddr);
  
  radio.enableRX();
  // put your setup code here, to run once:
  
}

void loop()
{
  char data[33];
  if(radio.read(data)){
    Serial.print("Received from :");
    Serial.println(data);
    delay(1000);
  }
  
  // put your main code here, to run repeatedly:
  
}
