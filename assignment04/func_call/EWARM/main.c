
int func1(int var0, int var1, int var2, int var3, int var4);
void func2(void);

int func1(int var0, int var1, int var2, int var3, int var4)
{
    int lvar0, lvar1, lvar2, lvar3, lvar4, sum;
    
    lvar0 = var0;
    lvar1 = var1;
    lvar2 = var2;
    lvar3 = var3;
    lvar4 = var4;
    
    sum = lvar0 + lvar1 + lvar2 + lvar3 + lvar4;
    
    return sum;
}

void func2(void)
{    
    int sum;
    
    sum = func1(0, 1, 2, 3, 4);

    sum <<= 1;
}

int main()
{
    func2();
    
    while (1) {
        ;
    }
    
    return 0;
}
