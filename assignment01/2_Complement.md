# Two's complement

## Why use two's complement to represet negatvie number?

### Anwser

In signed number representation, there are three sorts of ways: sign-magnnitude, one's complement, two's complement.

For the sign-magnitude, like its name, it represents a sign by most significant bit and magnitude by reset bits. If a number is negative, sign bit is on(1), and positive number vice verse. For magnitude part, both positive number and negative number are the same, and the difference is only a sign bit. This kind of representation is more easily recognized but not identical to the manipulation of unsigned arithmetic, so there is another method called one's comlement.

In one's complement representation, a negation of a number in binary is a bitwise not (inverse) of itself. If we try adding a number with its negation, we will get an inevitable result that all bits are 1. It is 111...111 and is defined as negative zero. Hence, there are two problems. First, there is always an offset -1, and second, the nubmer zero can be represented in two different forms: zero or negative zero. Besides, while manipulating one's complement, we need to do end-around carry if an overflow happens.

To fix problems of one's complement manipulation, here comes the third form, tow's complement. A negation of a number is represented by adding its one's complement with 1. The manipulation can be observed by sabstracting a number from 0. We can simply replace zero by all bits 1 plus 1, so the equation will equal to that all bits 1 adds a bit 1 and substracts a number. Notice here, while all bits 1 adds 1, its result will be overflow but all bits are 0 regardless of a carry bit. It can regard as 0. We know the result of subtracting a number from all bits 1 equals to an invert operation. Hence, a negation of anumber can be implied from one's complement plus 1. The benefit of two complement is that it kepps a consist arithmetic for unsigned integer and signed integer. That is there is no requirement for an extra circuit design to calculate sign number.

### Reference
* [Signed number representations](https://en.wikipedia.org/wiki/Signed_number_representations)
* [Two's complement](https://en.wikipedia.org/wiki/Two%27s_complement)
* [One's complement](https://en.wikipedia.org/wiki/Ones%27_complement)
* [Why are negative numbers stored as 2’s complement?](https://www.geeksforgeeks.org/why-are-negative-numbers-stored-as-2s-complement/#:~:text=In%202s%2Dcomplement%20representation%2C%20we,to%20perform%20addition%20and%20subtraction.)

