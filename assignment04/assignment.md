# Assignment \#04

1.

1. The compiler produces "store" instruction for writing a constant to the clock enable register. The produced instructions are:
   
   ```
   0x800 005c: MOVS    R0, #1
   0x800 005e: LDR.N   R1, [PC, #0x34]
   0x800 0060: STR     R0, [R1] <-- store R0 back to address stored in R1
   ...
   0x800 0094: DC32    0x4242 0980
   ```

2. The compiler produces several instructions for operating write-modify-write sequence to toggle the GPIOA\_ODR register. The instructions are:
   
   ```
   0x800 007e: LDR.N    R0, [PC, #0x18]
   0x800 0080: LDR      R1, [R0]     <-- Read
   0x800 0082: EORS.W   R1, R1, #32  <-- Modify
   0x800 0086: STR      R1, [R0]     <-- Write
   ```
   
   
