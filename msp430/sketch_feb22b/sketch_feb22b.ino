#include<SoftwareSerial.h>

SoftwareSerial hari(3,4);
void setup()
{
  hari.begin(9600);
  
  // put your setup code here, to run once:
  
}

void loop()
{
//  int i=hari.read();
  hari.write("print");
//  hari.write(i);
  // put your main code here, to run repeatedly:
  
}
