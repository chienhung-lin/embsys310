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
    MODULE  swap_two_pointers

;* swap_two_pointers
;* prototype :   void swap_two_pointers(int **de_ptr1, int **de_ptr2)
;*   - parameter :
;*     - de_ptr1, type: int **
;*     - de_ptr2, type: int **
;*   - return:
;*     none
;* files:    :   swap_two_pointers.s
    PUBLIC swap_two_pointers    ;export symbol for being called by other files


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

swap_two_pointers         ; function symbols
    PUSH   { R4-R5, LR }  ; caller saves LR if it will call a function
                          ; callee has to save R4-R11 if it will use them
    LDRB    R4, [R0]      ; extract the value in the address stored in R0
    LDRB    R5, [R1]      ; extract the value in the address stored in R1
                          ;
                          ; swap two pointers
                          ;   the type of pointers is a pointer to a pointer to
                          ;   int
                          ;
    STRB    R5, [R0]      ; store the value of R5 to the location in 
                          ;   the address stored in R0
    STRB    R4, [R1]      ; store the value of R4 to the location in 
                          ;   the address stored in R1
                          ;
    POP  { R4-R5, LR }    ; restore R4-R6 and LR
    BX   LR               ; return to the next address of the calling instruction
                          ; as same as POP { PC }
    
    END
