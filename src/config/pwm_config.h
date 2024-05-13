#ifndef _PWM_CONFIG_H
#define _PWM_CONFIG_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define PWM_CHANNEL PB2

void init_pwm();
void pwm_set_duty(uint8_t duty);



#endif