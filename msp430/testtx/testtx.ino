#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h>
#include <SPI.h>

Enrf24 radio(P2_0, P2_1, P2_2);  // P2.0=CE, P2.1=CSN, P2.2=IRQ
const uint8_t txaddr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0x01 };




void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6,INPUT);

SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
 // pinMode(5,INPUT_PULLUP);

  radio.begin();  // Defaults 1Mbps, channel 0, max TX power
//  dump_radio_status_to_serialport(radio.radioState());

  radio.setTXaddress((void*)txaddr);


}

void loop()
{
  // put your main code here, to run repeatedly:
String str1="*000";
int val=analogRead(6);
String str2= String(val);
String str3=String('#');
String str=(str1+str2+str3);
Serial.println(str);

int i= str.length();
String str4 =String(str.charAt(i-3));
String str5=String(str.charAt(i-2));
String Tx=(str4+str5);
radio.print(str);
radio.flush();
//Serial.println(Tx);
delay(500);
}
