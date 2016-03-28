//#include<SoftwareSerial.h>
//SoftwareSerial hari(1,);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int i=Serial.read();
Serial.write(i);
}
