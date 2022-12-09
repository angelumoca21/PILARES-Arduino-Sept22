#include<IRremote.h>
//PINES DE CONTROL DEL MOTOR
#define pinVelocidad 3
#define input1 4
#define input2 5
//PINES DE CONTROL DEL RECEPTOR IR
#define IRpin 9
#define b123 210 //girar en sentido izq
#define bpuntitos 206 //girar en otro sentido izq
#define bregresar 88 //stop
#define bhome 121 //+vel
#define bplay 185 //-vel

int velocidad = 255;

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(IRpin);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
}

void loop()
{
  while (IrReceiver.decode() != 0)
  {
    Serial.println(IrReceiver.decodedIRData.command);
    if (IrReceiver.decodedIRData.command == b123)
    {
      digitalWrite(input1, 1);
      digitalWrite(input2, 0);
      analogWrite(pinVelocidad, velocidad);
      Serial.println("Giro en un sentido");
    }
    else if (IrReceiver.decodedIRData.command == bpuntitos)
    {
      digitalWrite(input1, 0);
      digitalWrite(input2, 1);
      analogWrite(pinVelocidad, velocidad);
      Serial.println("Giro en otro sentido");
    }
    else if (IrReceiver.decodedIRData.command == bregresar)
    {
      digitalWrite(input1, 0);
      digitalWrite(input2, 0);
      Serial.println("Stop");
    }
    /*else if (IrReceiver.decodedIRData.command == bhome)
    {
      velocidad = velocidad + 10;
      Serial.println(velocidad);
    }
    else if (IrReceiver.decodedIRData.command == bplay)
    {
      velocidad = velocidad - 10;
      Serial.println(velocidad);
    }*/
    IrReceiver.resume();
  }
}
