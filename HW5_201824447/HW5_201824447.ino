int pins_LED[] = {2, 3, 4, 5};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(pins_LED[i], OUTPUT);
  }
}

void loop() {
  int PWM_value[4] = {0,63,127,191};
  while(true){
  for (int i = 0; i < 4; i++) {
    if (PWM_value[i] >= 256) {
      PWM_value[i] = 0;
    }
    PWM_value[i]++;
    analogWrite(pins_LED[i], PWM_value[i]);
    delay(3);
  }
  }
}
