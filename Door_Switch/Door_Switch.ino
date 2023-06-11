#define switchpin 12

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(12) == HIGH){
    Serial.println("Open"); 
  }
  if (digitalRead(12) == LOW){
    Serial.println("Closed");    
  }
}
