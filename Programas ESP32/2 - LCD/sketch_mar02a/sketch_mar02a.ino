#include <LiquidCrystal.h>
#include <DHT.h>;
#define sensor 32
#define DHTYPE DHT11
#define button 34
DHT dht(sensor, DHTYPE);


LiquidCrystal lcd(25, 26, 27, 14, 12, 13); //RS E 4 5 6 7
 
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  lcd.setCursor(0, 0);
//  lcd.clear();  
  lcd.print("Temperatura: ");
  lcd.print(verTemp());
  lcd.setCursor(0, 1);
  lcd.print("Humidade: ");  
  lcd.print(verHumid());
}




float verTemp()
{
  float t = (float)dht.readTemperature();
  return t;
}
float verHumid()
{
  float h = (float)dht.readHumidity();
  return h;
}
