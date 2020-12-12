#include"delay.h"

volatile uint32_t count = 0;

void delay(uint32_t delayInMilliseconds)
{
    uint32_t wake_count;
    
	/* If wak_count is overflow, it will wrap around */
    wake_count = count + delayInMilliseconds;
    
    while (count != wake_count) ;
}