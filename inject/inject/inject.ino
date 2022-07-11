/*

testing the new class StepperK
scukko
 */

#include "StepperK.h"

const int stepsPerRevolution = 800;  // change this to fit the number of steps per revolution
// for your motor

// initialize the Stepper library on pins 9 and 8:
StepperK myStepper(stepsPerRevolution, 9, 8, 10, 11);

//define the trigger pin
const int trigPin = 7;

int steps_travel = stepsPerRevolution * 5;

void setup() {
  //set up the trig pin:
  pinMode(trigPin, INPUT_PULLUP);
  // set the speed at xx rpm:
  myStepper.setSpeed(10);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
// inject only if the trigger signal is received:

    if (digitalRead(trigPin) == LOW)
    {
      Serial.println("clockwise");
      myStepper.step(steps_travel);
      delay(500);
    }



}
