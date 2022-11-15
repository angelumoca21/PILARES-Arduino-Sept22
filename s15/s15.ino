#define FotoRes A1
#define activadorRele 2

int lecturaFotoRes = 0;

void setup()
{
 pinMode(activadorRele,OUTPUT);
 Serial.begin(9600);
}

void loop()
{
  lecturaFotoRes = analogRead(FotoRes);
  Serial.println(lecturaFotoRes);
  if (lecturaFotoRes >= 536)
  {
    digitalWrite(activadorRele, 1);
  }
  else
  {
    digitalWrite(activadorRele, 0);
  }
}
