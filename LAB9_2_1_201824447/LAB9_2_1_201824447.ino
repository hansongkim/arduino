void loop() {
  // 모터 1 제어
  digitalWrite(Enable1, HIGH); // 모터 제어 가능 상태
  digitalWrite(DIR1, HIGH); // 정방향 회전
  digitalWrite(PWM1, LOW); // 최고 속도
  delay(4000);
  digitalWrite(PWM1, HIGH); // 속도 0
  delay(200);
  digitalWrite(DIR1, LOW); // 역방향 회전
  digitalWrite(PWM1, HIGH); // 최고 속도
  delay(4000);
  digitalWrite(PWM1, LOW); // 속도 0
  delay(200);
  digitalWrite(Enable1, LOW); // 모터 제어 불가능 상태
}
