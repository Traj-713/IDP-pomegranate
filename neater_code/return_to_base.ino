bool back_to_node(){
  end = false;
  long int start_time = millis();
  long int end_time = millis();
  long int time_diff = 0;
  int speed = 120;
  bool grabbed = false;

  while (end == false){

    int FLLineResult = digitalRead(frontLeftLineSensorPIN);
    int FRLineResult = digitalRead(frontRightLineSensorPIN);
    int leftLineResult = digitalRead(leftLineSensorPIN);
    int rightLineResult = digitalRead(rightLineSensorPIN);
    
    //testing_line_sensors(FLLineResult, FRLineResult, leftLineResult, rightLineResult);

    end_time = millis();
    time_diff = end_time - start_time;
   // Serial.print("Time Difference: "); Serial.println(time_diff);

    error_correction_backward(speed, FRLineResult, FLLineResult);
    
    digitalWrite(blueLEDPIN, HIGH);


    if (FLLineResult == 1 && FRLineResult == 1 && leftLineResult == 1 && time_diff > 3000) { 
      LMotor->setSpeed(0);
      RMotor->setSpeed(0);
      digitalWrite(blueLEDPIN, LOW);
      end = true;
      if (FLLineResult == 1 && FRLineResult == 1 && leftLineResult == 1 && rightLineResult == 1){
        Serial.println("AT CROSS");
        return false;
      } else {
        Serial.println("At a normal node, not CROSS");
        return true;
      }
    }
  }
}

bool forward_to_node(){
  end = false;
  long int start_time = millis();
  long int end_time = millis();
  long int time_diff = 0;
  int speed = 120;
  bool grabbed = false;

  while (end == false){

    int FLLineResult = digitalRead(frontLeftLineSensorPIN);
    int FRLineResult = digitalRead(frontRightLineSensorPIN);
    int leftLineResult = digitalRead(leftLineSensorPIN);
    int rightLineResult = digitalRead(rightLineSensorPIN);
    
    //testing_line_sensors(FLLineResult, FRLineResult, leftLineResult, rightLineResult);

    end_time = millis();
    time_diff = end_time - start_time;
   // Serial.print("Time Difference: "); Serial.println(time_diff);

    error_correction(speed, FRLineResult, FLLineResult);
    
    digitalWrite(blueLEDPIN, HIGH);


    if (FLLineResult == 1 && FRLineResult == 1 && leftLineResult == 1 && time_diff > 3000) { 
      LMotor->setSpeed(0);
      RMotor->setSpeed(0);
      digitalWrite(blueLEDPIN, LOW);
      end = true;
      if (FLLineResult == 1 && FRLineResult == 1 && leftLineResult == 1 && rightLineResult == 1){
        Serial.println("AT CROSS");
        return true;
      } else {
        Serial.println("At a normal node, not CROSS");
        return false;
      }
    }
  }
}

void return_cross(){
  bool returned_to_cross = false;
  returned_to_cross = back_to_node();
  turn_left(150);

  while (returned_to_cross == false){

    returned_to_cross = forward_to_node();

    turn_right(150);
    
  }
}