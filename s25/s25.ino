#define IN1 7
#define IN2 8
#define ENA 3

int vel = 0;//0-255

void setup() 
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
}

void loop() 
{
  for (vel=0;vel <= 255;vel++)
  {
    analogWrite(ENA,vel);
    digitalWrite(IN1,1);
    digitalWrite(IN2,0);
    delay(100);
  }
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  delay(3000);
  for (vel=255;vel >= 0;vel--)
  {
    analogWrite(ENA,vel);
    digitalWrite(IN1,0);
    digitalWrite(IN2,1);
    delay(100);
  }
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  delay(3000);
}
