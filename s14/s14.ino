#define AZUL 3
#define VERDE 5
#define ROJO 6
#define POTENCIOMETRO A0

int lecturaPot = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  lecturaPot = analogRead(POTENCIOMETRO);
  Serial.println(lecturaPot);
  lecturaPot = map(lecturaPot,0,1023,0,255);
  Serial.println(lecturaPot);
  analogWrite(AZUL,lecturaPot);
  delay(200);
}
