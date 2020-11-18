#include <stdint.h>

#define PERI_BASE (0x40000000)

#define AHB1_BASE (PERI_BASE + 0x20000)
#define AHB2_BASE (PERI_BASE + 0x8000000)

#define RCC_BASE (AHB1_BASE + 0x1000)

#define GPIO_BASE (AHB2_BASE + 0x0)
#define GPIOA_BASE (GPIO_BASE + 0x0)

#define RCC_AHB2ENR (*((volatile uint32_t *)(RCC_BASE + 0x4C)))
#define RCC_GPIOAENR (1 << 0)

#define GPIOA_MODER (*((volatile uint32_t *)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((volatile uint32_t *)(GPIOA_BASE + 0x14)))

#define GPIO_MODER(mode, pin) ((mode) << ((pin) * 2))
#define GPIO_ODR(pin) (1 << (pin))

#define MODE00 (0x0)
#define MODE01 (0x1)
#define MODE10 (0x2)
#define MODE11 (0x3)

#define PIN5 (5u)

/* bit band */
#define BB_SRAM_BASE (0x20000000)
#define BBA_SRAM_BASE (0x22000000)
#define BB_PERI_BASE (0x40000000)
#define BBA_PERI_BASE (0x42000000)

/* 
 * TODO: compiling time checking for the case 
 *       that addr is out of range
*/
#define BB_MAPPING(addr, bb_base, bba_base, pin) \
        ((bba_base) + (addr - bb_base) * 32 + pin *4)

#define BB_SRAM(addr, pin) \
        (*((volatile uint32_t *) \
           BB_MAPPING(addr, BB_SRAM_BASE, BBA_SRAM_BASE, pin)))

#define BB_PERI(addr, pin) \
        (*((volatile uint32_t *) \
            BB_MAPPING(addr, BB_PERI_BASE, BBA_PERI_BASE, pin)))

#define BB_SET (0x1)
#define BB_UNSET (0x0)

#define BIT_BAND_FLAG
#define BIT_BAND_MACRO

#define RCC_AHB2ENR_BB \
        (*(volatile uint32_t *)(BBA_PERI_BASE + 0x2104C * 32 + 0*4))

static inline void delay(uint32_t unit)
{
    uint32_t i, j;
    for (j = 0;j < unit; ++j) {
        for (i = 0;i < 100000; ++i) ;
    }
}

int main()
{
    volatile uint32_t tmpt;
 
#ifdef BIT_BAND_FLAG
#ifdef BIT_BAND_MACRO
    BB_PERI(0x4002104C, 0) = BB_SET;
#else
    RCC_AHB2ENR_BB = BB_SET;
#endif
#else
    RCC_AHB2ENR |= RCC_GPIOAENR;
#endif
    
    // read modify write
    // referenced from STM_HAL GPIO library
    tmpt = GPIOA_MODER;
    tmpt &= ~GPIO_MODER(MODE11, PIN5);
    tmpt |= GPIO_MODER(MODE01, PIN5);
    GPIOA_MODER = tmpt;
    
    while (1) {
        GPIOA_ODR ^= GPIO_ODR(PIN5);
        delay(1);
    }
    
    return 0;
}
