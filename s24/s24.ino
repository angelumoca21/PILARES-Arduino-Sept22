#include<Adafruit_NeoPixel.h>
#define NumeroPixels 9
#define Pin 2
Adafruit_NeoPixel tira = Adafruit_NeoPixel(NumeroPixels,Pin,NEO_GRB + NEO_KHZ800);

void setup()
{
  tira.begin();
}

void loop()
{
  tira.setBrightness(10);
  tira.setPixelColor(0,255,0,0);//rgb
  tira.setPixelColor(1,0,0,255);//rgb
  tira.setPixelColor(2,0,255,0);//rgb
  tira.setPixelColor(3,random(0,255),random(0,255),random(0,255));//rgb
  tira.setPixelColor(4,random(0,255),random(0,255),random(0,255));//rgb
  tira.setPixelColor(5,random(0,255),random(0,255),random(0,255));//rgb
  tira.setPixelColor(6,random(0,255),random(0,255),random(0,255));//rgb
  tira.setPixelColor(7,random(0,255),random(0,255),random(0,255));//rgb
  tira.setPixelColor(8,random(0,255),random(0,255),random(0,255));//rgb
  tira.show();
  delay(500);
}
