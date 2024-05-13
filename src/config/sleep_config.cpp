#include <config/sleep_config.h>



uint64_t timer = 0;
volatile uint8_t sleep_state = 0;


// ISR(INT0_vect){
//     sleep_state = 1;
//     wake_puzzle();
// }

void wake(){
    sleep_state = 1;
}

// void init_int0(){
//      // set int0 as falling edge
//      EICRA |= _BV(ISC01);
//      EICRA &= ~_BV(ISC00);
//      //enable int0 vector
//      EIMSK |= _BV(INT0);
//      sei();
// }

void wake_puzzle(){
    detachInterrupt(0);
    uint8_t click = 0;
    //EIMSK &= ~_BV(INT0); // disable int0
    //adc_enable();
    timer = millis();
    while (click < 5)
    {
        if(ena_btn_listener()){
            click++;
        }
        if(millis() - timer > MAX_PER_MS){
            click = 0;
            sleep_state = 2;
            sleep_mcu();
            break;
        }    
    }
    if(click >= 5){
        wake_display();
        keypad_enable();
        sleep_state = 0;
    }
}

void sleep_mcu(){ 
    // adc_disable();
    keypad_disable();
    sleep_display();
    attachInterrupt(0, wake, FALLING);
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}