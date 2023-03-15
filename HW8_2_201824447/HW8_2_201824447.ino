#include <LiquidCrystal.h>

LiquidCrystal lcd(44, 45, 46, 47, 48, 49);

void readTemperature() {
 int reading = analogRead(55); 
  float voltage = reading * 5.0 / 1024.0;
  float temp_C = voltage * 100;
  lcd.begin(16, 2);
  lcd.print(temp_C);
  lcd.write(" C");
}
void readIlluminance() {
  int reading = analogRead(56); 
  lcd.setCursor(0, 1);
  lcd.print(reading);
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  readTemperature();
  readIlluminance();
  delay(1000); 
}
