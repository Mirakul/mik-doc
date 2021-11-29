//ima koju greškicu al mozd si neko može od tud neš izvuč

#include <avr/io.h>
#include <LiquidCrystal.h>
#include <stdio.h> //za sprintf
#include <util/delay.h>
#define F_CPU 16000000UL

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
unsigned char a;
int p;

int povecaj(int b){
  if (p+b<=40)
    p=p+b;
  else
    p=40;
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(p);

  return p;
}

int smanji(int c){
  if(p-v>=5)
    p=p-c;
  else
    p=0;
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(p);

  return p;
}

int main(){

  DDRD = 255;
  PORTD = 255;
  PORTC = 255;

  int i=3, j=5;

  while(1){
    if((~(PINC>>PINC3)&1)&&a=0){
      _delay_ms(500);
      a=1;
      if((~PINC>>PINC3)&1)&&a==1){
        povecaj(i);
      }
    }
    if((~(PINC>>PINC4)&1)&&a==0){
      _delay_ms(500);
      a=1;
      if((~(PINC>>PINC4)&1)&&a==1){
        smanji(j);
      }
    }
  }

  return 0;
}
