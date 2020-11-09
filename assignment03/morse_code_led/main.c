#include<stdint.h>

/* MARCO: peripherals */
/* PA5 connects LED1 */
/* directly copy from blinking led1 */
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
#define GPIOB_MODER (*((unsigned int *)(GPIOB_BASE + GPIOx_MODER)))

#define GPIOA_ORD (*((unsigned int *)(GPIOA_BASE + GPIOx_ODR)))
#define GPIOB_ORD (*((unsigned int *)(GPIOB_BASE + GPIOx_ODR)))

#define MODE_00 (0x0)
#define MODE_01 (0x1)
#define MODE_10 (0x2)
#define MODE_11 (0x3)

#define PIN5 (5)
#define PIN14 (14)

#define MODER( mode , pin ) (mode << (pin << 1))
#define ORD( pin ) (1 << pin)

/* MACRO: morse table */
#define DUMMY_LETTER { 0 , 0x0 }

#define DASH_BIT (0x1)
#define DOT_BIT (0x0)

#define morse_base ((uint32_t)'0')

#define morse_tb_size (sizeof(morse_table[]) / sizeof(morse_table[0]))

/* MACRO: LED1 INIT, ON, OFF */
#define LED1_INIT()                     \
do {                                    \
    RCC_AHB2ENR |= RCC_AHB2_GPIOA;      \
    GPIOA_MODER = GPIOA_MODER           \
        & ~MODER(MODE_11, PIN5)         \
        | MODER(MODE_01, PIN5);         \
} while (0)

#define LED1_ON()               \
do {                            \
    GPIOA_ORD |= ORD( PIN5 );   \
} while (0)

#define LED1_OFF()              \
do {                            \
    GPIOA_ORD &= ~ORD( PIN5 );  \
} while (0)


/* MACRO: LED1 INIT, ON, OFF */
#define LED2_INIT()                     \
do {                                    \
    RCC_AHB2ENR |= RCC_AHB2_GPIOB;      \
    GPIOB_MODER = GPIOB_MODER           \
        & ~MODER(MODE_11, PIN14)         \
        | MODER(MODE_01, PIN14);         \
} while (0)

#define LED2_ON()               \
do {                            \
    GPIOB_ORD |= ORD( PIN14 );   \
} while (0)

#define LED2_OFF()              \
do {                            \
    GPIOB_ORD &= ~ORD( PIN14 );  \
} while (0)

#define LED2

#ifdef LED1
    
#define LED_INIT LED1_INIT
#define LED_ON LED1_ON
#define LED_OFF LED1_OFF

#endif

#ifdef LED2

#define LED_INIT LED2_INIT
#define LED_ON LED2_ON
#define LED_OFF LED2_OFF

#endif

/* type declaration */
typedef struct morse_letter_type morse_letter_t;

struct morse_letter_type {
    uint8_t len;
    uint8_t code;
};

const morse_letter_t morse_table[] =
{
    { 5 , 0x1F }, /* 0 , 0x30 , ----- , 0b 1 1111 */
    { 5 , 0x1E }, /* 1 , 0x31 , .---- , 0b 1 1110 */
    { 5 , 0x1C }, /* 2 , 0x32 , ..--- , 0b 1 1100 */
    { 5 , 0x18 }, /* 3 , 0x33 , ...-- , 0b 1 1000 */
    { 5 , 0x10 }, /* 4 , 0x34 , ....- , 0b 1 0000 */
    { 5 , 0x0 },  /* 5 , 0x35 , ..... , 0b 0 0000 */
    { 5 , 0x01 }, /* 6 , 0x36 , -.... , 0b 0 0001 */
    { 5 , 0x03 }, /* 7 , 0x37 , --... , 0b 0 0011 */
    { 5 , 0x07 }, /* 8 , 0x38 , ---.. , 0b 0 0111 */  
    { 5 , 0x0F }, /* 9 , 0x39 , ----. , 0b 0 1111 */
    DUMMY_LETTER, /* : , 0x3A , */
    DUMMY_LETTER, /* ; , 0x3B */
    DUMMY_LETTER, /* < , 0x3C */
    DUMMY_LETTER, /* = , 0x3D */
    DUMMY_LETTER, /* > , 0x3E */
    DUMMY_LETTER, /* ? , 0x3F */
    DUMMY_LETTER, /* @ , 0x40 */
    { 2 , 0x2 },  /* A , 0x41 , .-     , 0b 10    */
    { 4 , 0x1 },  /* B , 0x42 , -....  , 0b 01    */
    { 4 , 0x5 },  /* C , 0x43 , -.-.   , 0b 0101  */
    { 3 , 0x1 },  /* D , 0x44 , -..    , 0b 001   */
    { 1 , 0x0 },  /* E , 0x45 , .      , 0b 0     */
    { 4 , 0x4 },  /* F , 0x46 , ..-.   , 0b 0100  */
    { 3 , 0x3 },  /* G , 0x47 , --.    , 0b 011   */
    { 4 , 0x0 },  /* H , 0x48 , ....   , 0b 0000  */
    { 2 , 0x0 },  /* I , 0x49 , ..     , 0b 00    */
    { 4 , 0xE },  /* J , 0x4A , .---   , 0b 1110  */
    { 3 , 0x5 },  /* K , 0x4B , -.-    , 0b 101   */
    { 4 , 0x2 },  /* L , 0x4C , .-..   , 0b 0010  */
    { 2 , 0x3 },  /* M , 0x4D , --     , 0b 11    */
    { 2 , 0x1 },  /* N , 0x4E , -.     , 0b 01    */
    { 3 , 0x7 },  /* O , 0x4F , ---    , 0b 111   */
    { 4 , 0x6 },  /* P , 0x50 , .--.   , 0b 0110  */
    { 4 , 0xB },  /* Q , 0x51 , --.-   , 0b 1011  */
    { 3 , 0x2 },  /* R , 0x52 , .-.    , 0b 010   */
    { 3 , 0x0 },  /* S , 0x53 , ...    , 0b 000   */
    { 1 , 0x1 },  /* T , 0x54 , -      , 0b 1     */
    { 3 , 0x4 },  /* U , 0x55 , ..-    , 0b 100   */
    { 4 , 0x8 },  /* V , 0x56 , ...-   , 0b 1000  */
    { 3 , 0x6 },  /* W , 0x57 , .--    , 0b 110   */
    { 4 , 0x9 },  /* X , 0x58 , -..-   , 0b 1001  */
    { 4 , 0xD },  /* Y , 0x59 , -.--   , 0b 1101  */
    { 4 , 0x3 },  /* Z , 0x60 , --..   , 0b 0011  */
};

static inline void assert(uint32_t in)
{
    if (!in) {
        while (1) ;
    }
}

void delay(const uint32_t unit)
{
    int i, j;
    for (i = 0;i < unit;++i) {
        for (j = 0;j < 300000;++j) ;
    }
}

void transmit_ch(uint8_t ch)
{
    uint32_t index, len, code;
    const uint32_t code_mask = 0x1UL;
    
    assert(!('0' > ch || 'Z' < ch));
    assert(!('9' < ch && ch < 'A'));
    
    index = ch - morse_base;
    len = morse_table[index].len;
    code = morse_table[index].code;
    
    if (code & code_mask) {
        // light dash
        LED_ON();
        delay(3);
        LED_OFF();
    } else {
        // light dot
        LED_ON();
        delay(1);
        LED_OFF();
    }
    
    len -= 1;
    code >>= 1;
    
    while (len > 0) {        
        // pause one unit space
        LED_OFF();
        delay(1);
        
        if (code & code_mask) {            
            // light dash
            LED_ON();
            delay(3);
            LED_OFF();
        } else {            
            // light dash
            LED_ON();
            delay(1);
            LED_OFF();
        }
        
        len -= 1;
        code >>= 1;        
    }
}

void transmit_text(const char *s, uint32_t len)
{
    if (*s == '\0' || len == 0) {
        return;
    }
    
    transmit_ch((uint8_t)(*s));
    
    s += 1;
    len -= 1;
    
    while (*s != '\0' && len > 0) {        
        if (*s == ' ') {            
            // pause seven unit space
            LED_OFF();
            delay(7);
            
        } else {            
            // pause three unit space
            LED_OFF();
            delay(3);
            
            transmit_ch((uint8_t)*s);            
        }
        
        s += 1;
        len -= 1;        
    }
}

int main()
{
    const char name[] = "CHIEN HUNG";
    
    LED_INIT();
    
    transmit_text(name, sizeof(name)/sizeof(name[0]));
    
    while (1) ;
    
    return 0;
}
