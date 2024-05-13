#include <form/display.h>
#define STARTING_TIME 10000 // wait 10 seconds for per measuring voltage
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire,-1);
void init_display(){
    init(); //init arduino core
    if(! display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        for(;;);
    }
    display.clearDisplay();
    display.display();
    display.setTextColor(SSD1306_WHITE);
    display.setTextWrap(false);
    display.setRotation(1);
}

const char msg[] = "LOW BATTERY"; 
static void low_battery_display(){
    display.clearDisplay();
    display.setTextSize(1);
    for(uint8_t i = 0; i < strlen(msg); i++){
        display.setCursor(14, 10+i*10);
        display.println(msg[i]);
    }
    display.display();
}

/*
   0         32
    ---------> x
   |  MODE:
   |    N
   |  _---_
   |  |   |
   |  |   |
   |  |___|
   |    N%
   V
 y 128

*/
void update_display(uint8_t mode, uint8_t bat_percent){
    if(! bat_percent && millis() > STARTING_TIME ){
        low_battery_display();
        return;
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(4, 5);
    display.println("MODE");
    display.setTextSize(2);
    display.setCursor(11, 20);
    display.println(mode);

    //battery draw
    display.fillRect(11, 47, 10, 3, SSD1306_WHITE);
    display.fillRect(6, 50, 20, 50, SSD1306_WHITE);
    uint8_t len = map(bat_percent, 0, 100, 47, 0);
    display.fillRect(8, 52, 16, len, SSD1306_BLACK);
    
    //battery percent
    display.setTextSize(1);
    display.setCursor(8, 110);
    display.print(bat_percent);
    display.println("%");

    display.display();
}

void sleep_display(){
    display.clearDisplay();
    display.ssd1306_command(SSD1306_DISPLAYOFF);
}

void wake_display(){
    display.clearDisplay();
    display.ssd1306_command(SSD1306_DISPLAYON);
}