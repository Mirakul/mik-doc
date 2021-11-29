#include <avr/io.h>
#include <LiquidCrystal.h>
#include <stdio.h> //za sprintf

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //kao argument idu brojevi pinova na koje se spaja LCD

char a[12];
int i=5;

int main(){

  lcd.begin(16, 2);
  sprintf(a, "VRIJEDNOST=%d", i); //radi isto kao printf iz računalstva, osim što umjesto da ispisuje rezultat, stavlja ga u varijablu a
  lcd.print(a);

  return 0;
}
