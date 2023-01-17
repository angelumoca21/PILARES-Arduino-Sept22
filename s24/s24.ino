#include<Adafruit_NeoPixel.h>
#define NumeroPixels 16
#define Pin 13
Adafruit_NeoPixel tira = Adafruit_NeoPixel(NumeroPixels,Pin,NEO_GRB + NEO_KHZ800);

void setup()
{
  tira.begin();
}

void loop()
{
  tira.setBrightness(255);
  for(int i = 0;i<NumeroPixels;i++)
  {
    tira.setPixelColor(i,0,0,255);//rgb
    tira.show();
    delay(500);
  }
    for(int i = 0;i<NumeroPixels;i++)
  {
    tira.setPixelColor(i,random(0,255),random(0,255),random(0,255));//rgb
    tira.show();
    delay(500);
  }
  delay(5000);
}
