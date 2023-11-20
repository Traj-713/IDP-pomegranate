// make prototypes

void route(){
  turn_left(0);
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
void loop2(){
  straight_to_T();
  delay(500);
  turn_right(0);
  delay(500);
  straight_to_cornerRight();
  delay(500);
  straight_to_cornerRight();
  delay(500);
  straight_to_branchRight();
  delay(500);
  LMotor->run(FORWARD);
  LMotor->setSpeed(80);
  delay(10);
  RMotor->run(FORWARD);
  RMotor->setSpeed(80);
  delay(10);
  straight_to_branchLeft();
  delay(500); 
}

void loop3() {
  turn_right(0);
  delay(500);
  straight_to_cornerRight();
  delay(10);
  straight_to_cornerRight();
  delay(10);
  straight_to_branchRight();
  delay(10);
  LMotor->run(FORWARD);
  LMotor->setSpeed(80);
  delay(10);
  RMotor->run(FORWARD);
  RMotor->setSpeed(80);
  delay(10);
  straight_to_branchLeft();
  delay(500); 
}
void loop4() {
  straight_to_cornerRight();
  delay(500);
  straight_to_cornerRight();
  delay(500);
  straight_to_branchRight();
  delay(500);
  LMotor->run(FORWARD);
  LMotor->setSpeed(80);
  delay(10);
  RMotor->run(FORWARD);
  RMotor->setSpeed(80);
  delay(10);
  straight_to_branchLeft();
  delay(500);
}

void loop5() {
  straight_to_cornerRight();
  delay(500);
  straight_to_branchRight();
  delay(500);
  LMotor->run(FORWARD);
  LMotor->setSpeed(80);
  delay(10);
  RMotor->run(FORWARD);
  RMotor->setSpeed(80);
  delay(10);
  straight_to_branchLeft();
  delay(500); 
}

void loop6() {
  straight_to_branchRight();
  delay(500);
  LMotor->run(FORWARD);
  LMotor->setSpeed(80);
  delay(10);
  RMotor->run(FORWARD);
  RMotor->setSpeed(80);
  delay(10);
  straight_to_branchLeft();
  delay(500); 
}

void loop7() {
  LMotor->run(FORWARD);
  LMotor->setSpeed(80);
  delay(10);
  RMotor->run(FORWARD);
  RMotor->setSpeed(70);
  delay(10);
  straight_to_branchLeft();
  delay(500);
}

void loop8() {
  LMotor->run(FORWARD);
  LMotor->setSpeed(80);
  delay(10);
  RMotor->run(FORWARD);
  RMotor->setSpeed(70);
  delay(10);
}

void loop9() {
  straight_to_branchLeft();
  delay(500);
}
