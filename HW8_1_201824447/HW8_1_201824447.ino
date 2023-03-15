int button=14;
byte patterns[] = {
  0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6
};
int digit_select_pin[] = {66, 67, 68, 69}; // 자릿수 선택 핀
// 7세그먼트 모듈 연결 핀 ‘a, b, c, d, e, f, g, dp’ 순서
int segment_pin[] = {58, 59, 60, 61, 62, 63, 64, 65};
int SEGMENT_DELAY = 5; // 숫자 표시 사이의 시간 간격
unsigned long time_previous, time_current;
int minutes = 0, seconds = 0;
boolean state_previous = false;
boolean state_current;
int count = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) { // 자릿수 선택 핀을 출력으로 설정
    pinMode(digit_select_pin[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) { // 세그먼트 제어 핀을 출력으로 설정
    pinMode(segment_pin[i], OUTPUT);
  }
  time_previous = millis();
  pinMode(button, INPUT);
}

// 해당 자리에 숫자 하나를 표시하는 함수
void show_digit(int pos, int number) { // (위치, 출력할 숫자)
  for (int i = 0; i < 4; i++) {
    if (i + 1 == pos) // 해당 자릿수의 선택 핀만 LOW로 설정
      digitalWrite(digit_select_pin[i], LOW);
    else // 나머지 자리는 HIGH로 설정
      digitalWrite(digit_select_pin[i], HIGH);
  }
  for (int i = 0; i < 8; i++) {
    boolean on_off = bitRead(patterns[number], 7 - i);
    digitalWrite(segment_pin[i], on_off);
  }
}

// 4자리 7세그먼트 표시 장치에 4자리 숫자를 표시하는 함수
void show_4_digit(int number) {
  number = number % 1000;
  int hundreads = number / 100; // 백 자리
  number = number % 100;
  int tens = number / 10; // 십 자리
  int ones = number % 10; // 일 자리
  show_digit(2, hundreads);
  delay(SEGMENT_DELAY);
  show_digit(3, tens);
  delay(SEGMENT_DELAY);
  show_digit(4, ones);
  delay(SEGMENT_DELAY);
}

void loop() {
  state_current = digitalRead(button);
  if ( state_current ){
    if(state_previous == false){
      count++;
      state_previous = true;
    }
  }
  else {
    state_previous = false;
  }
  if(count%2==0){
  time_current = millis();
  if (time_current - time_previous >= 1000) { // 1초 경과
    time_previous = time_current;
    seconds++; // 초 증가
    if (seconds == 1000) seconds = 0;
  }
  show_4_digit(seconds); // 시간 표시를 위해 4자리 숫자로 만듦
  }
  else{
  time_current = millis();
  if (time_current - time_previous >= 1000) { // 1초 경과
    time_previous = time_current;
    seconds--; // 초 증가
    if (seconds == 0) seconds = 999; // 60분이 되면 0으로 되돌림
  }
  show_4_digit(seconds); // 시간 표시를 위해 4자리 숫자로 만듦
  }
}
