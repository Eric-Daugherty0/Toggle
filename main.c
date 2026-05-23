//#include <stdint.h>
//
//int main(void) {
//	/* USER CODE BEGIN 1 */
//	//Creating pointer variables for the registers
//	uint32_t *pClkCtrlreg = (uint32_t*)0x40023830;
//	uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
//	uint32_t *pPortDOutReg = (uint32_t*)0x40020C14;
//	//1. enable the clock for GPIOD peripheral in the AHB1NER
//	//uint32_t temp = *pClkCtrlreg;
//	//(Read operation) Dereferencing the pointer and storing it in temp.
//	//temp = temp | 0x008; //modify
//	//*pClkCtrlreg = temp;//write back
//	//all that eqauls
//	*pClkCtrlreg |= 0x08;
//	//2. configure the mode of the IO pins as output
//	//a. clear the 24th and 25th bit positions
//	*pPortDModeReg &= 0xFCFFFFFF;
//	//b. make the 24th bit position as 1 (set)
//	*pPortDModeReg |= 0x01000000;
//	//Set 12th bit of the output register data to make I/O pin 12 HIGH
//	*pPortDOutReg |= 0x1000;
//
//	while(1);
//
//}

#include <stdint.h>

int main(void)
{
    // RCC AHB1ENR register
    volatile uint32_t *pClkCtrlReg = (uint32_t*)0x40023830;

    // GPIOA registers
    volatile uint32_t *pPortAModeReg = (uint32_t*)0x40020000;
    volatile uint32_t *pPortAOutReg  = (uint32_t*)0x40020014;

    // 1. Enable GPIOA clock
    *pClkCtrlReg |= (1 << 0);

    // 2. Configure PA5 as output

    // Clear bits 11:10
    *pPortAModeReg &= ~(3 << 10);

    // Set 01 for output mode
    *pPortAModeReg |= (1 << 10);

    while(1){
		// 3. Set PA5 HIGH
		*pPortAOutReg |= (1 << 5);

		//Introduce a delay
		//This loop executes 10000k times.
		for(uint32_t i = 0; i < 300000 ; i++);

		//Turn off the LED
		*pPortAOutReg &= ~(1 << 5);

		for(uint32_t i = 0; i < 300000 ; i++);
	}

}
