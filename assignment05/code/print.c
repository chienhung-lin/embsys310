#include <stdint.h>
#include "print.h"
#include "stm32l4xx_hal.h"

/* TODO: implement variable parameters */
/* TODO: understand implementation of val_list */
/* TODO: practice standard printf format and parsing */

// huart1 declared in main.c
extern UART_HandleTypeDef huart1;

// Error_Handler defined in main.c
extern void Error_Handler(void);

/* inline directive doesn't work here */
static inline uint32_t abs(int32_t i32_num);

static uint8_t buff[20];

static const char hex_table[] = "0123456789ABCDEF";

void my_printf_char(const char *s)
{
    uint8_t u8_char = (uint8_t)*s;
    
    if (HAL_OK != 
            HAL_UART_Transmit(&huart1, &u8_char, sizeof(char), 10)) {
        Error_Handler();
    }
}

void my_printf_str(const char *s)
{
    char ch;
    while ((ch = *s++) != '\0') {
        if (HAL_OK != 
                HAL_UART_Transmit(&huart1, (uint8_t *)&ch, sizeof(char), 10)) {
            Error_Handler();
        }
    }
}

void my_printf_dec(int num)
{
    uint8_t u8_sign, u8_digit;
    uint32_t u32_num;
    uint8_t *p;
    
    u32_num = abs(num);
    u8_sign = ((uint32_t)(num & 0x80000000)) >> 31;
    p = buff;
    
    do {
        u8_digit = u32_num % 10;
        u32_num /= 10;
        *p++ = (uint8_t)('0' + u8_digit);
    } while (u32_num) ;
    
    if (u8_sign) {
        *p++ = (uint8_t)'-';
    }

    while (p != buff) {
        if (HAL_OK != 
                HAL_UART_Transmit(&huart1, --p, sizeof(char), 10)) {
            Error_Handler();
        }        
    }
}

void my_printf_hex(unsigned int num)
{
    int i = 10;
    const unsigned int mask = 0x0000000F;
    
    buff[i--] = '\0';
    
    for (;i > 1; --i) {
        buff[i] = hex_table[num & mask];
        num >>= 4;
    }
    
    buff[i--] = 'x';
    buff[i] = '0';
    
    my_printf_str(buff);
}

/* referenced from
 *   Bit Twiddling Hacks
 *   https://graphics.stanford.edu/~seander/bithacks.html#IntegerAbs
 */
uint32_t abs(int32_t i32_num)
{
    const int32_t i32_mask = i32_num >> 31;
    
    // 2's compliment, -num = ~num + 1, -num = ~(num - 1)
    // if num is negative, then mask is 0xFFFFFFFF
    //    the evaluation is euqal ~(num - 1)
    //    num - 1 is equal num + 0xFFFFFFFF
    //    inverse operation is equal num ^ 0xFFFFFFFF
    //
    // if num is positive, then mask is 0x00000000
    //    the evaluation is euqal num
    //    num + 0 is equal num + 0x00000000
    //    no operation is num ^ 0x00000000
    return i32_mask ^ (i32_num + i32_mask);
}