#include <Servo.h>

Servo myServo;
int servoPin = 11;
int button1 = 14;
int button2 = 15;
int angle=0;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  if(digitalRead(button1)){
    angle+=10;
    Serial.print("button1     ");
    Serial.println(angle);
    delay(1000);
  }
  if(digitalRead(button2)){
    angle-=10;
    Serial.print("button2     ");
    Serial.println(angle);
    delay(1000);
  }
  if(angle>180){
    angle=0;
  }
  if(angle<0){
    angle=180;
  }
  myServo.write(angle); // 각도 제어
}
