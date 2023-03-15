int button_pin = 14;
int count=0;
int Enable1=38;
int DIR1 = 39;
int PWM1 = 9;

void setup(){
  Serial.begin(9600);
  pinMode(Enable1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  digitalWrite(Enable1, HIGH);
  pinMode(button_pin, INPUT);
}

void loop() {
  if (digitalRead(button_pin)) {
    count+=1;
    Serial.print("PUSHED   ");
    Serial.println(count);
    delay(800);
  }
  if(count==0){
    digitalWrite(PWM1,LOW);
  }
  else if(count==1){
    analogWrite(PWM1,128);
  }
  else if(count==2){
    digitalWrite(PWM1, HIGH);
  }
  else if(count==3){
    count=0;
  }
}
