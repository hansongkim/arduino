void setup() {
  Serial.begin(9600);
}

void loop() {
  int state = 0;
  int count = 0;
  int len = 0;
  char buffer[128];
  String str[5];

  while (true) {
    if (state < 5) {
      Serial.print("Enter the " + String(state+1) +"th Word --> ");
      state = 5;
    }
    while (Serial.available()) { 
      char data = Serial.read();
      if (data == '\n') {  
        buffer[len] = '\0';
        str[count] = buffer;
        Serial.println(str[count]);
        count += 1;          
        state = count;
        len=0;
        break;          
      }
      buffer[len++] = data;
    }
    if (count == 5) break;
  }

  Serial.println("After Sorting");
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 5; j++) {
      int compare = str[i].compareTo(str[j]);
      if (compare > 0) { 
        String temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }
  
  for (int i = 0; i < 5; i++) {
    Serial.println(str[i]);
  }
}
