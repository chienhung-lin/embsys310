#include "delay.h"

#define UNIT_COUNTS (1000UL)

void delay(const uint32_t u32_count)
{
    uint32_t u32_i, u32_j;
    
    for (u32_i = 0;u32_i < u32_count;++u32_i) {
        u32_j = 0;
        while (u32_j++ < UNIT_COUNTS) ;
    }
    return;
}