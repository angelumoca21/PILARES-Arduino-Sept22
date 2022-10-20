/*
Programa del blink con arduino (Hola mundo).
Autor:Angel Morales (angelmoca21@gmail.com)
Ultima fecha de modificación:20/10/22
*/ 

#define LED 13 //LED -> PIN 13 

void setup()
{
  pinMode(LED, OUTPUT); //PIN 13 configurado como salida.
  Serial.begin(9600); //Inicializacion del puerto serial.
}

void loop()
{
  digitalWrite(LED, HIGH); //A LED se le manda a nivel alto (encender)
  Serial.println("El LED se encendio");
  delay(100);//1s de tiempo de espera
  digitalWrite(LED, LOW);//A LED se le manda a nivel bajo (apaga)
  Serial.println("El LED se apago");
  delay(100);//1s de tiempo de espera
}
