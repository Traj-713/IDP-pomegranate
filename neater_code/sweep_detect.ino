void sweep(){
  
  end = false;
  long int start_time = millis();
  long int end_time = millis();
  long int time_diff = 0;

  button_sweep_state = 0;
  bool not_reach_end = true;

  float current_dist = 0;

  while (end == false){

    not_reach_end = true;
    start_time = millis();

    // ROTATE RIGHT
    while (end == false && not_reach_end == true){

      LMotor->run(FORWARD);
      RMotor->run(BACKWARD);
      LMotor->setSpeed(70);     // globalised speed variable
      RMotor->setSpeed(70);
      delay(10);    // why is there this delay?


      button_sweep_state = digitalRead(sweepButtonPIN);

      end_time = millis();
      time_diff = end_time - start_time;

      current_dist = sensor.getDistance();
      delay(50);

      if (detected(current_dist)) {     // detects block and breaks out of both while loops
        end == true;
      };      

      if (time_diff > 400) {                // breaks out of this while loop after initial right sweep
        not_reach_end = false;
      }

    }

    not_reach_end = true;
    start_time = millis();

    // ROTATE LEFT
    while (end == false && not_reach_end == true){

      LMotor->run(BACKWARD);
      RMotor->run(FORWARD);
      LMotor->setSpeed(70); 
      RMotor->setSpeed(70);
      delay(10);

      button_sweep_state = digitalRead(sweepButtonPIN);

      end_time = millis();
      time_diff = end_time - start_time;

      current_dist = sensor.getDistance();
      delay(50);

      if (detected(current_dist)) {
        end == true;
      };

      if (time_diff > 800) {                // breaks out of this while loop after left sweep
        not_reach_end = false;
      };      
      // delay(1000*pi*0.1* /(60*val) - calibrated pick up mechanism distance) This is supposed to use
                    // the distance from the robot to block obtained from the TOF sensor and calculate the time required for travel in the direction, towards the robot
      }

    }

    // grab block here

};

bool detected(int distance) {           // simple function for detecting block
    if (distance < 200) {
      Serial.println("DETECTED");              // detection parameter for block
      return true;
    }
    else {
      return false;
    }
}
