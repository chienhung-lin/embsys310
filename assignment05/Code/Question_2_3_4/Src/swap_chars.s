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
    MODULE  swap_chars

;* swap_chars
;* prototype :   int swap_chars(char *c_ptr1, char *c_ptr2)
;*   - parameter :
;*     - char *c_ptr1
;*     - char *c_ptr2
;*   - return:
;*     - 0: the value of chars are different
;*     - 1: the value of chars are same
;* files:    :   swap_chars.s
    PUBLIC swap_chars       ;export symbol for being called by other files


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

swap_chars                ; function symbols
    PUSH   { R4-R6 }      ; callee has to save R4-R11 if it will use them
    LDRB    R4, [R0]      ; extract the value in the address stored in R0
    LDRB    R5, [R1]      ; extract the value in the address stored in R1
                          ;
                          ; TODO: try IT block
                          ;
                          ; compare two chars
    MOV    R6, #0         ; R6 is initialized to #0
    CMP    R4, R5         ; compare R4 and R5
    BEQ EXIT              ; if R4 is equal to R5, no needs to modify R6
                          ;   jump to EXIT
    MOV    R6, #1         ; if R4 is not equal to R5, R6 is assigned to #1
EXIT
                          ;
                          ; swap two chars
    STRB    R5, [R0]      ; store the value of R5 to the address stored in R0
    STRB    R4, [R1]      ; store the value of R4 to the address stored in R1
                          ;
    MOV  R0, R6           ; assign the comparison result to R0 as return valute
    POP  { R4-R6 }        ; restore R4-R6
    BX   LR               ; return to the next address of the calling instruction
                          ; as same as POP { PC }
    
    END
