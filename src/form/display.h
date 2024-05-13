#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>
#include <stdint.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C

void init_display();
void update_display(uint8_t mode, uint8_t bat_percent);
void sleep_display();
void wake_display();


#endif