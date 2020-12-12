#include<stdint.h>
#include"stm32l475xx.h"
#include"system_stm32l4xx.h"

#include"sys_tick.h"
#include"delay.h"

int main()
{
    sys_tick_init();
    
    /* Enable GPIO A clock gate */
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    /* reset GPIOA pin 5 moder to default value b'11 */
    /* set GPIOA pin 5 moder to general purpose output in the value b'01 */
    GPIOA->MODER &= ~GPIO_MODER_MODE5_Msk;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    while (1) {
        /* blink led by toggling GPIOA pin 5 */
        GPIOA->ODR ^= GPIO_ODR_OD5;
        delay(1000);
    }
    return 0;
}
