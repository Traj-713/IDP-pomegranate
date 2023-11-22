/*
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2
---->	http://www.adafruit.com/products/1438
*/

#include <Adafruit_MotorShield.h>
#include <Servo.h>

#include "DFRobot_VL53L0X.h"
DFRobot_VL53L0X sensor;

#define MAX_RANGE (520)//the max measurement value of the module is 520cm(a little bit longer than effective max range)
#define  ADC_SOLUTION (1023.0)

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *RMotor = AFMS.getMotor(1);
Adafruit_DCMotor *LMotor = AFMS.getMotor(2);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

Servo clawServo;
// clawServo.attach(9);
int servoPos = 0;

int dist_t = 0;
int sensity_t = 0;


bool end = false;
bool button_pressed = false;
int buttonstate = 0;
int button_sweep_state = 0;


const int frontLeftLineSensorPIN = 3;
const int frontRightLineSensorPIN = 2;
const int leftLineSensorPIN = 4;
const int rightLineSensorPIN = 5;
const int blueLEDPIN = 6; //moving; return
const int greenLEDPIN = 7; //non-magnetic
const int redLEDPIN = 8; //magnetic
const int buttonPIN = 10;
const int sweepButtonPIN = 11;
const int magnetPIN = 12;
const int sensityPin = A0;



bool line_blocks = false;
bool return_to_base = false;
bool magnetic = false;
int speed = 160;

int turn_delay = 0;

// setting up prototype functions. stops rare error...

bool grab_block();
void sweep();
bool detected();
void error_correction();
void error_correction_backward();
void claw();

void line_route();
void straight_to_T();
void straight_to_cross();
void straight_to_cornerRight();
void straight_to_cornerLeft();
void straight_to_branchLeft();
void straight_to_branchRight();
void turn_right(int delay_time);
void turn_left(int delay_time);

void return_cross();
bool back_to_node();
bool forward_to_node();



void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");
  Wire.begin();
  sensor.begin(0x50);

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");

  // Set the speed to start, from 0 (off) to 255 (max speed)
  LMotor->setSpeed(50); 
  RMotor->setSpeed(50);
  LMotor->run(BACKWARD);
  RMotor->run(BACKWARD);
  // turn on motor
  LMotor->run(RELEASE);
  RMotor->run(RELEASE);

  clawServo.attach(9);


  // setting pinmodes for line sensors
  pinMode(frontLeftLineSensorPIN, INPUT);
  pinMode(frontRightLineSensorPIN, INPUT);
  pinMode(leftLineSensorPIN, INPUT);
  pinMode(rightLineSensorPIN, INPUT);

  pinMode(blueLEDPIN, OUTPUT);
  //clawServo.attach(5);

  sensor.setMode(sensor.eContinuous,sensor.eHigh);
  //Laser rangefinder begins to work
  sensor.start();

  int distance = 0;



  int speed = 120;

  bool line_blocks = true;
}

void loop() {

  while (button_pressed == false){
    delay(100);
    buttonstate = digitalRead(buttonPIN);

    if (buttonstate == HIGH){
      button_pressed = true;
    }
  }

  //Serial.println("Button Pressed");


  //delay(1000);

  Serial.print("START");

  return_to_base = false;

  if (line_blocks = true) {

    //claw();
    line_route();
    // turn_left(1000);
    // delay(1000);

    // straight_to_T();
    // delay(1000);

    // turn_right(1000);
    // delay(1000);

    // straight_to_cross();
    // delay(100000);
      }

  else {    // function for finding blocks in middle of open space
    sweep();
  }

}


void testing_line_sensors (int FLLineResult, int FRLineResult, int leftLineResult, int rightLineResult){
    Serial.print("Front Left: "); Serial.println(FLLineResult);
    Serial.print("Front Right: "); Serial.println(FRLineResult);
    Serial.print("Left: "); Serial.println(leftLineResult);
    Serial.print("Right: "); Serial.println(rightLineResult);
}












  //   Serial.println("START");

  //   int FLLineResult = digitalRead(frontLeftLineSensorPIN);
  //   int FRLineResult = digitalRead(frontRightLineSensorPIN);
  //   int leftLineResult = digitalRead(leftLineSensorPIN);
  //   int rightLineResult = digitalRead(rightLineSensorPIN);
    
  //   Serial.print("Front Left: "); Serial.println(FLLineResult);
  //   Serial.print("Front Right: "); Serial.println(FRLineResult);
  //   Serial.print("Left: "); Serial.println(leftLineResult);
  //   Serial.print("Right: "); Serial.println(rightLineResult);

  //   end_time = millis();
  //   time_diff = end_time - start_time;
  //   Serial.print("Time Difference: "); Serial.println(time_diff);


  // }
  // turn_right(0);
  // delay(1000);
  // turn_left(0);
  // delay(100);
  // turn_left(0);
  // delay(1000);
  // turn_right(0);




void move_to_block(){
  long int start_time = millis();
  long int end_time = millis();
  long int time_diff = end_time - start_time;

  Serial.println("MOVE TO BLOCK");

  while (time_diff < 3000){
    end_time = millis();
    time_diff = end_time - start_time;

    LMotor->run(FORWARD);
    LMotor->setSpeed(120);
    delay(10);
    RMotor->run(FORWARD);
    RMotor->setSpeed(120);
    delay(10);
  }
  LMotor->setSpeed(0);
  RMotor->setSpeed(0);
  delay(3000);

  move_back(time_diff);

}

void move_back(int duration){         // 
  long int start_time = millis();
  long int end_time = millis();
  long int time_diff = end_time - start_time;

  Serial.println("MOVE TO BLOCK");

  while (time_diff < duration){
    end_time = millis();
    time_diff = end_time - start_time;

    LMotor->run(BACKWARD);
    LMotor->setSpeed(120);
    delay(10);
    RMotor->run(BACKWARD);
    RMotor->setSpeed(120);
    delay(10);
  }
  LMotor->setSpeed(0);
  RMotor->setSpeed(0);

}



