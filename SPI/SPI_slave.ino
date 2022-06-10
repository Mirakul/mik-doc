//by Roko Vulinec, decringefied by Lobel Kotnik

#define MISO PORTB4
#define MOSI PORTB3
#define SCK PORTB5
#define SS PORTB2

#include<util/delay.h>
#include<stdio.h>

char SlaveRecive(void){
  while(!(SPSR & (1<<SPIF)));
  return SPDR;
}

void SlaveINIT(void){
  DD_SPI|=(1<<MISO);
  SPCR|=(1<<SPE);
}

int main(){
  char a;
  DDRC=255;
  DDRD=255;
  DDRB=255;
  SlaveINIT();
  while(1){
    a=SlaveRecive();
    Serial.begin(9600);
    Serial.println(a);
  }
}
