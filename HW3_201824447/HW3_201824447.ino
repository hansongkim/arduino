int pattern=1, shift;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // 시리얼 통신 초기화
  for(int i = 2; i<6; i++) {
    pinMode(i,OUTPUT); //Output 모드로 설정
    digitalWrite(i,LOW); //꺼진 상태로 시작
  }
  
}
void loop() {
   for(int index=1; index<7; index++){
    if(pattern==1){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    delay(1000);
    }
    else if(pattern==3){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    delay(1000);
    }
    else if(pattern==7){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(1000);
    }
    else if(pattern==15){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    delay(1000);
    }
    pattern=0x01;
    if(index<4) shift = index;
    else shift = 6-index;
    if(shift !=0){
    for(int i=0; i<shift; i++){
      pattern = (pattern << 1) | 0x01;
      }
    }
  }
}
