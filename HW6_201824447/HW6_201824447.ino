int pin_LED[] = {2, 3};
unsigned long time_previous, time_current;
unsigned long time_previouss, time_currents;
unsigned long interval = 1000;
unsigned long intervals = 1000;
boolean LED_state = false;
boolean LED_states = false;

void setup() {
 pinMode(A0, INPUT);
 for(int i=0; i<2; i++){
 pinMode(pin_LED[i], OUTPUT);
 digitalWrite(pin_LED[i], LED_state);
 }
 Serial.begin(9600);
 time_previous = millis();
 time_previouss = millis();
}
void loop() {
 time_current = millis();
 time_currents = millis();
 if (time_current - time_previous >= interval) {
 Serial.print("Current interval is ");
 Serial.print(interval);
 Serial.println(" ms.");
 time_previous = time_current;
 LED_state = !LED_state;
 digitalWrite(pin_LED[1], LED_state);
 }
 if (time_currents - time_previouss >= intervals) {
 Serial.print("Current intervals is ");
 Serial.print(intervals);
 Serial.println(" ms.");
 time_previouss = time_currents;
 LED_states = !LED_states;
 digitalWrite(pin_LED[0], LED_states);
 }
 int adc = analogRead(A0);
 interval = map(adc, 0, 1023, 500, 1500);
 intervals = map(adc, 0, 1023, 1500, 500);
}
