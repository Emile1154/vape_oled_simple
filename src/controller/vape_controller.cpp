#include <controller/vape_controller.h>

static int8_t   power_mode = 0;
static uint16_t voltage = 0;
static uint16_t old_voltage = 0;
static uint8_t  charge_percent = 0;
static uint8_t  disable_counter = 0;
static uint8_t  lock = 0;    // lock vaping if low battery

static uint8_t duty_modes[3] = {85, 170, 220}; //power modes duty cycle

#define MAX_VOLT      4200 // in mV units lithium battery max voltage
#define MIN_VOLT      3000 // in mV units 

static void check_keypad(void){
    if(fire_btn_listener() && ! lock){
        pwm_set_duty(duty_modes[power_mode]);
    }else{
        pwm_set_duty(0);
    }
    if(up_btn_listener()){
        power_mode++;   
        if(power_mode > 2){
            power_mode = 0;
        }
    }
    if(down_btn_listener()){
        power_mode--;
        if(power_mode < 0){
            power_mode = 2;
        }
    }
    //------DISABLE DEVICE EVENT-------
    if(ena_btn_listener()){
        if(disable_counter == 1) {
            timer = millis();
        }
        disable_counter++;
        if(disable_counter >= 5){
            sleep_mcu();
            disable_counter = 0;
        }
    }
    if(disable_counter && millis() - timer > MAX_PER_MS){
        disable_counter = 0;
        timer = millis();
    }
}
uint64_t timer_measure = 0;
static void update_voltage(void){
    if(millis() - timer_measure > 100){
        voltage = 0.04*(1.1*1023*1000/read_adc()) + (1 - 0.04)*old_voltage;  //integral filter
        old_voltage = voltage;
        timer_measure = millis();
    }
#if DEBUG_ENABLED
    //Serial.println(voltage);
#endif
    if(voltage < MIN_VOLT){
        charge_percent = 0;
        lock = 1;
    }else{
        charge_percent = static_cast<uint8_t>((voltage - MIN_VOLT) * 100.0 / (MAX_VOLT - MIN_VOLT)); //calculate charge percent battery
        lock = 0;
    }
}

void init_vape(){
    init_display();
    init_keypad();
    init_adc();
    init_pwm();
#if DEBUG_ENABLED
    Serial.begin(9600);
#endif
    sleep_display();
    wake_display();
}


void vape_task(){
    while(sleep_state == 1){
        wake_puzzle();
    }
    if(sleep_state == 0){
        check_keypad();
        update_voltage();
        update_display(power_mode, charge_percent);
    }
}


