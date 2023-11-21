bool grab_block(bool sweep) {     // moving to block to grab it
  int distance = 0;   
  distance = sensor.getDistance();
  LMotor->run(FORWARD);
  RMotor->run(FORWARD);

  if (sweep == true) {
    while (distance > 100) {     //grab block for sweep
        LMotor->setSpeed(50); 
        RMotor->setSpeed(50);

    }
    LMotor->setSpeed(0); 
    RMotor->setSpeed(0);

    claw();
    return true;
  }

  if (distance < 100 && sweep == false){    // grab block for line following

    LMotor->setSpeed(0); 
    RMotor->setSpeed(0);

    claw();

    return true;
  }

  else {
    return false;
  }


}

void claw() {
    int mag = 0;
    bool magnetic = false;    // MAYBE MOVE TO SOMEWEHRE ELSE

    servoPos = 0;    // degree to flat
    int lowerPos = 15;
    int upperPos = 90;
    int long start_time;
    int long end_time;
    int long time_diff;
    int long shimmy_end;
    int long shimmy_duration;

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

    RMotor->run(BACKWARD);
    LMotor->run(BACKWARD);
    
    RMotor->setSpeed(150);
    LMotor->setSpeed(150);


    
  
    while (time_diff < 7000) {
      mag = digitalRead(magnetPIN);
      end_time = millis();

      // shimmy_end = millis();
      // shimmy_duration = shimmy_end - start_time;

      // if ((shimmy_duration/50)/2 == 0){
      //   RMotor->run(FORWARD);
      //   LMotor->run(BACKWARD);
        
      //   RMotor->setSpeed(50);
      //   LMotor->setSpeed(50);
      // } else{
      //   RMotor->run(BACKWARD);
      //   LMotor->run(FORWARD);
        
      //   RMotor->setSpeed(50);
      //   LMotor->setSpeed(50);
      // }

      time_diff = end_time - start_time;
    if (time_diff > 1000) {
          RMotor->setSpeed(0);
          LMotor->setSpeed(0);
    }
    if (mag == HIGH) { // check if the input is HIGH

    magnetic = true;
    //Serial.println("red");
    }

 
    }
       if (magnetic == true){
      digitalWrite(greenLEDPIN, LOW); // turn LED OFF
      digitalWrite(redLEDPIN, HIGH);
      delay(5000);
    }
    else {
    digitalWrite(redLEDPIN, LOW); // turn LED ON
    digitalWrite(greenLEDPIN, HIGH);
    delay(5000);
    //Serial.println("grren");
    }
 
    // for (servoPos = lowerPos; servoPos <= upperPos; servoPos += 1) { // raises claww
    //     // in steps of 1 degree
    //     clawServo.write(servoPos); // tell servo to go to position in variable 'pos'
    //     delay(15); // waits 15 ms for the servo to reach the position
    // }
}
