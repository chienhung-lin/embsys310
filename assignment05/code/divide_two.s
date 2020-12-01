;*******************************************************************************
;* File Name          : divide_two.s
;* Author             : Chien Hung Lin
;* Description        : Divide integer by 2
;*                      This module performs:
;*                      - print "Hello world"
;*                      - divide passed parameter by two
;*                      - return the result
;* Notes              : file referenced from startup_stm32l475.s
;*******************************************************************************
;*
;* <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
;* All rights reserved.</center></h2>
;*
;* This software component is licensed by ST under Apache License, Version 2.0,
;* the "License"; You may not use this file except in compliance with the
;* License. You may obtain a copy of the License at:
;*                        opensource.org/licenses/Apache-2.0
;*
;*******************************************************************************
;*******************************************************************************
;* MIT License
;* 
;* Copyright (c) 2020 Chien Hung Lin
;* 
;* Permission is hereby granted, free of charge, to any person obtaining a copy
;* of this software and associated documentation files (the "Software"), to deal
;* in the Software without restriction, including without limitation the rights
;* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
;* copies of the Software, and to permit persons to whom the Software is
;* furnished to do so, subject to the following conditions:
;* 
;* The above copyright notice and this permission notice shall be included in all
;* copies or substantial portions of the Software.
;* 
;* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
;* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
;* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
;* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
;* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;* SOFTWARE.
;*
;*******************************************************************************

;* declare module name
;* still do not the usage of MODULE symbol
    MODULE  divide_two

;* my_printf_str
;* prototype :   void my_printf_str(const char *s)
;* files:    :   print.c
    EXTERN my_printf_str           

;* divide_two
;* prototype :   int divide_two(int number)
;* files:    :   divide_two.s
    PUBLIC divide_two       ;export symbol for being called by other files

;* indicate a const data section
;* alignment is 2
    SECTION .data:CONST (1)

myCstr DC8 "Helloworld!\r\n"

;* section : .text
;* type    : CODE
;* flag    :
;*   - REORDERS : starts a new section with a given name
;*   - NOROOT   : the section fragment is discarded if no symbols are refered to 
;* (2)     : align, align with two power of two

    SECTION .text:CODE:REORDER:NOROOT(2)

;* indicate instructions are Thumb2. That is, they are eighter 16 bits 
;* instructions or 32 bits ones.

    THUMB

divide_two              ; function symbols
    PUSH { LR }         ; caller save LR if it will call a function
    MOV  R1, R0         ; copy the value of passed parameters
    LDR  R0,=myCstr     ; copy the address of first char
                        ; preparing parameters
    PUSH { R1 }         ; caller saves R0-R3, R12
                        ; caller has to keep R1 so stores R1 only
    BL   my_printf_str  ; call printf function and save the address of the next
                        ; instruction in LR
    POP { R1 }          ; restore R1 from the stack
    ASR  R1, R1, #1     ; Arithmetic shift right one bits for dividing 2
    MOV  R0, R1         ; assign the result to R0 as a return value
    POP  {LR}           ; restore LR
    BX   LR             ; return to the next address of the calling instruction
                        ; as same as POP { PC }
    
    END
