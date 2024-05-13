#ifndef _ADC_CONFIG_H
#define _ADC_CONFIG_H

#include <stdint.h>
#include <avr/io.h>

void     init_adc();
uint16_t read_adc();

void adc_disable();
void adc_enable();
#endif