/* 
Purpose       :  for this code to run 
                 The centre to centre distance between the Line sensors should be 11 to 11.5 cm
                 The Width of black tape(should not be shiny black tape) used is 4.8 to 5 cm
                 The Distance of Sensor LED from flat grond surface is 2 cm.

Library used  :  Adafruit Motor Shield library V1 version: 1.0.1
*/

#include <AFMotor.h>
#include <Servo.h>

// MACROS to for Debug print, while calibrating set its value to 1 else let it remain 0
#define DEBUG_PRINT 0

// MACROS to for Analog Input
#define LEFT_IR A0
#define RIGHT_IR A1

// MACROS to control the Robot
#define DETECT_LIMIT 300
#define FORWARD_SPEED 60
#define TURN_SHARP_SPEED 150
#define TURN_SLIGHT_SPEED 120
#define DELAY_AFTER_TURN 140
#define BEFORE_TURN_DELAY 10

// BO Motor control related data here
// Currently Motor are RUN Using M3 and M4 of the Shield and left Motor is connected to M3 and Right Motor is connected to M4 using IC2 of the Shield
AF_DCMotor motorL(3);  // Uses PWM0B pin of Arduino Pin 5 for Enable
AF_DCMotor motorR(4);  // Uses PWM0A pin of Arduino Pin 6 for Enable

// variables to store the Analog Values
int left_value;
int right_value;

// Set the Last Direction to Stop
char lastDirection = 'S';  

void setup() {

#if DEBUG_PRINT  
  Serial.begin(9600);
#endif  

  // Set the current speed of left Motor to 0
  motorL.setSpeed(0);
  // turn on motor
  motorL.run(RELEASE);
  // Set the current speed of Right Motor to 0
  motorR.setSpeed(0);
  // turn off motor
  motorR.run(RELEASE);

  // To provide starting push to Robot these values are set
  motorR.run(FORWARD);
  motorL.run(FORWARD);
  motorL.setSpeed(255);
  motorR.setSpeed(255);
  delay(40);  // delay of 40 ms
}


void loop() {
  left_value = analogRead(LEFT_IR);
  right_value = analogRead(RIGHT_IR);


#if DEBUG_PRINT
  // This is for debugging to check the Analog Inputs the DETECT_LIMIT MACRO value 300 is set by analysing the debug prints
  Serial.print(left_value);
  Serial.print(",");
  Serial.print(right_value);
  Serial.print(",");
  Serial.print(lastDirection);
  Serial.write(10);
#endif

  // Right Sensor detect black line and left not
  if (right_value >= DETECT_LIMIT && !(left_value >= DETECT_LIMIT)) {
    turnRight();
  }
  // Left Sensor detect black line and right not
  else if ((left_value >= DETECT_LIMIT) && !(right_value >= DETECT_LIMIT)) {
    turnLeft();
  }
  // both sensors doesn't detect black line
  else if (!(left_value >= DETECT_LIMIT) && !(right_value >= DETECT_LIMIT)) {
    moveForward();
  }
  // both sensors detect black line
  else if ((left_value >= DETECT_LIMIT) && (right_value >= DETECT_LIMIT)) {
    moveBackward();
  }
}

void moveForward() {
  if (lastDirection != 'F') {
    // To provide starting push to Robot when last direction was not forward
    motorR.run(FORWARD);
    motorL.run(FORWARD);
    motorL.setSpeed(255);
    motorR.setSpeed(255);
    lastDirection = 'F';
    delay(20);
  } else {
    // If the last direction was forward
    motorR.run(FORWARD);
    motorL.run(FORWARD);
    motorL.setSpeed(FORWARD_SPEED);
    motorR.setSpeed(FORWARD_SPEED);
  }
}

void moveBackward() {
  if (lastDirection != 'S') {
    // When stop is detected move further one time to check if its actual stop or not, needed when the robot turns
    motorR.run(FORWARD);
    motorL.run(FORWARD);
    motorL.setSpeed(255);
    motorR.setSpeed(255);
    lastDirection = 'S';
    delay(40);
  } else {
    // When stop is detected next time then sop the Robot
    motorL.setSpeed(0);
    motorR.setSpeed(0);
    motorL.run(RELEASE);
    motorR.run(RELEASE);
    lastDirection = 'S';
  }
}


void turnRight(void) {
  // If First time Right Turn is Taken
  if (lastDirection != 'R') {
    lastDirection = 'R';

    // Stop the motor for some time
    motorL.setSpeed(0);
    motorR.setSpeed(0);
    delay(BEFORE_TURN_DELAY);

    // take Slight Right turn
    motorL.run(FORWARD);
    motorR.run(BACKWARD);
    motorL.setSpeed(TURN_SLIGHT_SPEED);
    motorR.setSpeed(TURN_SLIGHT_SPEED);
  } else {
    // take sharp Right turn
    motorL.run(FORWARD);
    motorR.run(BACKWARD);
    motorL.setSpeed(TURN_SHARP_SPEED);
    motorR.setSpeed(TURN_SHARP_SPEED);
  }
  delay(DELAY_AFTER_TURN);
}

void turnLeft() {
  // If First time Left Turn is Taken
  if (lastDirection != 'L') {
    lastDirection = 'L';

    // Stop the motor for some time
    motorL.setSpeed(0);
    motorR.setSpeed(0);
    delay(BEFORE_TURN_DELAY);

    // take slight Left turn
    motorR.run(FORWARD);
    motorL.run(BACKWARD);
    motorL.setSpeed(TURN_SLIGHT_SPEED);
    motorR.setSpeed(TURN_SLIGHT_SPEED);
  } else {
    // take sharp Left turn
    motorR.run(FORWARD);
    motorL.run(BACKWARD);
    motorL.setSpeed(TURN_SHARP_SPEED);
    motorR.setSpeed(TURN_SHARP_SPEED);
  }
  delay(DELAY_AFTER_TURN);
}
