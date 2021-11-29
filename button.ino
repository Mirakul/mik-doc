#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

//koristim PINC3 za očitavanje gumba

int main(){

  DDRC = 0;
  PORTC = 255; //spustam pull-up otpornike
  DDRB = 255;  //stavljam port na izlazno radi stanja visoke impedencije
  DDRD = 255;  //-||-

  //način 1
  if(~(PINC>>PINC3)&1){
    //do sth
  }

  //način 2
  if(!(PINC&(1<<PINC3))){
    //do sth
  }

  return 0;
}
