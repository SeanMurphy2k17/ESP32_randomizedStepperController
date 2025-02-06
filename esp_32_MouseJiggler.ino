
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 512;  // change this to fit the number of steps per revolution
// for your motor

int randomTime = 0;
unsigned long previousMillis = 0;
int direction = 0;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 13, 12, 15, 14);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(30);
  // initialize the serial port:
  Serial.begin(115200);
}

void loop() 
{
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > randomTime) 
  {
    randomTime = getRandom(10, 100);
    direction = getRandom(-1, 1);
    previousMillis = currentMillis;
  }  
  myStepper.step(direction);
}
int getRandom(int minTime, int maxTime) {
  return random(minTime, maxTime + 1);
}

