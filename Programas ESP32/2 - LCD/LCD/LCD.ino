#include <LiquidCrystal.h>
#include <DHT.h>;
#define sensor 32
#define DHTYPE DHT11
#define button 34
DHT dht(sensor, DHTYPE);


LiquidCrystal lcd(13, 12, 14, 27, 26, 25); //RS E 4 5 6 7
 
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  dht.begin();

  pinMode(button, INPUT_PULLUP);
}

bool temp = true;
bool buttOn = false;
void loop() {
  lcd.setCursor(0, 0);
  lcd.clear();  
  lcd.print(temp ? "Temperatura" : "Humidade");  

  lcd.setCursor(0, 1);
  lcd.print(temp ? verTemp() : verHumid());
  if(digitalRead(button) == HIGH){
    if(!buttOn){
      if(temp)
        temp = false;
      else if(!temp)
        temp = true;
      buttOn = true;
    }
  }
  if(digitalRead(button) == LOW)
  {
    if(buttOn)
       buttOn = false; 
  }
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
