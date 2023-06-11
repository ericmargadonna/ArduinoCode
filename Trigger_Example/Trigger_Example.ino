

/*
Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Wire.h>
#include <Servo.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

Servo myservo;  // create servo object to control a servo
                // twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int dpin = A3;

void setup()
{
  AFMS.begin();
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{  
  //myservo.write(180);
  myMotor->setSpeed(100);
  myMotor->run(FORWARD);
  delay(1000);
  myservo.write(0);
  delay(1000);
  /*if (digitalRead(dpin) == HIGH){
    myservo.write(180);    
  }
  else{
    myservo.write(0);
  }*/
}
