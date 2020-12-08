#include <stdint.h>
#include "delay.h"
#include "user_led.h"
#include "rcc_ctrl.h"

#define LED_ON  (0x01U)
#define LED_OFF (0x00U)

#define RCC_BASE (0x40021000UL)
#define RCC_AHB2_ENR (*((volatile int32_t *)(RCC_BASE + 0x4CUL)))

#define RCC_AHB2_ENR_GPIOA (0UL)
#define RCC_AHB2_ENR_GPIOA_MASK (1 << RCC_AHB2_ENR_GPIOA)

#define GPIO_BASE (0x48000000UL)
#define GPIOA_BASE (GPIO_BASE + 0x0UL)
#define GPIOA_MODER (*((volatile uint32_t *)(GPIOA_BASE + 0x0UL)))
#define GPIOA_ODR (*((volatile uint32_t *)(GPIOA_BASE + 0x014)))

#define GPIO_MODE0 (0x00UL)
#define GPIO_MODE1 (0x01UL)
#define GPIO_MODE2 (0x02UL)
#define GPIO_MODE3 (0x03UL)

#define GPIO_MODE(mode, pin) (mode << ((pin) << 1))

#define GPIO_ODR(pin) (1 << (pin))

#define PIN5 (5)

int main()
{
    uint32_t u32_duration = 300000;
    
    // RCC_AHB2_ENR |= RCC_AHB2_ENR_GPIOA_MASK;
    enable_rcc(RCC_AHB2_ENR_GPIOA);
    
    // set GPIOA_MODER as mode 1, general purpose output
    GPIOA_MODER &= ~GPIO_MODE(GPIO_MODE3, PIN5);
    GPIOA_MODER |= GPIO_MODE(GPIO_MODE1, PIN5);
    
    while (1) {
        control_user_led1(LED_ON, u32_duration);
        control_user_led1(LED_OFF, u32_duration);
        
    }
    
    return 0;
}