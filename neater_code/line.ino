void line_route() {
      straight_to_cross();

    delay(500);

    turn_right(150);

    delay(500);

    straight_to_T();

    delay(500);

    turn_left(150);

    delay(500);

    straight_to_branchLeft();

    delay(500);

    turn_left(150);

    delay(500);

    straight_to_branchLeft();

    delay(500);

    turn_left(150);

    delay(500);

    straight_to_T();

    delay(500);

    turn_right(150);

    delay(500);

    straight_to_cross();
    delay(500);

    turn_left(150);
    delay(500);

    straight_to_T();

    delay(500000);
}

void straight_to_T(){
  end = false;
  long int start_time = millis();
  long int end_time = millis();
  long int time_diff = 0;
  int speed = 120;

  while (end == false){
    Serial.println("*****T*******");

    int FLLineResult = digitalRead(frontLeftLineSensorPIN);
    int FRLineResult = digitalRead(frontRightLineSensorPIN);
    int leftLineResult = digitalRead(leftLineSensorPIN);
    int rightLineResult = digitalRead(rightLineSensorPIN);
    
    testing_line_sensors(FLLineResult, FRLineResult, leftLineResult, rightLineResult);

    end_time = millis();
    time_diff = end_time - start_time;
    Serial.print("Time Difference: "); Serial.println(time_diff);

    error_correction(speed, FRLineResult, FLLineResult);

    digitalWrite(blueLEDPIN, HIGH);
    // delay(250);
    // digitalWrite(blueLEDPIN, LOW);
    // delay(250);

    

    //if (rightLineResult == 1 && leftLineResult == 1 && frontLineResult == 0 && time_diff > 3000){
    if (FLLineResult == 0 && FRLineResult == 0 && leftLineResult == 1 && rightLineResult == 1 && time_diff > 3000) { //FOR TESTING
      LMotor->setSpeed(0);
      RMotor->setSpeed(0);
      digitalWrite(blueLEDPIN, LOW);
      end = true;
    }
    
  }
}

void straight_to_cross(){
  end = false;
  long int start_time = millis();
  long int end_time = millis();
  long int time_diff = 0;
  int speed = 120;

  while (end == false){

    int FLLineResult = digitalRead(frontLeftLineSensorPIN);
    int FRLineResult = digitalRead(frontRightLineSensorPIN);
    int leftLineResult = digitalRead(leftLineSensorPIN);
    int rightLineResult = digitalRead(rightLineSensorPIN);
    
    testing_line_sensors(FLLineResult, FRLineResult, leftLineResult, rightLineResult);

    end_time = millis();
    time_diff = end_time - start_time;
    Serial.print("Time Difference: "); Serial.println(time_diff);

    error_correction(speed, FRLineResult, FLLineResult);

    digitalWrite(blueLEDPIN, HIGH);
    // delay(250);
    // digitalWrite(blueLEDPIN, LOW);
    // delay(250);

    

    //if (rightLineResult == 1 && leftLineResult == 1 && frontLineResult == 0 && time_diff > 3000){
    if (FLLineResult == 1 && FRLineResult == 1 && leftLineResult == 1 && rightLineResult == 1 && time_diff > 3000) { //FOR TESTING
      LMotor->setSpeed(0);
      RMotor->setSpeed(0);
      digitalWrite(blueLEDPIN, LOW);
      end = true;
    }
    
  }
}

void straight_to_cornerRight(){
  end = false;
  long int start_time = millis();
  long int end_time = millis();
  long int time_diff = 0;
  int speed = 120;

  while (end == false){
    Serial.println("START");

    int FLLineResult = digitalRead(frontLeftLineSensorPIN);
    int FRLineResult = digitalRead(frontRightLineSensorPIN);
    int leftLineResult = digitalRead(leftLineSensorPIN);
    int rightLineResult = digitalRead(rightLineSensorPIN);
    
    // testing_line_sensors(FLLineResult, FRLineResult, leftLineResult, rightLineResult);

    end_time = millis();
    time_diff = end_time - start_time;
    Serial.print("Time Difference: "); Serial.println(time_diff);

    error_correction(speed, FRLineResult, FLLineResult);

    digitalWrite(blueLEDPIN, HIGH);
    // delay(250);
    // digitalWrite(blueLEDPIN, LOW);
    // delay(250);


    //if (rightLineResult == 1 && leftLineResult == 1 && frontLineResult == 0 && time_diff > 3000){
    if (FLLineResult == 0 && FRLineResult == 0 && rightLineResult == 1 && time_diff > 3000) { //FOR TESTING
      LMotor->setSpeed(0);
      RMotor->setSpeed(0);
      digitalWrite(blueLEDPIN, LOW);
      end = true;
    }
    
  }
}

void straight_to_cornerLeft(){
  end = false;
  long int start_time = millis();
  long int end_time = millis();
  long int time_diff = 0;
  int speed = 120;

  while (end == false){
    Serial.println("START");

    int FLLineResult = digitalRead(frontLeftLineSensorPIN);
    int FRLineResult = digitalRead(frontRightLineSensorPIN);
    int leftLineResult = digitalRead(leftLineSensorPIN);
    int rightLineResult = digitalRead(rightLineSensorPIN);
    
    // testing_line_sensors(FLLineResult, FRLineResult, leftLineResult, rightLineResult);

    end_time = millis();
    time_diff = end_time - start_time;
    Serial.print("Time Difference: "); Serial.println(time_diff);

    error_correction(speed, FRLineResult, FLLineResult);

    digitalWrite(blueLEDPIN, HIGH);
    // delay(250);
    // digitalWrite(blueLEDPIN, LOW);
    // delay(250);

    

    //if (rightLineResult == 1 && leftLineResult == 1 && frontLineResult == 0 && time_diff > 3000){
    if (FLLineResult == 0 && FRLineResult == 0 && leftLineResult == 1 && rightLineResult == 0 && time_diff > 3000) { //FOR TESTING
      LMotor->setSpeed(0);
      RMotor->setSpeed(0);
      digitalWrite(blueLEDPIN, LOW);
      end = true;
    }
    
  }
}

void straight_to_branchLeft(){
  end = false;
  long int start_time = millis();
  long int end_time = millis();
  long int time_diff = 0;
  int speed = 110;

  while (end == false){
    Serial.println("****BRANCH LEFT****");

    int FLLineResult = digitalRead(frontLeftLineSensorPIN);
    int FRLineResult = digitalRead(frontRightLineSensorPIN);
    int leftLineResult = digitalRead(leftLineSensorPIN);
    int rightLineResult = digitalRead(rightLineSensorPIN);
    
    // testing_line_sensors(FLLineResult, FRLineResult, leftLineResult, rightLineResult);

    end_time = millis();
    time_diff = end_time - start_time;
    Serial.print("Time Difference: "); Serial.println(time_diff);

    error_correction(speed, FRLineResult, FLLineResult);

    digitalWrite(blueLEDPIN, HIGH);
    // delay(250);
    // digitalWrite(blueLEDPIN, LOW);
    // delay(250);

    

    //if (rightLineResult == 1 && leftLineResult == 1 && frontLineResult == 0 && time_diff > 3000){
    if (FLLineResult == 1 && FRLineResult == 1 && leftLineResult == 1 && rightLineResult == 0 && time_diff > 3000) { //FOR TESTING
      LMotor->setSpeed(0);
      RMotor->setSpeed(0);
      digitalWrite(blueLEDPIN, LOW);
      end = true;
    }
    
  }
}

void straight_to_branchRight(){
  end = false;
  long int start_time = millis();
  long int end_time = millis();
  long int time_diff = 0;
  int speed = 110;

  while (end == false){
    Serial.println("****BRANCH RIGHT****");

    int FLLineResult = digitalRead(frontLeftLineSensorPIN);
    int FRLineResult = digitalRead(frontRightLineSensorPIN);
    int leftLineResult = digitalRead(leftLineSensorPIN);
    int rightLineResult = digitalRead(rightLineSensorPIN);
    
    // testing_line_sensors(FLLineResult, FRLineResult, leftLineResult, rightLineResult);

    end_time = millis();
    time_diff = end_time - start_time;
    Serial.print("Time Difference: "); Serial.println(time_diff);

    error_correction(speed, FRLineResult, FLLineResult);

    digitalWrite(blueLEDPIN, HIGH);
    // delay(250);
    // digitalWrite(blueLEDPIN, LOW);
    // delay(250);

    

    //if (rightLineResult == 1 && leftLineResult == 1 && frontLineResult == 0 && time_diff > 3000){
    if (FLLineResult == 1 && FRLineResult == 1 && leftLineResult == 0 && rightLineResult == 1 && time_diff > 3000) { //FOR TESTING
      LMotor->setSpeed(0);
      RMotor->setSpeed(0);
      digitalWrite(blueLEDPIN, LOW);
      end = true;
    }
    
  }
}

void turn_right(int delay_time){
  end = false;
  long int start_time = millis();
  long int end_time = millis();
  long int time_diff = 0;

  while (end == false){
    Serial.println("START");

    int FLLineResult = digitalRead(frontLeftLineSensorPIN);
    int FRLineResult = digitalRead(frontRightLineSensorPIN);
    int leftLineResult = digitalRead(leftLineSensorPIN);
    int rightLineResult = digitalRead(rightLineSensorPIN);
    
    testing_line_sensors(FLLineResult, FRLineResult, leftLineResult, rightLineResult);

    end_time = millis();
    time_diff = end_time - start_time;
    Serial.print("Time Difference: "); Serial.println(time_diff);

    // error_correction(speed, FRLineResult, FLLineResult);

    LMotor->run(FORWARD);
    LMotor->setSpeed(80);
    delay(10);
    RMotor->run(BACKWARD);
    RMotor->setSpeed(80);
    delay(10);
    digitalWrite(blueLEDPIN, HIGH);
    // delay(250);
    // digitalWrite(blueLEDPIN, LOW);
    // delay(250);

    

  
    //if (FLLineResult == 1 && FRLineResult == 1 && leftLineResult == 1 && rightLineResult ==1 && time_diff > 2000) {
    if (FLLineResult == 1 && FRLineResult == 1 && time_diff > 1000) { //FOR TEST
      delay(delay_time);
      LMotor->setSpeed(0);
      RMotor->setSpeed(0);
      digitalWrite(blueLEDPIN, LOW);
      end = true;
    }
    
  }
}

void turn_left(int delay_time){
  end = false;
  long int start_time = millis();
  long int end_time = millis();
  long int time_diff = 0;

  while (end == false){
    Serial.println("START");

    int FLLineResult = digitalRead(frontLeftLineSensorPIN);
    int FRLineResult = digitalRead(frontRightLineSensorPIN);
    int leftLineResult = digitalRead(leftLineSensorPIN);
    int rightLineResult = digitalRead(rightLineSensorPIN);
    
    testing_line_sensors(FLLineResult, FRLineResult, leftLineResult, rightLineResult);

    end_time = millis();
    time_diff = end_time - start_time;
    Serial.print("Time Difference: "); Serial.println(time_diff);

    // error_correction(speed, FRLineResult, FLLineResult);

    LMotor->run(BACKWARD);
    LMotor->setSpeed(80);
    delay(10);
    RMotor->run(FORWARD);
    RMotor->setSpeed(80);
    delay(10);
    digitalWrite(blueLEDPIN, HIGH);
    // delay(250);
    // digitalWrite(blueLEDPIN, LOW);
    // delay(250);

  
    //if (FLLineResult == 1 && FRLineResult == 1 && leftLineResult == 1 && rightLineResult ==1 && time_diff > 2000) {
    if (FLLineResult == 1 && FRLineResult == 1 && time_diff > 1000) { //FOR TEST
      delay(delay_time);
      LMotor->setSpeed(0);
      RMotor->setSpeed(0);
      digitalWrite(blueLEDPIN, LOW);
      end = true;
    }
    
  }
}

