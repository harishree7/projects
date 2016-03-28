// Reeceive the data from bluetooth printit in serial communication and LCD display first row

#include <SoftwareSerial.h>// import the serial library
#include<LiquidCrystal.h> //LCD INTERFACE
SoftwareSerial hari(6,7); //7- RX,6- TX
int ledpin=2; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer
LiquidCrystal lcd(P2_0, P2_1, P2_2, P2_3, P2_4, P2_5); // LCD PIN : RS,E,D4,D5,D6,D7 Respectively
int count=0;


void setup() {
  // put your setup code here, to run once:
  hari.begin(9600);
  Serial.begin(9600);

  hari.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT);
  pinMode(5,INPUT_PULLUP);
  
  lcd.begin(16,1);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

char val[15];

if (digitalRead(5)==0)
{
lcd.clear();
count=0;
//lcd.setCursor(0,1);
if(digitalRead(5)==HIGH)
{
hari.println("Display Cleared");  //hardware button on launch pad to clear lcd
}
}



   if (hari.available()){
BluetoothData=hari.read();
//sprintf(val,"%c",BluetoothData);
//Serial.print();
int j = sizeof(BluetoothData);
Serial.write(j);

if(count!=16)
{
lcd.write(BluetoothData);
count=count+1;
delay(10);
}
else
{
  lcd.setCursor(0,1);
  count=1;
  lcd.write(BluetoothData);
}
/*

//press 1 to led on and 0 to led off

   if(BluetoothData=='1'){   // if number 1 pressed ....
   digitalWrite(ledpin,1);
  Genotronex.println("LED  On D13 ON ! ");
  lcd.clear();
  lcd.print("LED ON");
   }
  if (BluetoothData=='0'){// if number 0 pressed ....
  digitalWrite(ledpin,0);
   Genotronex.println("LED  On D13 Off ! ");
  lcd.clear();
   lcd.print("LED OFF");
  }*/
}
//delay(100);// prepare for next data ...
}
