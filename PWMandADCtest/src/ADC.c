#include "ADC.h"
#include <avr/io.h>

void initADC(void){
    ADMUX = (_BV(REFS0)|_BV(MUX1)|_BV(MUX0)|_BV(ADLAR)); //Use AVCC, and connect PC3 to ADC
    ADCSRA = (_BV(ADEN)|_BV(ADPS2)|_BV(ADPS0)); // Set ADC enable bit, and set 32 division factor
    DIDR0 = _BV(ADC3D); //Disables digital input buffer

}

uint8_t readADC(void){
    ADCSRA |= _BV(ADSC); //starts a conversion
    loop_until_bit_is_clear(ADCSRA, ADSC); // Wait for conversion Do i ave to turn it to 1 afterwards?
    return ADCH;
}
