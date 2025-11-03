#include "timer.h"
#include <avr/io.h>

void initPWM(void){
    TCCR0A |= (_BV(WGM00)|_BV(WGM01)); // Fast PWM
    TCCR0A |= (_BV(COM0A1)); //Non inverted
    TCCR0B |= (_BV(CS01)); //8 prescaler ~4kHz in this case
}