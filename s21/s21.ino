#include<IRremote.h>
#define IRpin 9
#define LED 2

void setup()
{
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
  IrReceiver.begin(IRpin);
}

void loop()
{
  while(IrReceiver.decode() != 0)
  {
    Serial.println(IrReceiver.decodedIRData.command);
    /*if (IrReceiver.decodedIRData.command == 210)
      digitalWrite(LED,!digitalRead(LED));*/
    IrReceiver.resume();
  }
}
