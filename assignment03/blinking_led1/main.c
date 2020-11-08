
/* PA5 connects LED1 */

#define PERIPH_BASE (0x40000000)

#define APB1_BASE (PERIPH_BASE + 0x0)
#define APB2_BASE (PERIPH_BASE + 0x10000)
#define AHB1_BASE (PERIPH_BASE + 0x20000)
#define AHB2_BASE (PERIPH_BASE + 0x8000000)

/* RCC */
/* RCC_BASE: 0x40021000 => 0x40000000 + 0x20000 + 0x1000 */
#define RCC_BASE (AHB1_BASE + 0x1000)

#define RCC_AHB1ENR (*((unsigned int *)(RCC_BASE + 0x48)))
#define RCC_AHB2ENR (*((unsigned int *)(RCC_BASE + 0x4C)))
#define RCC_APB1ENR1 (*((unsigned int *)(RCC_BASE + 0c58)))
#define RCC_APB1ENR2 (*((unsigned int *)(RCC_BASE + 0x5C)))
#define RCC_APB2ENR (*((unsigned int *)(RCC_BASE + 0X60)))

#define RCC_AHB2_GPIOA (1 << 0)
#define RCC_AHB2_GPIOB (1 << 1)

/* GPIOx */
#define GPIOA_BASE (AHB2_BASE + 0x0)
#define GPIOB_BASE (AHB2_BASE + 0x400)

#define GPIOx_MODER (0x0)
#define GPIOx_ODR (0x14)

#define GPIOA_MODER (*((unsigned int *)(GPIOA_BASE + GPIOx_MODER)))
#define GPIOA_ORD (*((unsigned int *)(GPIOA_BASE + GPIOx_ODR)))

#define MODE_00 (0x0)
#define MODE_01 (0x1)
#define MODE_10 (0x2)
#define MODE_11 (0x3)

#define PIN5 (5)

#define MODER( mode , pin ) (mode << (pin << 1))
#define ORD( pin ) (1 << pin)

static inline void delay(void)
{
    int counter = 0;
    while (counter++ < 100000);
}

int main()
{
    // Enable GPIO A AHB2 Clock gate
    RCC_AHB2ENR |= RCC_AHB2_GPIOA;
    
    // Set mode of PA5 as general output
    GPIOA_MODER = GPIOA_MODER 
        & ~MODER(MODE_11, PIN5) // clear pin5 mode
        | MODER(MODE_01, PIN5); // set pin5 mode
    
    while (1) {
        GPIOA_ORD ^= ORD( PIN5 );
        delay();
    }
    
    return 0;
}
