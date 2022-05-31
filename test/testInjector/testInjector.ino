/*

testing the new class StepperK

 */

#include "StepperK.h"

const int stepsPerRevolution = 800;  // change this to fit the number of steps per revolution
// for your motor

// initialize the Stepper library on pins 8 through 11:
StepperK myStepper(stepsPerRevolution, 9, 8);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution * 10);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution * 10);
  delay(500);
}
