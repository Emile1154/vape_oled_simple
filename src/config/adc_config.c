#include <config/adc_config.h>

uint32_t middle_val = 0;
#define NUM_CONV 20

void init_adc(void){
    ADCSRA |= ( 1 << ADEN );
    ADMUX  |= _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);   
    ADMUX  &= ~(1 << ADLAR);
}

uint16_t read_adc(){
    middle_val = 0;
    for(uint8_t i = 0 ; i < NUM_CONV; i++){
        ADCSRA |= ( 1 << ADSC );
        while(ADCSRA & (1 << ADSC));
        middle_val =  middle_val + ADC;
    }
    return middle_val / NUM_CONV;
}

void adc_disable(){
    ADCSRA &= ~( 1 << ADEN );
}

void adc_enable(){
    ADCSRA |= ( 1 << ADEN );
}