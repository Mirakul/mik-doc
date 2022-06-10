#define SPI_DDR DDRB
#define CS      PINB2
#define MOSI    PINB3
#define MISO    PINB4
#define SCK     PINB5

#include <util/delay.h>

void SPI_init()
{
    SPI_DDR |= (1 << CS) | (1 << MOSI) | (1 << SCK);
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0);
}

void SPI_masterTransmitByte(uint8_t data)
{
    SPDR = data;
    while(!(SPSR & (1 << SPIF)));
}

int main(){
  SPI_init();

  while(1){
    SPI_masterTransmitByte(69);
    _delay_ms(100);
  }

}
