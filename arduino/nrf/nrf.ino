#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h>
#include <SPI.h>
#include<LiquidCrystal.h>
#include<SoftwareSerial.h>

SoftwareSerial myserial(A8,A9);
LiquidCrystal lcd(A1,A0,A2,A3,A4,A5);
int count=0, data;

Enrf24 radio(2,3,4);  // P2.0=CE, P2.1=CSN, P2.2=IRQ
const uint8_t txaddr[] = {0xDE, 0xAD, 0xBE, 0xEF, 0x01 };

const char *str_on = "ON";
const char *str_off = "OFF";

void setup() {

  Serial.begin(9600);
myserial.begin(9600);
  lcd.begin(16,2);

  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);

  radio.begin();  // Defaults 1Mbps, channel 0, max TX power

  radio.setTXaddress((void*)txaddr);
}

void loop() {
  if(myserial.available())
  {
 int val=myserial.read();
  if(val=='1')
  {
  Serial1.print("Sending packet: ");
  Serial1.println(str_on);
  radio.print(str_on);
  lcd.clear();
  lcd.write(str_on);
  radio.flush();  // Force transmit (don't wait for any more data)
  //delay(1000);
  }
  if(val=='0')
  {
  Serial1.print("Sending packet: ");
  Serial1.println(str_off);
  radio.print(str_off);
  lcd.clear();
  lcd.write(str_off);
  radio.flush();  //
  //delay(1000);
  }
}
}
