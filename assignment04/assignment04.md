# Assignment \#04

1. 1. The compiler produces "store" instruction for writing 0x01 into the alias address of the bit 0 of RCC_AHB2ENR. The instructions are:
      
      ```
      0x800 005c: MOVS    R0, #1
      0x800 005e: LDR.N   R1, [PC, #0x34]
      0x800 0060: STR     R0, [R1] <-- store R0 back to address stored in R1
      ...
      0x800 0094: DC32    0x4242 0980
      ```
   
   2. The compiler produces several instructions for operating write-modify-write sequence, and it sets the bit 0 of RCC_AHB2ENR register by OR instruction. The instructions are:
      
      ```
      0x800 005c: LDR.N    R0, [PC, #0x38]
      0x800 005e: LDR      R1, [R0]     <-- Read
      0x800 0060: ORRS.W   R1, R1, #1   <-- Modify
      0x800 0064: STR      R1, [R0]     <-- Write
      ...
      0x800 009c: DC32     RCC_AHB2ENR
      ```

2. 1. The calling function \"fun2\" passes 5 arguments in R0, R1, R2, R3, and one in stack. In assembly code, arguments with value of 0, 1, 2, and 3 are moved indiviually to R0, R1, R2, and R3. The value of 4 is stored into the address which the SP register is pointed to.
   
   2. At the beginning, the \"func2\" saves R7 and LR into the stack. A callee has to save the variable registers, R4 - R11, if it will use them in the subroutine call. Also, a callee saves LR if it will call a subroutine call.
      
      To pass 5 arguments to \"func1\", the compiler generates the following codes:
      
      ```
      0x8000 0064: PUSH    {R7, LR}
      0x8000 0066: MOVS    R0, #4
      0x8000 0068: STR     R0, [SP]
      0x8000 006A: MOVS    R3, #3
      0x8000 006c: MOVS    R2, #2
      0x8000 006e: MOVS    R1, #1
      0x8000 0070: MOVS    R0, #0
      0x8000 0072: BL      func1   <-- 32 bits instruction
      0x8000 0076: ...
      ```
   
   3. According to AAPCS, a callee has to save the registers, R4-R11, if it will use them. The function \"func1\" stores R4 to R8 and LR becuase it use them as local variables to store 5 passed arguments. The one interesting thing is that LR is used as the variable register here.
      
      ```
      0x800 0040: PUSH.W    {R4-R8, LR}
      ...
      0x800 004e: MOV       LR, R3    // lvar3 = var3;
      ```
   
   4. In the beginning of \"main\" function and \"func2\", they save R7 and LR into the stack, but I don't see that R7 is used in the following code. Is there a convention that push and pop instructions should operate even registers?
