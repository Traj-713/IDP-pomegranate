void error_correction(int speed, int FLLineResult, int FRLineResult) {
    if (FLLineResult == 1 && FRLineResult == 1) {
      LMotor->run(FORWARD);
      LMotor->setSpeed(speed);
      // delay(10);
      RMotor->run(FORWARD);
      RMotor->setSpeed(speed);
      // delay(10);
      Serial.print("Straight");
    } else if (FLLineResult == 1 && FRLineResult == 0)  {
      LMotor->run(FORWARD);
      LMotor->setSpeed(speed-50);
      // delay(10);
      RMotor->run(FORWARD);
      RMotor->setSpeed(speed);
      // delay(10);
      Serial.print("Derail to right");
    } else if (FLLineResult == 0 && FRLineResult == 1)  {
      LMotor->run(FORWARD);
      LMotor->setSpeed(speed);
      // delay(10);
      RMotor->run(FORWARD);
      RMotor->setSpeed(speed-50);
      // delay(10);
      Serial.print("Derail to right");
    }

}
