void setup() {
  Serial.begin(9600); // 컴퓨터와의 시리얼 연결
  Serial1.begin(9600); // 우노와의 시리얼 연결
}

void loop() {
  if (Serial1.available()) { // 우노로부터 데이터 수신
    double temp = Serial1.read();
    Serial.print("Current temperature : ");
    Serial.println(temp);
  }
}
