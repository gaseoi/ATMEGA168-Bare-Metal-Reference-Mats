#include <avr/io.h>
#include <util/delay.h> 
#include <avr/power.h>
#include "USART.h"
#include "timer.h"
#include "ADC.h"

int main(void){
  clock_prescale_set(clock_div_1);
  initUSART();
  DDRD |= _BV(PD6); //LED for displaying PWM output
  initPWM();
  initADC();
  while(1){
    _delay_ms(500);
    uint8_t value8bit = readADC(); 
    printString("ADC value: ");
    printByte(value8bit);
    printString("\r\n");

    for (uint8_t i = 0; i <255; i++){
      _delay_ms(10);
      OCR0A = i;
    }

  }
}