#include <config/keypad_config.h>


void init_keypad(){
    //set as input
    DDRD &= ~_BV(FIRE_BTN);
    DDRD &= ~_BV(ENA_BTN);
    DDRB &= ~_BV(UP_BTN);
    DDRB &= ~_BV(DOWN_BTN);
    //pull up resistor 
    PORTD |= _BV(FIRE_BTN);
    PORTD |= _BV(ENA_BTN);
    PORTB |= _BV(UP_BTN);
    PORTB |= _BV(DOWN_BTN);
}

uint64_t timer_up_dn = 0;
uint8_t up_btn_listener(){
    if(! (PINB & (1 << UP_BTN)) && millis() - timer_up_dn > 300){
        timer_up_dn = millis();
        return 1;
    }
    return 0;
}
uint8_t down_btn_listener(){
    if(! (PINB & (1 << DOWN_BTN)) && millis() - timer_up_dn > 300){
        timer_up_dn = millis();
        return 1;
    }
    return 0;
}
uint8_t fire_btn_listener(){
    if(! (PIND & (1 << FIRE_BTN)) ){
        return 1;
    }
    return 0;
}

uint8_t btn_pressed = 0;
uint32_t tim = 0;
uint8_t ena_btn_listener(){
    if(! (PIND & (1 << ENA_BTN)) && ! btn_pressed && millis() - tim > 150){
        btn_pressed = 1;
        tim = millis();
        return 1;
    }else if(PIND & (1 << ENA_BTN) && millis() - tim > 150){
        btn_pressed = 0;
        tim = millis();
    }
    return 0;
}


void keypad_disable(){
    PORTD &= ~_BV(FIRE_BTN);
    PORTB &= ~_BV(UP_BTN);
    PORTB &= ~_BV(DOWN_BTN);
}

void keypad_enable(){
    PORTD |= _BV(FIRE_BTN);
    PORTB |= _BV(UP_BTN);
    PORTB |= _BV(DOWN_BTN);
}