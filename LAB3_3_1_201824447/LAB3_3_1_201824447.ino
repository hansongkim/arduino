int led = 13;               //Digital I/O 대상 Pin번호

void setup() {
  pinMode(led, OUTPUT);     //Digital 13번 Pin을 Output모드로 설정
}

void loop() {
  digitalWrite(led, HIGH);  //13번 Pin으로 HIGH (1 또는 ON) 출력
  delay(1000);              //1초(1000ms)대기
  digitalWrite(led, LOW);   //13번 Pin으로 LOW (0 또는 OFF) 출력
  delay(1000);              //1초(1000ms)대기
}
