#include "stm32l475xx.h"
#include "delay.h"

int main()
{
    /* The project does not contain system_stem32l4xx.c */
    /* The program does not call SystemInit(), 
     * MSI is used as the clock source.
     * SYS_CLK is 4 Mhz
     */
    
    /* enable GPIO A clock gate */
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    /* set the mode of GPIOA pin 5 as general purpose output mode */
    /* set the mode as 00 first and then set as 01 */
    GPIOA->MODER &= ~GPIO_MODER_MODE5;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    while (1) {
        /* Toggle pin 5 in GPIOA */
        GPIOA->ODR ^= GPIO_ODR_OD5;
        delay(1000);
    }
    return 0;
}
