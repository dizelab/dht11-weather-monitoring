#include <LiquidCrystal.h>
#include "DHT.h"              //https://github.com/dizelab/DHT-sensor-arduino-library

#define DHTPIN 8                // Sensor Pin!
#define DHTTYPE DHT11          // define the type of sensor used!

DHT dht(DHTPIN, DHTTYPE);     // Initialize DHT sensor.
                                     
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte degreec[] =
 { 
  B11000,
  B11000,
  B00011,
  B00100,
  B00100,
  B00100,
  B00011,
  B00000
 };

void setup() 
{
 pinMode(3,OUTPUT);
 digitalWrite(3,HIGH); 
 lcd.begin(16, 2);
 lcd.createChar(0, degreec);
 lcd.home();
 dht.begin();
 
 lcd.setCursor(0,1);
 lcd.print("WeatherMonitor ");
 delay(600);
 lcd.setCursor(0,0);
 lcd.print("                 ");
  lcd.setCursor(0,1);
 lcd.print("                 ");
 delay(100);
 
}

void loop()
{
 float h = dht.readHumidity();      // Read Humidity 
 float t = dht.readTemperature();   // Read temperature as Celsius
 lcd.setCursor(1,0);
 lcd.print("Temp:");
 lcd.setCursor(6,0);
 lcd.print(t);
 lcd.setCursor(11,0);
 lcd.write((byte)0);
 lcd.setCursor(1,1);
 lcd.print("Humd:");
 lcd.setCursor(6,1);
 lcd.print(h);
 lcd.setCursor(11,1);
 lcd.print("%");
 
}
