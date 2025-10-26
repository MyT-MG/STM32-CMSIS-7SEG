#include "stm32f1xx.h"

uint8_t seg_code[10] = {
    0x3F, // 0 -> 0b00111111
    0x06, // 1 -> 0b00000110
    0x5B, // 2 -> 0b01011011
    0x4F, // 3 -> 0b01001111
    0x66, // 4 -> 0b01100110
    0x6D, // 5 -> 0b01101101
    0x7D, // 6 -> 0b01111101
    0x07, // 7 -> 0b00000111
    0x7F, // 8 -> 0b01111111
    0x6F  // 9 -> 0b01101111
};

void delay_ms(int t){
	for (int i = 0; i < t*800; i++){
		__NOP();
	}
}

int main(void){

	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	GPIOA->CRL =0x22222222;

	while(1){
		for (int i = 0; i < 10; i++){
			GPIOA->ODR = 0x00;
			GPIOA->ODR = seg_code[i];
			delay_ms(200);
		}
		for (int i = 9; i > -1; i--){
			GPIOA->ODR = 0x00;
			GPIOA->ODR = seg_code[i];
			delay_ms(200);
		}
	}
}
