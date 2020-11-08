
 



 
 



 






static inline void delay(void)
{
    int counter = 0;
    while (counter++ < 100000);
}

int main()
{
    
    (*((unsigned int *)((((0x40000000) + 0x20000) + 0x1000) + 0x4C))) |= (1 << 0);
    
    
    (*((unsigned int *)((((0x40000000) + 0x8000000) + 0x0) + (0x0)))) = (*((unsigned int *)((((0x40000000) + 0x8000000) + 0x0) + (0x0)))) 
        & ~((0x3) << ((5) << 1)) 
        | ((0x1) << ((5) << 1)); 
    
    while (1) {
        (*((unsigned int *)((((0x40000000) + 0x8000000) + 0x0) + (0x14)))) ^= (1 << (5));
        delay();
    }
    
    return 0;
}
