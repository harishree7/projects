#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);

int bluetoothTx = 6; // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 7; // RX-I pin of bluetooth mate, Arduino D3
 
int led = 2;
 
int buttonPin1 = 5;
int buttonPin2 = 3;
int button1State = 0;
int button2State = 0;
 
int dataFromBt;
 
boolean lightBlink = false;
 
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
 
void setup()
{
 Serial.begin(9600); // Begin the serial monitor at 9600bps
 lcd.begin(16,1);
 lcd.print("Bluetooth");
 bluetooth.begin(115200); // The Bluetooth Mate defaults to 115200bps
 bluetooth.print("$"); // Print three times individually
 bluetooth.print("$");
 bluetooth.print("$"); // Enter command mode
 delay(100); // Short delay, wait for the Mate to send back CMD
 bluetooth.println("U,9600,N"); // Temporarily Change the baudrate to 9600, no parity
 // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
 bluetooth.begin(9600); // Start bluetooth serial at 9600
 pinMode(led, OUTPUT);
 pinMode(buttonPin1, INPUT_PULLUP);
 pinMode(buttonPin2, INPUT);
}
 
void loop()
{
 
 if(bluetooth.available()) // If the bluetooth sent any characters
 {
 // Send any characters the bluetooth prints to the serial monitor
 //Serial.println((char)bluetooth.read());
 
 dataFromBt = bluetooth.read();
 
 if(dataFromBt == '1'){
 Serial.println("led on");
 digitalWrite(led, HIGH);
 bluetooth.print("1");
 lcd.clear();
 lcd.print("ON");
 }
 if(dataFromBt == '0'){
 Serial.println("led off");
 digitalWrite(led, LOW);
 bluetooth.print("0");
 lcd.clear();
 lcd.print("OFF");
 }
 if(dataFromBt == 'b'){
 Serial.println("a");
 lightBlink = true;
 }else{
 lightBlink = false;
 }
 
 }
 if(digitalRead(5)==LOW)
 {
   lightBlink=false;
   bluetooth.print("1");
   Serial.println("led on");
   digitalWrite(led,HIGH);
   lcd.clear();
   lcd.print("on");
 }
 
 if(Serial.available()) // If stuff was typed in the serial monitor
 {
 // Send any characters the Serial monitor prints to the bluetooth
 bluetooth.print((char)Serial.read());
 }
 
 // and loop forever and ever!
 if(lightBlink){
 digitalWrite(led, HIGH);
 bluetooth.print("1");
 Serial.println("HIGH");
 lcd.clear();
 lcd.print("ON");
 delay(500);
 digitalWrite(led, LOW);
 bluetooth.print("0");
 Serial.println("LOW");
 lcd.clear();
 lcd.print("OFF");
 delay(500);
 }
}
  
