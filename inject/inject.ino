/* Code for inecting 

code available at: https://github.com/kanangit/injectorDrive

History

2023-01-25. Created by Kananovich

*/

#include "StepperK.h"

// Defining the Arduino pin numbers:
#define TRIGPIN 7
#define DIRPIN 8
#define PUPIN 9
#define LSCWPIN 10
#define LSCCWPIN 11
#define ACTIVATEMOTORPIN 12

const int stepsPerRevolution = 800;  // change this to fit the number of steps per revolution
// for your motor

// initialize the StepperK library:
StepperK myStepper(stepsPerRevolution, PUPIN, DIRPIN, LSCWPIN, LSCCWPIN, ACTIVATEMOTORPIN);

int steps_travel =  - stepsPerRevolution * 15;

void setup() {
  //set up the trig pin:
  pinMode(TRIGPIN, INPUT_PULLUP);
  // set the speed at xx rpm:
  myStepper.setSpeed(160);
  //Prepare for motion, activate the motor:
    digitalWrite(ACTIVATEMOTORPIN, HIGH);  
}

void loop() {
// inject only if the trigger signal is received:

    if (digitalRead(TRIGPIN) == LOW)
    {      
      myStepper.step(steps_travel);
    }



}
