
//#define GLOBAL_DECLARE

#ifdef GLOBAL_DECLARE

int x, y;
    
int *x_ptr, *y_ptr;

#endif

void swap_pointers(int **de_ptr1, int **de_ptr2);

int main()
{
#ifndef GLOBAL_DECLARE
    
    int x, y;
    
    int *x_ptr, *y_ptr;
    
#endif
    
    x = 2000000;
    y = 1000000;
    
    x_ptr = &x;
    y_ptr = &y;
    
    swap_pointers(&x_ptr, &y_ptr);
    
    while (1) {
        ;
    }
    
    return 0;
}


void swap_pointers(int **de_ptr1, int **de_ptr2)
{
    int *tmpt_ptr;
    
    tmpt_ptr = *de_ptr1;
    *de_ptr1 = *de_ptr2;
    *de_ptr2 = tmpt_ptr;
}