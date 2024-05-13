#ifndef _SLEEP_CONFIG_H_
#define _SLEEP_CONFIG_H_

#include <Arduino.h>
//#include <avr/sleep.h>
#include <config/keypad_config.h>
#include <form/display.h>
extern "C" {
    #include <config/pin_config.h>
    #include <config/pwm_config.h>
    #include <config/adc_config.h>
}
#include <LowPower.h>

extern volatile uint8_t sleep_state;
extern uint64_t timer;
#define MAX_PER_MS 3500

ISR(INT0_vect);
void init_int0();
void wake_puzzle();
void sleep_mcu();

#endif