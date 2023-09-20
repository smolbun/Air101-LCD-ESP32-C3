#include <Arduino.h>
#include <TFT_eSPI.h> 
#include <SPI.h>

#define WIDTH 160
#define HEIGHT 80

TFT_eSPI tft = TFT_eSPI(); // Pins defined in Setup_Air101LCD_LuatOS_ESP32C3.h
TFT_eSprite disbuff = TFT_eSprite(&tft);

void setup()
{
  tft.init();
  tft.invertDisplay(true);
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);

  disbuff.createSprite(WIDTH, HEIGHT);
  disbuff.fillSprite(TFT_BLACK);
}

void loop()
{
  // disbuff.printf("Hello World"); // no position
  disbuff.drawString("Hello World!", 10, 10, 4);
  disbuff.drawString("0.96 TFT", 10, 40, 4);
  disbuff.pushSprite(0, 0);
  delay(1000);
}