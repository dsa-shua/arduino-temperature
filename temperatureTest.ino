
#include <LiquidCrystal.h>
#include "DHT.h"
DHT dht(8, DHT11);
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  dht.begin();
  lcd.begin(16,2);
  pinMode(9,OUTPUT); // status pin
  pinMode(7,OUTPUT); // error pin
}

void loop() {
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    digitalWrite(7,HIGH);
    delay(500);
    digitalWrite(7,LOW);
    delay(500);
    return;
  }
  digitalWrite(9,HIGH);
  lcd.setCursor(0,0); 
  lcd.print("Humi: "); 
  lcd.print(h);
  lcd.print(" %");

  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
  
  digitalWrite(9,LOW);
  delay(2000);
}
