int pins_LED[] = {2, 3, 4, 5};
int pin_button = 14;
int count = 0;
boolean state_previous = false;
boolean state_current;
int i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pin_button, INPUT);
  for(int i = 0; i < 4; i++) {
    pinMode(pins_LED[i],OUTPUT);
  }
}

void loop() {
  state_current = digitalRead(pin_button);
    if ( state_current ){
      if(state_previous == false){
        count++;
        state_previous = true;
      }
    }
    else {
      state_previous = false;
    }
    if( count % 2 == 0 ){
    digitalWrite( pins_LED[i] , HIGH );
    i++;
    delay(700);
    for(int j=0; j<4; j++){
      digitalWrite( pins_LED[j] , LOW);
    }
    i %= 4;
    }
    else{
    digitalWrite( pins_LED[i] , HIGH );
    i--;
    delay(700);
    for(int j=0; j<4; j++){
      digitalWrite( pins_LED[j] , LOW);
    }
    i += 4;
    i %= 4;
    }
  }
