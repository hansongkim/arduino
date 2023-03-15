#include <LiquidCrystal.h>

// 핀 번호 (RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(44, 45, 46, 47, 48, 49); // LCD 연결

void setup() {
  lcd.begin(16, 2); // LCD 초기화
  lcd.print("Hello World!"); // 문자열 출력
}

void loop() {
}
