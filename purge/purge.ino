/* Code for purging the syringe */

// Defining the Arduino pin numbers:
#define TRIGPIN 7
#define DIRPIN 8
#define PUPIN 9
#define LSCWPIN 10
#define LSCCWPIN 11
#define ACTIVATEMOTORPIN 12


#include "StepperK.h"

int totalStepsAllowed = 25600;
int stepsTaken = 0;

const int stepsPerRevolution = 800;  // change this to fit the number of steps per revolution
// for your motor

// initialize the StepperK library:
StepperK myStepper(stepsPerRevolution, PUPIN, DIRPIN, LSCWPIN, LSCCWPIN, ACTIVATEMOTORPIN);

//int steps_travel =  stepsPerRevolution * 15;
int steps_travel =  1;

void setup() {

  // set the speed at xx rpm:
  myStepper.setSpeed(160);
  // initialize the serial port:
  //Serial.begin(9600);
  //Prepare for motion, activate the motor:
    digitalWrite(ACTIVATEMOTORPIN, HIGH);  
}

void loop() {
// inject only if the trigger signal is received:
  while ((stepsTaken < totalStepsAllowed) && (digitalRead(LSCWPIN) == LOW))
  {
      myStepper.step(steps_travel);
      stepsTaken++;
  }


}
