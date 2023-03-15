int LED_pins[] = {2, 3, 4, 5};
int num_LED = 0; // 켜져 있는 LED 개수
int delta = 1; // LED 개수 증감

void setup() {
  Serial.begin(9600); // 컴퓨터와의 시리얼 연결
  Serial1.begin(9600); // 우노와의 시리얼 연결
  for (int i = 0; i < 4; i++) {
    pinMode(LED_pins[i], OUTPUT);
    digitalWrite(LED_pins[i], LOW);
  }
}

void loop() {
  if (Serial1.available()) { // 우노로부터 데이터 수신
    char data = Serial1.read();
    Serial.println("OK");
    if (data == '1') {
      num_LED += delta;
      if (num_LED == 5) {
        delta = -1;
        num_LED = 3;
      }
      else if (num_LED == -1) {
        delta = 1;
        num_LED = 1;
      }
      Serial.print("Currently ");
      Serial.print(num_LED);
      Serial.println(" LEDs are ON.");
      for (int i = 0; i < 4; i++) { // LED 출력
        if (i < num_LED)
          digitalWrite(LED_pins[i], HIGH);
        else
          digitalWrite(LED_pins[i], LOW);
      }
    }
  }
}
