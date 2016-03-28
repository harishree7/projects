#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h>
#include <SPI.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(3,4,5,11,12,13);


Enrf24 radio(P2_0, P2_1, P2_2);
const uint8_t rxaddr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0x01 };

const char *str_on = "ON";
const char *str_off = "OFF";

//void dump_radio_status_to_serialport(uint8_t);

void setup() {
  lcd.begin(16,1);
 // Serial.begin(9600);
  
  lcd.clear();
  lcd.print("RECEIVING...");
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  
  radio.begin();  // Defaults 1Mbps, channel 0, max TX power
  //dump_radio_status_to_serialport(radio.radioState());

  radio.setRXaddress((void*)rxaddr);
  
  pinMode(2, OUTPUT);
  digitalWrite(P1_0, LOW);
  
  radio.enableRX();  // Start listeningn9
}

void loop() {
  char inbuf[33];
  
 // dump_radio_status_to_serialport(radio.radioState());  // Should show Receive Mode

  while (!radio.available(true))
    ;
  if (radio.read(inbuf)) {
    //Serial.print("Received packet: ");
  //  Serial.println(inbuf);

   // if (!strcmp(inbuf, str_off))
   // {
  //    lcd.clear();
 //  lcd.write(inbuf);
   
   
   int val=atoi(inbuf);
   
   if(val>400)
   {
     digitalWrite(2,LOW);
     lcd.clear();
     lcd.write("LED OFF");
   }
   else
   {
     digitalWrite(2,HIGH);
      lcd.clear();
      lcd.write("LED ON");

   }
    //   Serial.println(val);
   /* //  digitalWrite(P1_0, LOW);
    }
    if (!strcmp(inbuf, str_on))
     {
      lcd.clear();
    lcd.print("LED ON");
       digitalWrite(P1_0, HIGH);
     }*/
  }
}

