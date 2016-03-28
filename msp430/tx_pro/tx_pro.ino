/***********************************************************
        Transmitting data through nRF module
************************************************************/

        
#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h>
#include <SPI.h>

Enrf24 radio(P2_0, P2_1, P2_2);   //CE, CSN, IRQ Respectively
const uint8_t txaddr[]={0xDE,0xAD,0xBE, 0xEF, 0x01};
void setup()
{
  Serial.begin(9600);
  
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  
  radio.begin();      //Defaults 1Mbps, Channel 0,Max Tx Power
  
  radio.setTXaddress((void*)txaddr);
  // put your setup code here, to run once:
  
  pinMode(3,INPUT);        //CHK pin
  pinMode(4,INPUT);
  
}

void loop()
{
  if(digitalRead(3)==HIGH)
  {
    /*transmit the Sensor one value */
    radio.print("1");
    radio.println(analogRead(4));
    delay(1000);
  }
  else
  {
    //transmit Sensor two value
    radio.print("1");
    radio.println(analogRead(4));
    delay(1000);  
}
  
  // put your main code here, to run repeatedly:
  
}
