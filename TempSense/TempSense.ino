#include <Adafruit_GFX.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"
#include <gfxfont.h>
#include <SPI.h>
#include <Wire.h>

#define OLED_RESET 4
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11

Adafruit_SSD1306 display(OLED_RESET);
DHT dht(DHTPIN, DHTTYPE);

void setup()  {                
  Serial.begin(9600);
  
  dht.begin(); //this starts the temperature sensor

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done

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
    
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    display.println("Failed to read from DHT sensor!");
    return;
  }

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.clearDisplay();
  display.print(" ");
  display.print(f);
  display.print(" F");
  display.println(" ");
  display.print(" ");
  display.print(h);
  display.print("% H");
  display.display();
  delay(250);
}

