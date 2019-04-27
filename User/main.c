#include "1986be9x_config.h"
#include "1986BE9x.h"
#include "1986BE9x_uart.h"
#include "1986BE9x_port.h"
#include "1986BE9x_rst_clk.h"
#include "1986BE9x_it.h"
#include "mlt_lcd.h"
#include "MilFlash.h"

void Led_init (void)
{
  RST_CLK->PER_CLOCK |=(1<<23);                   //Включаем тактирование порта C.
	PORTC->OE |= 1;                                 //Порт - выход.
	PORTC->ANALOG |= 1;                             //Порт - цифоровой. 
	PORTC->PWR |= 1;                                //Порт - медленный режим.
}

int main (void)
{
	Led_init();                                     //Инициализируем ножку 0 порта C для светодиода. 
	
  while (1)
	{
		PORTC->RXTX |= 1;
		for (uint32_t Loop; Loop<0xFFFFF; Loop++){}
		PORTC->RXTX = 0;
	  for (uint32_t Loop; Loop<0xFFFFF; Loop++){}
	}
}
