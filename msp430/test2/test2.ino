
#include <SoftwareSerial.h>// import the serial library
SoftwareSerial hari(6,7); //7- RX,6- TX

void setup()  {
  
 hari.begin(9600);
 Serial.begin(9600);
}

void loop() {  
//hari.println("*+000123#");

int j= hari.read();

  Serial.write(j);
delay(50);
}
