

//int swi=0;
int count;
void setup()
{
  pinMode(5,INPUT_PULLUP);
  pinMode(2,OUTPUT);
}  

void loop()
{
if (digitalRead(5)==LOW)
{
P1OUT = P1OUT ^ B00000001;      //BITWISE TOGGLE
delay(500);
}
}
