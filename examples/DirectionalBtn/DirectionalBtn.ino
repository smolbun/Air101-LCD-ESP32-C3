#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include "arrow.h"

#define WIDTH 80
#define HEIGHT 160

TFT_eSPI tft = TFT_eSPI(); // Pins defined in Setup_Air101LCD_LuatOS_ESP32C3.h
TFT_eSprite arrowSprite = TFT_eSprite(&tft);
TFT_eSprite background = TFT_eSprite(&tft);
TFT_eSprite arrowRotatedSprite = TFT_eSprite(&tft);

#define backlightPin 0
#define selectBtn 4
#define upBtn 5
#define downBtn 9
#define leftBtn 13
#define rightBtn 8

void setup()
{
  Serial.begin(115200);

  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(upBtn, INPUT_PULLUP);
  pinMode(downBtn, INPUT_PULLUP);
  pinMode(leftBtn, INPUT_PULLUP);
  pinMode(rightBtn, INPUT_PULLUP);
  pinMode(backlightPin, OUTPUT);
  analogWrite(backlightPin, 128); // Set to 50% brightness, lower value = lower brightness

  tft.init();
  tft.setSwapBytes(true);
  tft.setRotation(2);
  tft.fillScreen(TFT_BLACK);

  background.createSprite(WIDTH, HEIGHT);
  background.setTextColor(TFT_SKYBLUE);
  arrowSprite.createSprite(48, 48);
  arrowSprite.setSwapBytes(true);
  arrowSprite.setPivot(24, 24);
  arrowRotatedSprite.createSprite(48, 48);

  Serial.println("Started!");
}

void loop()
{
  background.fillSprite(TFT_BLACK);
  // arrowRotatedSprite.fillSprite(TFT_BLACK);
  arrowSprite.pushImage(0, 0, 48, 48, arrow);

  if (digitalRead(upBtn) == LOW && digitalRead(leftBtn) == LOW)
  {
    Serial.println("upBtn & leftBtn pressed");
    arrowSprite.pushRotated(&arrowRotatedSprite, 225);
    background.drawString("up & left", 5, 10);
  }

  else if (digitalRead(upBtn) == LOW && digitalRead(rightBtn) == LOW)
  {
    Serial.println("upBtn & rightBtn pressed");
    arrowSprite.pushRotated(&arrowRotatedSprite, 315);
    background.drawString("up & right", 5, 10);
  }

  else if (digitalRead(downBtn) == LOW && digitalRead(leftBtn) == LOW)
  {
    Serial.println("downBtn & leftBtn pressed");
    arrowSprite.pushRotated(&arrowRotatedSprite, 140);
    background.drawString("down & left", 5, 10);
  }

  else if (digitalRead(downBtn) == LOW && digitalRead(rightBtn) == LOW)
  {
    Serial.println("downBtn & rightBtn pressed");
    arrowSprite.pushRotated(&arrowRotatedSprite, 45);
    background.drawString("down & right", 5, 10);
  }

  else if (digitalRead(selectBtn) == LOW)
  {
    Serial.println("selectBtn pressed");
    background.drawString("select", 5, 10);
  }

  else if (digitalRead(upBtn) == LOW)
  {
    Serial.println("upBtn pressed");
    arrowSprite.pushRotated(&arrowRotatedSprite, 270);
    background.drawString("up", 5, 10);
  }

  else if (digitalRead(downBtn) == LOW)
  {
    Serial.println("downBtn pressed");
    arrowSprite.pushRotated(&arrowRotatedSprite, 90);
    background.drawString("down", 5, 10);
  }

  else if (digitalRead(leftBtn) == LOW)
  {
    Serial.println("leftBtn pressed");
    arrowSprite.pushRotated(&arrowRotatedSprite, 180);
    background.drawString("left", 5, 10);
  }

  else if (digitalRead(rightBtn) == LOW)
  {
    Serial.println("rightBtn pressed");
    arrowSprite.pushRotated(&arrowRotatedSprite, 0);
    background.drawString("right", 5, 10);
  }
  else
  {
    Serial.println("nothing pressed");
  }

  arrowRotatedSprite.pushToSprite(&background, 15, 50);
  background.pushSprite(0, 0);
  delay(150);
}
