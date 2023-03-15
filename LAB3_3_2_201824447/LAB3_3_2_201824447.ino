int pins[] = {2,3,4,5};         //LED 연결핀
int state = 0;                  //현재 켤 LED 인덱스

void setup() {
  Serial.begin(9600);           //시리얼 통신 초기화
  for (int i = 0; i<4; i++){
    pinMode(pins[i], OUTPUT);   //Output 모드로 설정
    digitalWrite(pins[i], LOW); //꺼진 상태로 시작
  }
}

void loop() {
  for(int i = 0; i<4;i++){
    if(i==state){               //하나의 LED만 켬
      Serial.print("O ");
      digitalWrite(pins[i], HIGH);
    } else {                    //나머지는 끔
      Serial.print("X ");
      digitalWrite(pins[i], LOW);
    }
  }
  Serial.println();
  state = (state+1)%4;          //켤 LED 바꿈
  delay(1000);                  //1초대기
}
