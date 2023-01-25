/* Code purging the syringe */

// Defining the Arduino pin numbers:
#define TRIGPIN 7
#define DIRPIN 8
#define PUPIN 9
#define LSCWPIN 10
#define LSCCWPIN 11
#define ACTIVATEMOTORPIN 12


#include "StepperK.h"

const int stepsPerRevolution = 800;  // change this to fit the number of steps per revolution
// for your motor

// initialize the StepperK library:
StepperK myStepper(stepsPerRevolution, PUPIN, DIRPIN, LSCWPIN, LSCCWPIN, ACTIVATEMOTORPIN);

//define the trigger pin
const int trigPin = 7;

int steps_travel =  stepsPerRevolution * 15;
//int steps_travel =  25200;

void setup() {
  //set up the trig pin:
  pinMode(trigPin, INPUT_PULLUP);
  // set the speed at xx rpm:
  myStepper.setSpeed(160);
  // initialize the serial port:
  //Serial.begin(9600);
}

void loop() {
// inject only if the trigger signal is received:

    if (digitalRead(trigPin) == LOW)
    {
      
      myStepper.step(steps_travel);
    }



}
