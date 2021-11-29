#include <LiquidCrystal.h>

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int main(){

  lcd.begin(16, 2);
  lcd.print("Hello world");

  return 0;
}
