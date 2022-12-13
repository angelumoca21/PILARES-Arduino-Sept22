#include <IRremote.h>
//PINES DE CONTROL DEL MOTOR
#define input1 4
#define input2 7
#define pinVel 5
//PINES DE CONTROL DEL RECEPTOR IR
#define IRpin 9
#define bizq 210   //girar en sentido izq
#define bder 206   //girar en otro sentido izq
#define bplay 88   //stop
#define bvolM 121  //+vel
#define bvolm 185  //-vel

int vel = 130;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IRpin);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
}

void loop() 
{
  while (IrReceiver.decode() != 0) 
  {
    analogWrite(pinVel, vel);
    if (IrReceiver.decodedIRData.command == bizq){
      digitalWrite(input1, 1);
      digitalWrite(input2, 0);
      Serial.println("Giro en un sentido");
      Serial.print("Velocidad actual: ");
      Serial.println(vel);
    }
    else if (IrReceiver.decodedIRData.command == bder) {
      digitalWrite(input1, 0);
      digitalWrite(input2, 1);
      Serial.println("Giro en otro sentido");
      Serial.print("Velocidad actual: ");
      Serial.println(vel);
    }
    else if (IrReceiver.decodedIRData.command == bplay) {
      digitalWrite(input1, 0);
      digitalWrite(input2, 0);
      Serial.println("Stop");
      Serial.print("Velocidad actual: ");
      Serial.println(vel);
    } 
    else if (IrReceiver.decodedIRData.command == bvolM) {
      vel = vel + 20;
      if (vel > 255)
        vel = 255;
      Serial.print("Velocidad actual: ");
      Serial.println(vel);
    } 
    else if (IrReceiver.decodedIRData.command == bvolm) 
    {
      vel = vel - 20;
      if (vel < 0)
        vel = 0;
      Serial.print("Velocidad actual: ");
      Serial.println(vel);
    }
    IrReceiver.resume();
  }
}
