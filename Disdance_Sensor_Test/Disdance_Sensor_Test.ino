#include <Wire.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int dsensor = A1;

#define OLED_RESET 4
#define XPOS 0
#define YPOS 1
#define DELTAY 2

Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  Serial.begin(9600);
  Serial.println("Start of distance sensor");
  pinMode(dsensor, INPUT);
  
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println("Eric");
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();

  
}

void loop() {
  if (digitalRead(dsensor) == HIGH){
    Serial.println("NOTHING DETECTED");
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.setCursor(10,0);
    display.clearDisplay();
    display.println("NO");
    display.display();
 }
  
  if (digitalRead(dsensor) == LOW){
    Serial.println("OBJECT DETECTED");
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.setCursor(10,0);
    display.clearDisplay();
    display.println("Yes");
    display.display();
 }
  
    delay(500);
}
