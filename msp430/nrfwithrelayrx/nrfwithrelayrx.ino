#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h>
#include <SPI.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,11);

Enrf24 radio(P2_0, P2_1, P2_2);
const uint8_t rxaddr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0x01 };

const char *str_on = "ON";
const char *str_off = "OFF";

//void dump_radio_status_to_serialport(uint8_t);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);

  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  
  radio.begin();  // Defaults 1Mbps, channel 0, max TX power
  //dump_radio_status_to_serialport(radio.radioState());

  radio.setRXaddress((void*)rxaddr);
  
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
  radio.enableRX();  // Start listening
}

void loop() {
  char inbuf[33];
  
 // dump_radio_status_to_serialport(radio.radioState());  // Should show Receive Mode

  while (!radio.available(true))
    ;
  if (radio.read(inbuf)) {
    //Serial.print("Received packet: ");
    Serial.println(inbuf);

    if (!strcmp(inbuf, str_off))
      {
        lcd.print("RElAY OFF");
      digitalWrite(                                 13, LOW);
      
    }
    if (!strcmp(inbuf, str_on))
    {
      lcd.print("RELAY OFF");
      digitalWrite(P1_0, HIGH);
    }
  }
}
