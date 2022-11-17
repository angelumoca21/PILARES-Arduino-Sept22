#define Trig 2
#define Echo 4
#define b 6
#define g 7

float tiempo=0,distancia=0; 

void setup()
{
  Serial.begin(9600);
  pinMode(b,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  digitalWrite(Trig,LOW);
}

void loop()
{
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  tiempo=pulseIn(Echo,HIGH);
  tiempo=tiempo/2;
  Serial.println("Distancia calculada:");
  distancia=tiempo*0.0343;
  Serial.println(distancia);
  Serial.println("Distancia por experiencia:");
  distancia=tiempo/29;
  Serial.println(distancia);
  if (distancia < 14)
  {
    digitalWrite(b,1);
    digitalWrite(g,0); 
  }
  else
  {
    digitalWrite(g,1);
    digitalWrite(b,0); 
  }
}
