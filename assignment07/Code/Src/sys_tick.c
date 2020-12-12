#include<stdint.h>
#include"sys_tick.h"
#include"stm32l475xx.h"
#include"system_stm32l4xx.h"

extern volatile uint32_t count;

void sys_tick_init(void)
{
    /* The default clock source after reset is MSI. */
    /* The system core clock is configuared as 4MHz */
    /* The systick clock is 4MHz divied by 8, so it is 500KHz */
    /* The reload value is 1ms / 2us =  500 */
    SysTick->LOAD = ((uint32_t)500 & SysTick_LOAD_RELOAD_Msk);
    
    /* Force current value and countflag are clear */
    SysTick->VAL = ((uint32_t)0 & SysTick_VAL_CURRENT_Msk);
    
    /* set systick interrupt enable bit and set systick enable bit*/
    SysTick->CTRL |= (SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk);    
}

void SysTick_Handler(void)
{
    ++count;
}