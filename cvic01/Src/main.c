#define sct_nla(x) do { if (x) GPIOB->BSRR = (1 << 5); else GPIOB->BRR = (1 << 5); } while (0)
#define sct_sdi(x) do { if (x) GPIOB->BSRR = (1 << 4); else GPIOB->BRR = (1 << 4); } while (0)
#define sct_clk(x) do { if (x) GPIOB->BSRR = (1 << 3); else GPIOB->BRR = (1 << 3); } while (0)
#define sct_noe(x) do { if (x) GPIOB->BSRR = (1 << 10); else GPIOB->BRR = (1 << 10); } while (0)

#include "stm32f0xx.h"



void sct_led(uint32_t value)
{
	sct_nla(1);

	for(int i = 0; i < 32; i++){
		sct_clk(0);

		// delay
		sct_sdi(value & (1<<i));
		// delay
		sct_clk(1);
	}

	// delay

	sct_nla(0);
}

void sct_init(void)
{
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODER4_0;
	GPIOB->MODER |= GPIO_MODER_MODER3_0;
	GPIOB->MODER |= GPIO_MODER_MODER5_0;
	GPIOB->MODER |= GPIO_MODER_MODER10_0;

	sct_led(0);
	sct_noe(0);
}



int main(void)
{
	sct_init();
	sct_led(0x7A5C36DE);
	while(1)
		;
}












/*
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define LED_TIME_BLINK 2000
#define LED_TIME_SHORT 100
#define LED_TIME_LONG 100

#include "stm32f0xx.h"

volatile uint32_t Tick;

void EXTI0_1_IRQHandler(void)
{
	if (EXTI->PR & EXTI_PR_PR0) { // check line 0 has triggered the IT
		EXTI->PR |= EXTI_PR_PR0; // clear the pending bit
		GPIOB->ODR ^= (1<<0); // toggle
	}
}

void SysTick_Handler(void)
{
	Tick++;
}

void blikac(void)
{
	static uint32_t delay;
	if (Tick > delay + LED_TIME_BLINK) {
		GPIOA->ODR ^= (1<<4);
		delay = Tick;
	}
}

void tlacitka_2()
{
	static uint32_t old_tick;

	if(Tick > old_tick+5){
		old_tick = Tick;
		static uint32_t off_time_s2;
		static uint32_t off_time_s1;
		static uint16_t debounce_1 = 0xFFFF;
		static uint16_t debounce_2 = 0xFFFF;
		static uint8_t on_1;
		static uint8_t on_2;


		debounce_1 <<= 1;
		debounce_2 <<= 1;

		if(GPIOC->IDR & (1<<1)) {
			debounce_1 |= 1;
		}

		if(GPIOC->IDR & (1<<0)) {
			debounce_2 |= 1;
		}

		if(debounce_1 == 0x7FFF) {
			GPIOA->BSRR = (1<<4);	// = rozsvietime LED1
			off_time_s1 = Tick + LED_TIME_LONG;
			on_1 = 1;
		}

		if(debounce_2 == 0x7FFF) {
			GPIOB->BSRR = (1<<0);	// = rozsvietime LED2
			off_time_s2 = Tick + LED_TIME_SHORT;
			on_2 = 1;
		}

	}

	if ((Tick > off_time_s1) && on_1)  {	// Podmienka ktora po uplynutom case
		GPIOA->BRR = (1<<4);	// vypne LED1
		on_1 = 0;
	}
	if ((Tick > off_time_s2) && on_2) {	// Podmienka ktora po uplynutom case
		GPIOB->BRR = (1<<0);	// vypne LED2
		on_2 = 0;
	}

}


int main()
{
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN | RCC_AHBENR_GPIOCEN; // clock enable

	GPIOA->MODER |= GPIO_MODER_MODER4_0; // LED1 = PA4, output
	GPIOB->MODER |= GPIO_MODER_MODER0_0; // LED2 = PB0, output
	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR0_0; // S2 = PC0, pullup
	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR1_0; // S1 = PC1, pullup
/*
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; // clock enable
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PC; // select PC0 for EXTI0
	EXTI->IMR |= EXTI_IMR_MR0; // mask
	EXTI->FTSR |= EXTI_FTSR_TR0; // trigger on falling edge
	NVIC_EnableIRQ(EXTI0_1_IRQn); // enable EXTI0_1

	SysTick_Config(8000); // 1 ms

	while(1) {
		blikac();
		tlacitka_2();
	}
}
*/







/*void one()
{
	int j;

	GPIOA->BSRR = (1<<5); // set
	for(j=0;j<100000;j++);

}

void zero()
{
	int j;
	GPIOA->BRR = (1<<5); // reset
	for(j=0;j<100000;j++);
}


int main(void)
{

	uint32_t data = 0b10101001110111011100101010000000;
	int32_t i;

	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER5_0;



	while(1){
		for(i=31;i>=0;i--){
			if(data & (1<<i)){
				one();
			}
			else {
				zero();
			}
		}

	}

}
*/

