# EMBSYS 310 - AU20 - ASSIGNMENT 02

## Answer

1.
   1. The value of the "counter" from the "Locals" window is 0.
   2. The value of the "counter" from the "Registers" window is 0, and it is stored in R0.
   3. N flag and V flag are still 0 because the increment statement does not the bit\[31\] of the "counter" or cause overflow.

2.
   1. The value of "counter" is changed from -1 to 0 in decimal representation.
   2. The N flag is changed from 1 to 0 because the value of counter wraps around. As the result, the most significant bit, bit\[31\], turns from 1 to 0. The V flag is still 0 because the value of "counter" is not turned to overflow value.

3.
   1. The value of "counter" is incremented from 2147483647 to 2147483648, and increment operation doesn't make "counter" overflow.
   2. The N flag is still 0 because the bit\[31\] of "counter" is still 0. The V flag is still 0, and it will not happen because the type of "counter" is unsigned.

4.
   1. The value of "counter" is 0 because it wraps around to 0.
   2. The N flag is changed from 1 to 0 becasue the bit\[31\] of "counter" changes from 1 to 0. The V flag is still 0, and it will never turn to 1. For unsigned ineteger, it never happens overflow.

5.
   1. global
   2. No, it cannot.
   3. Global variables can be track via "Watch" view.
   4. The address of "counter" is at 0x20000000.

6.
   1. The value of "counter" is 4.
   2. The pointer, "p_int", is pointed to "counter", and "\*p_int" is dereferenced from "counter". "\*p_int" can be treated as alias of "counter", so any operation on "\*p_int" has as same effect as on "counter".

7.
   1. The address of "counter" is 0x20000000.
   2. The "counter" variable is stored in RAM because it is read/write data.
   3. The value of "counter" is 4.

## Reference
* $4.2, $4.3, The definitive guide to ARM CORTEX-M3 AND ARM CORTEX-M4 PROCESSORS
* A2.2.1, A7.7.76, ARM v7-M Architecture Reference Manual
