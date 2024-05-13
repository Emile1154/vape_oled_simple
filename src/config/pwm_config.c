#include <config/pwm_config.h>

void init_pwm(){
    DDRB |= _BV(PWM_CHANNEL);
    PORTB &= ~_BV(PWM_CHANNEL);
    OCR1B = 0;
    TCCR1A |= _BV(COM1B1) | _BV(WGM10); //PWM not inverting
    TCCR1B |= _BV(WGM12) | _BV(CS10) | _BV(CS11); // divide by 64 FAST PWM
    //allow all interrupts
    sei();
}

void pwm_set_duty(uint8_t duty){
    OCR1B = duty;
}