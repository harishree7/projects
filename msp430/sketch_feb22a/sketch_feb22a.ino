#include<SoftwareSerial.h>

SoftwareSerial hari(3,4);
void setup()
{
 hari.begin(9600);
pinMode(5,INPUT_PULLUP);
  // put your setup code here, to run once:
  
}

void loop()
{
  hari.write("*+000");
  hari.print(analogRead(5));
  hari.write("#");
  hari.println();
  delay(500);
  // put your main code here, to run repeatedly:
  
}
