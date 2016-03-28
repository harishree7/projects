#include<SoftwareSerial.h>

SoftwareSerial hari(0,1);

void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(13,OUTPUT);

Serial.begin(9600);
hari.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//int val=analogRead(A0);

hari.println();

}
