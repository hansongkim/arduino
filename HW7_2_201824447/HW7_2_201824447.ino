#include <pitches.h>

int speakerPin = 57;
unsigned int note = 1;
void setup() {
  pinMode(56, INPUT);
}

void loop() {
  int adc = analogRead(56);
  note = map(adc, 0, 1023, 1, 9);
  Serial.println(note);
  if(note<=1){
    tone(57, 0, 1000);
  }
  else if(note<=2){
    tone(57, NOTE_C4, 1000);
  }
  else if(note<=3){
    tone(57, NOTE_D4, 1000);
  }
  else if(note<=4){
    tone(57, NOTE_E4, 1000);
  }
  else if(note<=5){
    tone(57, NOTE_F4, 1000);
  }
  else if(note<=6){
    tone(57, NOTE_G4, 1000);
  }
  else if(note<=7){
    tone(57, NOTE_A4, 1000);
  }
  else if(note<=8){
    tone(57, NOTE_B4, 1000);
  }
  else{
    tone(57, NOTE_C5, 1000);
  }
}
