#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL

ISR(TIMER1_OVF_vect){
  TCNT1=39536;
  if(OCR0A<255)
    OCR0A++;
}

int main(){

  DDRB=255;
  DDRC=255;
  DDRD=255;
  
  TCCR0A = (1<<COM0A1)|(1<<WGM00);
  TCCR0B = (1<<CS00);

  TCCR1A = 0;
  TCCR1B = (1<<CS11);
  TCCR1C = 0;
  TCNT1 = 0;

  TIMSK1 = 1;
  
  OCR0A=153;

  sei();

  while(1);

  return 0;
}
