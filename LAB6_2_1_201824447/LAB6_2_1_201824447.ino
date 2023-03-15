const int pin_LED = 13;
boolean LED_state = false;

void setup() {
  pinMode(pin_LED, OUTPUT);
}

void loop() {
  LED_state = !LED_state; // LED 상태 반전
  digitalWrite(pin_LED, LED_state); // LED 출력
  delay(1000);
}
