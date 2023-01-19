#include<SoftwareSerial.h>

SoftwareSerial moduloAngel(10,11);//RX TX

void setup() 
{
  Serial.begin(9600); //Comunicacion con la PC, monitor serie
  moduloAngel.begin(38400); //Comunicación con el modulo bluetooth
  Serial.println("Listo");
}

void loop() 
{
  if(moduloAngel.available())
    Serial.write(moduloAngel.read());
  if(Serial.available())
    moduloAngel.write(Serial.read());
}
