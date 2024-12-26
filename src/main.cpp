#include <Arduino.h>
#include <TFT_eSPI.h>
#include <Wire.h>
#include <BH1750.h>

#define         SDA_PIN 44  // Define your custom SDA pin
#define         SCL_PIN 43  // Define your custom SCL pin

TFT_eSPI        tft = TFT_eSPI();
char            buf[20] = "";
BH1750          lightMeter;

void setup() {
    Serial.begin(115200);
    Wire.begin(SDA_PIN, SCL_PIN);  // Initialize I²C with custom pins
    lightMeter.begin();
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE);
    tft.drawString("BH1750 Lux Meter", 120, 20, 2);
    tft.drawString("Lux : ", 30, 60, 4);
}

void loop() {
    float lux = lightMeter.readLightLevel();
    sprintf(buf, "%.2f", lux);
    tft.fillRect(90, 60, 240, 240, TFT_BLACK);
    tft.drawString(buf, 90, 60, 4);
    delay(500);
}