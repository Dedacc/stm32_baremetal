#define PERIPH_BASE 																				(0x40000000UL) /*UL=unsigned(positive) long(data type)*/
#define AHB1PERIPH_OFFSET    															(0x00020000UL) /*memory address starts*/
#define AHB1PERIPH_BASE      																(PERIPH_BASE+AHB1PERIPH_OFFSET) /*starting address*/
#define GPIOA_OFFSET																			(0x0000UL)
#define GPIOA_BASE																					(AHB1PERIPH_BASE+GPIOA_OFFSET)
#define RCC_OFFSET																					(0x3800UL)
#define RCC_BASE																						(AHB1PERIPH_BASE + RCC_OFFSET)
/*Located the house now time to find rooms*/
#define AHB1EN_R_OFFSET                                                                  (0x30UL)
#define RCC_AHB1EN_R																			(*(volatile unsigned int *)(RCC_BASE+AHB1EN_R_OFFSET))
#define GPIOAEN																							(1U<<0) //0b 0000 0000 0000 0000 0000 0000 0000 0001//
#define MODE_R_OFFSET																		(0x00UL)
#define GPIOA_MODE_R																			(*(volatile unsigned int *)(GPIOA_BASE+MODE_R_OFFSET))
#define OD_R_OFFSET																				(0x14UL)
#define GPIOA_ODR																					((*(volatile unsigned int *)(GPIOA_BASE+OD_R_OFFSET)))
#define PIN5                                      																(1U<<5)
#define LED_PIN 																							PIN5

 int main(void)
{
	//1. Enable clock access to gpioa//
	 RCC_AHB1EN_R  |= GPIOAEN;

	 //2. set pa5 as output pin //
	 GPIOA_MODE_R  |= (1U<<10); //sets  bit 10 to 1 without changing other bits//
	 GPIOA_MODE_R &=~(1U<<11); //sets bit 11 to 0 without changing other bits//

	 while (1)
	 {
		 //sets pa5 to high//
		 GPIOA_ODR |= LED_PIN;


	 }

}






