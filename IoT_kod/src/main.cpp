#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>
#include <WiFi.h>

#define I2C_SDA 8
#define I2C_SCL 9


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Adafruit_BME280 bme;


const char* WIFI_SSID = "T-Mobile_Swiatlowod_8470"; 
const char* WIFI_PASSWORD = "89431802009858735166";



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

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Łącznie z WiFi...");
  display.display();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  } 
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Połączono z WiFi!");
  display.display();
  delay(2000);
    


}

void loop() {
  float temperatura = bme.readTemperature();
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  display.print("Temp: ");
  display.print(temperatura);
  display.print(" C");
  display.display();

  delay(2000);

}
