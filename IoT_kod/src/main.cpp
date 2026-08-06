#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>

#define I2C_SDA 8
#define I2C_SCL 9


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Adafruit_BME280 bme;



int myFunction(int, int);

void setup() {
  Wire.begin(I2C_SDA, I2C_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true); 
  }
  
  display.clearDisplay();
  display.display();

  if (!bme.begin(0x76, &Wire)) {
    while (true); 
  }
}

void loop() {

}