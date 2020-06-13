#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);

void setup(){
    oled.begin(0x3c);
    Serial.begin(9600);
}

void loop(){

    for(int x = 1 ;x < 128;x++)
    {
    oled.clearDisplay();
    oled.setCursor(x,10);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(3);
    oled.print("Hello");
    
    oled.display();
    }   
}//commit 