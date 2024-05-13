# vape_oled_simple
Ordered firmware for mcu ATmega328.
this device have 4 buttons:
 - FIRE    (  coil push button   )
 - UP      (increment power mode )
 - DOWN    (decrement power mode ) 
 - ENABLE  (5 click power down mcu, 5 click wake mcu)

power selection values default is 33%, 66% and 86%
These values are set in vape_controller.cpp.
<code>
static uint8_t duty_modes[3] = {85, 170, 220}; //power modes duty cycle
</code>
### Simulator files exist in test folder.
## Proteus model:
![image](https://github.com/Emile1154/vape_oled_simple/assets/42141666/7d0e2318-db03-4097-bec7-d5a36fd41780)
## SimulIDE model:
![image](https://github.com/Emile1154/vape_oled_simple/assets/42141666/fefb5e31-e5ed-475b-be86-cdacaffaaab0)
