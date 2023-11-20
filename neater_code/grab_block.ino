void grab_block() {     // moving to block to grab it
  int distance = 0;   
  distance = sensor.getDistance();
  LMotor->run(FORWARD);
  RMotor->run(FORWARD);
  while (distance < 100) {
      LMotor->setSpeed(50); 
      RMotor->setSpeed(50);
  }

  LMotor->setSpeed(0); 
  RMotor->setSpeed(0);

  claw();
};

void claw() {
    int mag = 0;

    servoPos = 0;    // degree to flat
    int lowerPos = 15;
    int upperPos = 70;
    int long start_time;
    int long end_time;
    int long time_diff;

    for ( servoPos = upperPos; servoPos >= lowerPos; servoPos -= 1) { //lowers claw
    // in steps of 1 degree
    clawServo.write(servoPos); // tell servo to go to position in variable 'pos'
    delay(15); // waits 15 ms for the servo to reach the position
    }
    // clawServo.write(servoPos);
    delay(100);
    Serial.println("run");

    start_time = millis();
    time_diff = 0;
  
    while (time_diff < 7000) {
      mag = digitalRead(magnetPIN);
      end_time = millis();
      time_diff = end_time - start_time;
    if (mag == HIGH) { // check if the input is HIGH
    digitalWrite(greenLEDPIN, LOW); // turn LED OFF
    digitalWrite(redLEDPIN, HIGH);
    Serial.println("green");
    } else {
    digitalWrite(redLEDPIN, LOW); // turn LED ON
    digitalWrite(greenLEDPIN, HIGH);
    Serial.println("Red");
    }
    }
 
    for (servoPos = lowerPos; servoPos <= upperPos; servoPos += 1) { // raises claww
    // in steps of 1 degree
    clawServo.write(servoPos); // tell servo to go to position in variable 'pos'
    delay(15); // waits 15 ms for the servo to reach the position
    }
}
