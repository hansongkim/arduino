...

void loop() {
  ...
  if (distance > 100) {
    led1Bright = 0;
  } else {
    led1Bright = map(distance, 100, 0, 0, 255);
  }
  Serial.println(led1Bright);
  analogWrite(led1Pin, led1Bright);
  
  if(motion == 1) {
    Serial.println("Motion detected");
    digitalWrite(led2Pin, HIGH);
  } else {
    digitalWrite(led2Pin, LOW);
  } 

  delay(500);
}
