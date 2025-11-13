#include <dht11.h>
#include <LiquidCrystal.h>
#define DHT11PIN 4

dht11 DHT11;
const int rs = 2,
          en = 3,
          d4 = 6,
          d5 = 7,
          d6 = 8,
          d7 = 9;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void  setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{
  int chk = DHT11.read(DHT11PIN);

  lcd.setCursor(0, 0);
  lcd.print("Humidity (%): ");
  lcd.println((float)DHT11.humidity, 2);
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Temp (C): ");
  lcd.println((float)DHT11.temperature, 2);
  delay(2000);
  lcd.clear();
}
