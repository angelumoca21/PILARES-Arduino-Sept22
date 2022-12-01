#include<LiquidCrystal.h>
#include<DHT.h>

#define DHTPIN 10
#define DHTTYPE DHT11

DHT tempHum(DHTPIN, DHTTYPE);
LiquidCrystal pantallita(12, 11, 5, 4, 3, 2);

void setup()
{
  tempHum.begin();
  pantallita.begin(16, 2);
  pantallita.setCursor(3, 0);
  pantallita.print("Bienvenidos");
  pantallita.setCursor(3, 1);
  pantallita.print("PILARES :D");
  delay(1000);
}

void loop()
{
  float temperature = tempHum.readTemperature();
  float humidity = tempHum.readHumidity();
  pantallita.clear();
  pantallita.setCursor(0, 0);
  pantallita.print("Temp:");
  pantallita.setCursor(5, 0);
  pantallita.print(temperature);
  pantallita.setCursor(12, 0);
  pantallita.print("C");
  pantallita.setCursor(0, 1);
  pantallita.print("Hum:");
  pantallita.setCursor(4, 1);
  pantallita.print(humidity);
  pantallita.setCursor(10, 1);
  pantallita.print("%");
  delay(500);
}
