void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(15,INPUT);
  pinMode(2,OUTPUT);
}

void loop()
{
  int value= analogRead(15);
  Serial.println(value);
  if(value<15)
  {
    digitalWrite(2,HIGH);
  }
  else
  digitalWrite(2,LOW);
  // put your main code here, to run repeatedly:
    delay(1000);

}
