#define F_CPU 16000000UL                // definiramo frekvenciju rada procesora
#include <util/delay.h>                //librery za delay 
#include <LiquidCrystal.h>             //librery za LC display
#include <avr/io.h>                    //librery nezz za sta tocno ni da li je potreban ali je tu za svaki slucaj
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);  // upisujemo ulaze za LCD, pošto ga spajamo na portC onda pišemo "A0,A1,A2,A3,A4,A5", da spajamo na PORTB islo bi "8,9,10,11,12,13", a za PORTD"0,1,2,3,4,5"

char matricna(void){                                                                              //stvaramo funkciju "char"-vrsta izlaznog podatka, matricna-ime funkcije , void-ulazni podatci(nema ih) 
  char znakovi[4][4]={{'1','2','3','4'},{'5','6','7','8'},{'9','a','b','c'},{'d','e','f','g'}};   // stvaramo u funkciji 4 polja u kojima se nalaze po četri polja i odma upisujemo vrijednosti tako da je 3 polje 1 polja =3, 4 polje 3 polja= c
  char stupac=-1, redak=-1, radno=0;                                                              // pomoćne varijable ,brojaci za lakše pračenje redaka i stupca

while((redak++<4)&&(stupac==-1)){      //imamo 4 reda (od 0 do 3= 4) i trazimo u kojem stupcu je ,ako nađemo(kliknem gumb) promjeni se broj stupaca i prekida while petlju , redak ++ zato što da po redu gleda red po red,
  PORTD&=~(128>>redak);                //slika 1 dio 
  _delay_ms(10);
  radno=(~PIND)&15;                    // slika 2.dio
  if(radno!=0) {                       //ako je došlo do promjene radno će biti različito od 0 i petlja ce provesti provjeru 
    if(radno==8) stupac=0;             //prema vrijednosti radno određujemo u kojem je stupcu i ako je jedna tipka kliknuta onda je vrijednost stupca promjenjena i prekida se while petlja
    else if(radno==4) stupac=1;
    else if(radno==2) stupac=2;
    else stupac=3;
  }
  PORTD|=(128>>redak);                 //vraća PORTD u normalu (255)

}

  if(stupac!=-1)                        // ako je petlja prekinuta 
    return(znakovi[redak-1][stupac]);   // daj podatke van,  redak-1 jer se petlja prekida nakon što se redak poveća za jedan previse pa ga trebamo vratit 
  else return('\0');                    // ako nije ništa očitano ne vračaj ništa
}

int main(){
  PORTC=255;  // PORTC nam je ulazni (mogli smo pisati DDRC=0 ispred ali nije potrebno jer je po defoltu tako) i trebamo dići pul up otpornike pa ga moramo staviti u 255 
  PORTB=255;  // PORTB nam je ulazni (mogli smo pisati DDRB=0 ispred ali nije potrebno jer je po defoltu tako) i trebamo dići pul up otpornike pa ga moramo staviti u 255 
  DDRD=240;   // PORTD na mora pola biti ulaz, a pola izlaz pa DDRD= 11110000 što kad se zbroji iznosi 240 
  PORTD=255;  // stavljamo sve u jedinice ili 255 jer trebamo dići pull up otpornike i na jedinicama zabranjujemo tok struje
  char a;     // potreebna varijabla
  lcd.begin(16,2);   //namještavamo LCD
  
while(1){ 
a= matricna();  // pozivamo funkciju i varijabla a dobiva izlaznu vrijednost f-ije matricna
  if (a!='a'&& a!='b'&& a!='c'&& a!='d'&& a!='e'&& a!='f'&& a!='g'&& a!='\0'){ // provjerava uvjete(a!='\0' je tu da ako nije upisan broj onda pamti onaj zadnje upisani, da nema toga stalno briše)
 lcd.clear(); // čisti LCd od priješnjeg ispisa
 lcd.print(a); // printa vrijednost a=>izlaznu vrijednost f-ije matricna
  }                    // dolje navedene f-ije su za sve dvoznamenkaste brojeve koje će f-ija matricna očitati kao slova,a ove dolje će slova pretvoriti u brojeve
   else if (a=='a'){
    lcd.clear();
    lcd.print(10);
  }
    else if (a=='b'){
    lcd.clear();
    lcd.print(11);
  }
    else if (a=='c'){
    lcd.clear();
    lcd.print(12);
  }
    else if (a=='d'){
    lcd.clear();
    lcd.print(13);
  }
    else if (a=='e'){
    lcd.clear();
    lcd.print(14);
  }
    else if (a=='f'){
    lcd.clear();
    lcd.print(15);
  }
  else if (a=='g'){
    lcd.clear();
    lcd.print(16);
  }
}
}