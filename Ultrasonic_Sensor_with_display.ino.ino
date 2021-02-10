

#include <LiquidCrystal.h>

LiquidCrystal lcd(3,4,5,6,7,8);

const int trig=9;
const int echo=10;
float duration;
int cmDistance;
int inchDistance;

void setup(){
  lcd.begin(16, 2);
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);
}

void loop(){
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  cmDistance= duration*0.034/2;
  inchDistance=cmDistance/2.54;

  lcd.setCursor(0,0);
  lcd.print("Dist: ");
  lcd.print(cmDistance);
  lcd.print(" cm");

  lcd.setCursor(0,1);
  lcd.print("Dist: ");
  lcd.print(inchDistance);
  lcd.print(" inch");
  delay(2000);

  lcd.setCursor(0,0);
  lcd.print("                        ");
  lcd.setCursor(0,1);
  lcd.print("                        "); 
}
