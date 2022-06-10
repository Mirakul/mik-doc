#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL

int main(){

  DDRB=255;
  DDRC=255;
  DDRD=255;
  TCCR0A = (1<<COM0A1)|(1<<WGM00);
  TCCR0B = (1<<CS00);

  for(int i=153; i<256; i++){
    OCR0A=i;
    _delay_ms(13);
  }

  return 0;
}
