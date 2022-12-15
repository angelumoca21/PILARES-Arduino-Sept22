#include<Servo.h>
#define pinServo 5
#define pinPot A5
Servo servoMotor;
int valorPot = 0;

void setup()
{
  servoMotor.attach(pinServo);
  servoMotor.write(0);
}

void loop()
{ valorPot = analogRead(pinPot);
  valorPot = map(valorPot, 0, 1023, 0, 180);
  servoMotor.write(valorPot);
}
