void route(){
  turn_left(150);
  delay(500);
  straight_to_T();
  turn_right(150);
  delay(500);
  straight_to_cornerRight();
  delay(500);
  straight_to_cornerRight();
  delay(500);
  straight_to_branchRight();
  delay(500);
  LMotor->run(FORWARD);
  LMotor->setSpeed(80);
  delay(10000);//change this value depending on speed and length of square
  RMotor->run(FORWARD);
  RMotor->setSpeed(80);
  delay(10000);
  straight_to_branchLeft();
  delay(500);
}

