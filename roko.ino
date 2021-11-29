//ćika kauzlarić provjerio, točno je
#include <avr/io.h>
#include <LiquidCrystal.h>
#include <stdio.h> //za sprintf
#include <util/delay.h>
#define F_CPU 16000000UL

void ispis(void);
int povecaj(int);
int smanji(int);
char b[12];
int a=27, p, s, x=5, y=3;

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int main(){

  DDRD = 255;
  PORTD = 255;
  PORTC = 255;

  lcd.begin(16, 1);
  sprintf(b, "VARIJABLA=%d", a);
  lcd.print(b);

  while(1){
    if(~(PINC>>PINC3)&1){
      _delay_ms(30);
      a=povecaj(x);
      ispis();
    }
    if(~(PINC>>PINC4)&1){
      _delay_ms(30);
      a=smanji(x);
      ispis();
    }
  }
}

int povecaj(int x){
  if (40-a>=5)
    p=a+x;
  else
    p=40;
    
  return p;
}

int smanji(int c){
  
  if(~(8-a)>=3)
    s=a-y;
  else
    s=3; 
    
  return y;
}

void ispis(void){

  lcd.clear();
  sprintf(b, "VARIJABLA=%d", a);
  ldc.print(b);
  
}
