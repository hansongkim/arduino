//HW2 - 201824447
int nState = 1;
int num1, num2, sum;
void setup() {
  Serial.begin(9600);
}

void loop() {
  num1 = 0;
  num2 = 0;
  sum = 0;
  Serial.println("Enter 2 Integers to add");
  while (Serial.available() == 0){}
    num1 = Serial.parseInt();
  Serial.print(num1);
  Serial.print(" + ");
  while (Serial.available() == 0){}
    num2 = Serial.parseInt();
  Serial.print(num2);
  Serial.print(" = ");
  sum = num1 + num2;
  Serial.println(sum);
}
