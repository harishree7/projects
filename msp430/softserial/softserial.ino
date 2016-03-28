/*
  Software serial multple serial test
 
 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.
 
 The circuit: 
 * RX is digital pin P1.4 (connect to TX of other device)
 * TX is digital pin P1.3 (connect to RX of other device)
 
 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example
 modified again 8 Feb 2013
 by Brian Baker for MSP430
 
 This example code is in the public domain.
 
 */
#include <SoftwareSerial.h>
char Message[30];
SoftwareSerial mySerial(P1_4, P1_3); // RX, TX
int i;
char msg[30];
void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  Serial.println("Serial port");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
//  mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  for(i=0;i<30;i++)
  {
    msg[i]=Message[i]=0;
  }
 if (mySerial.available()){
    if (mySerial.read()=='+'||mySerial.read()=='-')
    {
    }
    else
    {
         for(i=0;i<=15;i++){

     Message[i] = mySerial.read();
      if(Message[i]=='#')
    {
      i=i-1;
      break;
    }
    }
    }
 //   memcpy(msg, Message, i);
   int msglen=strlen(Message); 
msglen--; 
 if(Message[msglen]=='#')
 {
   Message[msglen]= '\0';
 }
 msg[0]=Message[msglen-4];
 msg[1]=Message[msglen-3];
 msg[2]=Message[msglen-2];
 msg[3]=Message[msglen-1];
 
int k= atoi(msg);
int l=map(k,0,1023,0,255);
  Serial.println(l);
//  Serial.println();
  delay(500);
 // if (Serial.available())
   // mySerial.write(Serial.read());
}
}
