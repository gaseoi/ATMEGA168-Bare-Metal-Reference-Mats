#include <AVR/io.h>
#include <util/delay.h> 
#include <avr/power.h>
#include "i2c.h"
#include "ssd1306.h"

int main(void){
    clock_prescale_set(clock_div_1);
    initI2C();
    initSSD();
    clearSSD();
    while(1){
      drawColon();
      drawTime(1, 2, 3, 4);
      drawBatteryShell();
      drawBatteryAlert();
      drawAlarmBasic();
      drawAlarmActive();

      _delay_ms(5000);
      flipDisplay();

      _delay_ms(5000);
      nonflipDisplay();
    }
    return 0;
}