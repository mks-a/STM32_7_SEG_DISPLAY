#include "main.h"

volatile uint32_t* reg_ptr;

int main(void)
{
	//asm ("bkpt");
	init();
	
	while(1)
	{
		display();
	}
	
	return 0;
}

// this function initialize rcc registers for using gpio pins on port C
void gpio_port_c_rcc_init(void)
{
	// Note!!! should not reset port C on RCC_APB2RSTR register
	reg_ptr = (volatile uint32_t*) RCC_APB2ENR;
	*reg_ptr = 0x10;									// set bit 4 in RCC_APB2ENR register
}

// this function ititialize port C pin 14 for output
void init(void)
{
	uint32_t tmp;
	
	gpio_port_c_rcc_init();
	
	reg_ptr = (volatile uint32_t*) GPIOC_CRH;
	tmp = *reg_ptr;
	
	// Set PC13, PC14, PC15 for output (max speed 2Mhz), others for input
	tmp = 0x22200000;
	
	*reg_ptr = tmp;
}

// flash switch PC14 from high to low and from low to high
void display(void)
{
	uint8_t i;
	enum segment seg;
	uint8_t arr[4] = {SEG_2 & SEG_3, 
						SEG_1 & SEG_2 & SEG_7 & SEG_5 & SEG_4, 
						SEG_1 & SEG_2 & SEG_7 & SEG_3 & SEG_4, 
						SEG_6 & SEG_7 & SEG_2 & SEG_3};
	
	for(i = 0; i < 4; i++)
	{
		if(i == 0)
			seg = DIG_1;
		send_data(arr[i], seg);
		show_changes();
		delay();
		seg = seg << 1;
	}
}

void show_changes(void)
{
	uint16_t ports = 0;
	reg_ptr = (volatile uint32_t*) GPIOC_ODR;
	
	ports |= PC13; 
	*reg_ptr = ports;
		
	ports = 0; 
	*reg_ptr = ports;
}

void send_data(enum digit dig, uint8_t value)
{
	uint8_t buf = dig;
	uint8_t i, j;
	uint16_t ports = 0;								// uint16_t because highest 2 bytes are ignored by stm32
	reg_ptr = (volatile uint32_t*) GPIOC_ODR;
	
	for(i = 0; i < 2; i++)
	{		
		for(j = 0; j < 8; j++)
		{	
			if((buf & 0x01) > 0)
				ports = PC15;
			else
				ports = 0;
			*reg_ptr = ports;
			
			ports |= PC14; 
			*reg_ptr = ports;
		
			ports &= ~PC15;
			*reg_ptr = ports;
			
			ports &= ~PC14; 
			*reg_ptr = ports;
			
			buf = buf >> 1;
		}
		
		buf = value;
	}
}

void delay(void)
{
	int i = 0x000FFFFF;
	while(i > 0)
	{
		i--;
	}
}
	