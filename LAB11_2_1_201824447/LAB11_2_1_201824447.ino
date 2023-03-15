// 예제코드의 loop()에 다음내용을 넣어 동작 확인
// http://adam-meyer.com/arduino/ADXL345
  
  //read interrupts source and look for triggerd actions
  byte interrupts = adxl.getInterruptSource();
  //tap
  if(adxl.triggered(interrupts, ADXL345_SINGLE_TAP))
    Serial.println("tap"); 
  //double tap
  if(adxl.triggered(interrupts, ADXL345_DOUBLE_TAP))
    Serial.println("double tap"); 
  // freefall
  if(adxl.triggered(interrupts, ADXL345_FREE_FALL))
    Serial.println("freefall"); 
  //inactivity
  if(adxl.triggered(interrupts, ADXL345_INACTIVITY))
    Serial.println("inactivity");
  //activity
  if(adxl.triggered(interrupts, ADXL345_ACTIVITY))
    Serial.println("activity");
