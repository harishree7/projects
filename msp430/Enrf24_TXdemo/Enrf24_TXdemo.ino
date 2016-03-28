#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h>
#include <SPI.h>

Enrf24 radio(P2_0, P2_1, P2_2);  // P2.0=CE, P2.1=CSN, P2.2=IRQ
const uint8_t txaddr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0x01 };

const char *str_on = "ON";
const char *str_off = "OFF";


void setup() {
  Serial.begin(9600);

  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  pinMode(5,INPUT_PULLUP);

  radio.begin();  // Defaults 1Mbps, channel 0, max TX power

  radio.setTXaddress((void*)txaddr);
}

void loop() {
//  Serial.print("Sending packet: ");
  
 
  radio.print(analogRead(3));
  Serial.println(analogRead(3));
  radio.flush();  // Force transmit (don't wait for any more data)
 delay(500);
/* }
 else
 {
  Serial.println(str_on);
  radio.print(str_on);
  radio.flush();  //
  delay(500);

}*/
}
