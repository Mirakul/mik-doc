//kod bi trebao biti 16B manji u RAMu i znatno krači

#define F_CPU 16000000UL                // definiramo frekvenciju rada procesora
#include <util/delay.h>                //librery za delay 
#include <LiquidCrystal.h>             //librery za LC display
#include <avr/io.h>                    //librery nezz za sta tocno ni da li je potreban ali je tu za svaki slucaj
#include <math.h>                       //librery za log2()
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);  // upisujemo ulaze za LCD, pošto ga spajamo na portC onda pišemo "A0,A1,A2,A3,A4,A5", da spajamo na PORTB islo bi "8,9,10,11,12,13", a za PORTD"0,1,2,3,4,5"

int matricna(void){                       //whippity whoppity sad je int
  char stupac=-1, redak=-1, radno=0;                                                              // pomoćne varijable ,brojaci za lakše pračenje redaka i stupca

while((redak++<4)&&(radno==0)){      //imamo 4 reda (od 0 do 3= 4) i trazimo u kojem stupcu je ,ako nađemo(kliknem gumb) promjeni se broj stupaca i prekida while petlju , redak ++ zato što da po redu gleda red po red,
//zamijenil 2-D array sa jednostavnom memory friendly matematikom
  PORTD&=~(128>>redak);                //slika 1 dio 
  _delay_ms(10);
  radno=(~PIND)&15;                    // slika 2.dio
  PORTD|=(128>>redak);                 //vraća PORTD u normalu (255)
}
  if(radno!=0)                        // ako je petlja prekinuta 
    return ((log(radno)/log(2))+1)+(4*(redak-1));   //slika 1. za algoritam racunanja brojeva i 2. za racunanje stupca, vjerovatno je moguce i samo sa log2(radno) u atmel studiu
  else return '\0';                    // ako nije ništa očitano ne vračaj ništa
}

int main(){
  PORTC=255;  // PORTC nam je ulazni (mogli smo pisati DDRC=0 ispred ali nije potrebno jer je po defoltu tako) i trebamo dići pul up otpornike pa ga moramo staviti u 255 
  PORTB=255;  // PORTB nam je ulazni (mogli smo pisati DDRB=0 ispred ali nije potrebno jer je po defoltu tako) i trebamo dići pul up otpornike pa ga moramo staviti u 255 
  DDRD=240;   // PORTD na mora pola biti ulaz, a pola izlaz pa DDRD= 11110000 što kad se zbroji iznosi 240 
  PORTD=255;  // stavljamo sve u jedinice ili 255 jer trebamo dići pull up otpornike i na jedinicama zabranjujemo tok struje
  char a[2];     // potrebna varijabla
  int gg;
  lcd.begin(16,2);   //namještavamo LCD
  
  while(1){ 
    gg = matricna();
    lcd.clear();
    lcd.print(gg);
    _delay_ms(1000);
    //sprintf(a, "%d", matricna());  //u a pisemo vrijednost funkcije
    if(a[0]!='\0'){  //ako ništa nije kliknuto, nista ne ispisuje
      lcd.clear(); // čisti LCD od priješnjeg ispisa
      lcd.print(a);
    }
  }
}