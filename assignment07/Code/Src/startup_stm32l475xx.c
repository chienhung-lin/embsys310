#include <stdint.h>

#pragma section = "CSTACK"

#pragma weak NMI_Handler=Default_Handler
#pragma weak Hardfault_Handler=Default_Handler
#pragma weak Memfault_Handler=Default_Handler
#pragma weak Busfault_Handler=Default_Handler
#pragma weak Usagefault_Handler=Default_Handler
#pragma weak SVC_Handler=Default_Handler
#pragma weak PendSV_Handler=Default_Handler
#pragma weak SysTick_Handler=Default_Handler

extern void __iar_program_start(void);

void Default_Handler(void);

void NMI_Handler(void);
void Hardfault_Handler(void);
void Memfault_Handler(void);
void Busfault_Handler(void);
void Usagefault_Handler(void);
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);


const uint32_t __vector_table[] @ ".intvec" =
{
    (uint32_t)__section_end("CSTACK"),  // MSP
    (uint32_t)__iar_program_start,       // reset handler
    (uint32_t)NMI_Handler,              // NMI handler
    (uint32_t)Hardfault_Handler,        // Hard fault handler
    (uint32_t)Memfault_Handler,         // Memory management fault handler
    (uint32_t)Busfault_Handler,         // Bus fault handler
    (uint32_t)Usagefault_Handler,       // Usage fault handler
    0,
    0,
    0,
    0,
    (uint32_t)SVC_Handler,              // SVC handler
    0,
    0,
    (uint32_t)PendSV_Handler,           // PendSV handler
    (uint32_t)SysTick_Handler           // Systick handler
};

void Default_Handler(void)
{
    while (1) ;
}