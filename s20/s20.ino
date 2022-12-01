#include<LiquidCrystal.h>
#define Trig 10
#define Echo 9

LiquidCrystal pantallita(12, 11, 5, 4, 3, 2);

float tiempo=0,distancia=0; 

void setup()
{
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  digitalWrite(Trig,LOW);
  pantallita.begin(16, 2);
  pantallita.setCursor(3,0);
  pantallita.print("Bienvenidos");
  pantallita.setCursor(3,1);
  pantallita.print("PILARES :D");
  delay(1000);
}

void loop()
{
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  tiempo=pulseIn(Echo,HIGH);
  tiempo=tiempo/2;
  distancia=tiempo/29;
  pantallita.clear();
  pantallita.setCursor(3,0);
  pantallita.print("Distancia:");
  pantallita.setCursor(4,1);
  pantallita.print(distancia);
  pantallita.setCursor(10,1);
  pantallita.print("cm");
  delay(500);
}
