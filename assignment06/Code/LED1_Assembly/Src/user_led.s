/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20
LED_ON      EQU 0x01
LED_OFF     EQU 0x00

control_user_led1
    PUSH  { R4-R8, LR }         // push R4-R8 and LR
    MOV   R4, R0                // move first arguemtn to a variable register
    MOV   R5, R1                // move second arguemtn to a variable register
    
    LDR   R6,=(GPIOA_BASE+GPIOA_ODR)
                                // pseude instruction
                                // the value 0x48000014 is stored at the 
                                // address of PC + offset.
                                // the instrcution is equal to 
                                // "LDR R6, [PC, #offsset]"
                                
    LDR   R7, [R6]              // load the value of GPIOA_ODR register
    
    LDR   R8,=GPIOA_BIT_5       // load the value 0x20 stored in the address of
                                // PC + #offset.
                                // the instruction is equal to 
                                // "LDR R8, [PC, #offset]"
    
    CMP   R4, #LED_ON           // compare desired led state
    BNE   bit_clear             // if the request state is off, then jump to p1
    ORR   R7, R7, r8            // if the request state is on,
                                // then set bit 5 in R7 (R7 = R7 | R8)
    B     bit_set               // jump to p2
bit_clear
    BIC   R7, R7, R8            // if the request state is off,
                                // then clear bit 5 in R7 (R7 = R7 & ~R8)
bit_set
    STR   R7, [R6]              // store back to GPIOA_ODR register
    MOV   R0, R5                // pass the duration to delay function
    BL    delay                 // call delay fucntion
    POP   { R4-R8, PC }         // pop R4 to R8 and LR from the stack
                                // PC is set by LR, so it triggers a branch
    END
