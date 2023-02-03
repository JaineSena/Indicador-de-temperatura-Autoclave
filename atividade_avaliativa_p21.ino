// Atividade Avaliativa P2 // Jaine Sena // 
// Indicador de temperatura de uma autoclave // 

#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);
int led9 = 9;
int led11 = 11;
int Ch = 12;
int temp; // Sensor de temperatura
int pot; // Potenciometro

void setup()
{
  pinMode(9,OUTPUT); // Led Verde (Acende quando liga)
  pinMode(11,OUTPUT); // Led Verde (Acende quando liga)
  pinMode (12, INPUT); // Chave / Liga o termometro
  lcd.begin(16,2); // LDC
}

void loop()
{
   	temp = analogRead(A0);
  	pot = analogRead(A1);
  	lcd.setCursor(0, 0); 
  	lcd.print("  Aquecimento");
  	lcd.setCursor(0, 1); 
  	lcd.print("Sel:    Real:   ");
  	lcd.setCursor(4, 1);
  	lcd.print(pot);
  	//pwm = map(x, 0, 1023, 0, 255);
  	//analogWrite(led, pwm);
 	lcd.setCursor(13, 1);
  	lcd.print(temp);
  	delay(100);
  	//lcd.clear();
  
  if (temp < pot)
  {
    digitalWrite(led9, HIGH);
    digitalWrite(led11, LOW);
    lcd.clear();
  } 
   
 else if (temp > pot)
  {
    digitalWrite(led9, LOW);
    digitalWrite(led11, HIGH);
    lcd.clear();
}
}

