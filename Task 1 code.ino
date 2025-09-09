// C++ code
//
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(2, LOW);
  delay(500); // Wait for 500 millisecond(s)
  while (digitalRead(8) == HIGH)
  {
    digitalWrite(2,LOW);
  }
  if(digitalRead(7 ) == HIGH)
  {
    while (true)
    digitalWrite(2,HIGH);
  }
  
}
