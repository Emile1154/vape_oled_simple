#ifndef _KEYPAD_CONFIG_H_
#define _KEYPAD_CONFIG_H_

#include <stdint.h>
#include <avr/io.h>
#include <Arduino.h>
#include <config/pin_config.h>

void init_keypad();

uint8_t up_btn_listener();
uint8_t down_btn_listener();
uint8_t fire_btn_listener();
uint8_t ena_btn_listener();

void keypad_disable();
void keypad_enable();

#endif