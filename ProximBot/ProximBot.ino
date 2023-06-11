#include <Adafruit_MotorShield.h>


Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *leftMotor = AFMS.getMotor(4);
// Set up the right motor on port M3
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);
int dpin = A3;

void setup() {
  Serial.begin(9600);
  AFMS.begin();  // create with the default frequency 1.6KHz
}

void loop() {
  if (digitalRead(dpin) == HIGH){
    Serial.println("Yes");
    leftMotor->setSpeed(40);
    rightMotor->setSpeed(40);
    
  }
  if (digitalRead(dpin) == LOW){
    Serial.println("No");
    leftMotor->setSpeed(0);
    rightMotor->setSpeed(0);
  }
  leftMotor->run(FORWARD); 
  rightMotor->run(FORWARD); 
}
