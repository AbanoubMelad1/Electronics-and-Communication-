#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  pinMode(5, OUTPUT);   
  pinMode(A0, INPUT);   
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);

  lcd.init();          
  lcd.backlight();      
}

void loop()
{
  int x = analogRead(A0);              
  int pwmValue = (x * 255) / 1023;     

  digitalWrite(7, LOW);
  delayMicroseconds(2);
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);

  long duration = pulseIn(8, HIGH);       
  long distance = duration * 0.034 / 2;   

  if (distance < 15) {
    pwmValue = 0; 
  }

  analogWrite(5, pwmValue);            

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm");

  lcd.setCursor(0, 1);
  lcd.print("Speed: ");
  lcd.print(pwmValue);

  delay(500); 
}
