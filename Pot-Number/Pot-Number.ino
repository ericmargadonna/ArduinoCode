#include <SoftwareSerial.h>


int analogPin = 1;

int val = 0;

void setup() {
 Serial.begin(1200);
}

void loop() {
  val = analogRead(A1);
  
  Serial.println(val);
  
   if (val == 0){
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
   }
   
  if (val == 201){
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW); 
  } 
      
   delay(250);   
}
