//Testing out watchdog ISR as a wake trigger for the AVR in power down sleep
//LED at PB1
//Didnt change any fuse settings in AVRDUDESS, worked anyway.

#include <AVR/io.h>
#include <util/delay.h> 
#include <avr/power.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <avr/sleep.h>

ISR(WDT_vect){
  //Nothing
}

void enableWatchDogInterrupt(void){
  cli();
  wdt_reset();
  MCUSR &= ~_BV(WDRF); 
  WDTCSR |= _BV(WDCE) | _BV(WDE);
  WDTCSR = _BV(WDIE) | _BV(WDP0) |  _BV(WDP3); //Sets a timeout of 8 seconds
  sei();
}

void enterPowerDown(void){
  SMCR |= _BV(SM1);
  SMCR |= _BV(SE);
  sleep_mode();
}

int main(void){
    clock_prescale_set(clock_div_1);
    PORTB = (_BV(PB1));
    while(1){
      DDRB ^= (_BV(PB1));
      enableWatchDogInterrupt();
      enterPowerDown();
    }
    return 0;

}
