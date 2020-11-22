#include <stddef.h>     // NULL maro definition
#include <assert.h>
#include "stack.h"

/* 
 * Predefined stack size
 */
#define STACK_SIZE 3

#define STACK_BEGIN ((unsigned int)0)
#define STACK_END ((unsigned int)STACK_SIZE)  

#ifdef DEBUG_ON
#define STACK_ASSERT( exp ) assert(exp);
#else
#define STACK_ASSERT( exp )
#endif
     
typedef struct stack_type stack_t;

/*
 * Stack Abtract Data Type
 *
 * Array is a container. A length is an available size plus one because 
 * the top index always points to empty item.
 * 
 * Top is a pointer to the last emtyp item
 */
struct stack_type {
    int array[STACK_SIZE + 1];
    unsigned int index;
};

/*
 * Declare global stack object
 * 
 * The predicator "static" limits the scope only within this file
 */
static stack_t stack;

/* 
 * Declare a global pointer of the type "stack_t" and point to the object 
 * "stack", the following operattions based on it
 */
static stack_t *stack_ptr = &stack;

/*
 * Initialize stack object
 * 
 * Point the member "top" to the address of the member "array[0]". The function
 * always returns 0 to indicate 
 */
int stack_init(void)
{
    STACK_ASSERT(stack_ptr != NULL);
    
    stack_ptr->index = STACK_BEGIN;
    
    STACK_ASSERT(stack_ptr->array != NULL);
    
    /* only check upper boundery, don't need to compare 0 with unsigned type */
    STACK_ASSERT(stack_ptr->index <= STACK_END);
    
    return 0;
}

/*
 * Check if stack is emtpy
 * 
 * Return 1 if the stack is empty and otherwise return 0
 */
int stack_empty(void)
{
    STACK_ASSERT(stack_ptr != NULL);
    
    return stack_ptr->index == STACK_BEGIN;
}

/*
 * Check if stack is full
 * 
 * Return 1 if the stack is full and otherwise return 0 
 */
int stack_full(void)
{
    STACK_ASSERT(stack_ptr != NULL);
    
    return stack_ptr->index == STACK_END;
}

/* 
 * Push one integer type data into stack
 * 
 * Store an input data into an item pointed by "top" and update "top" to 
 * the address of the next empty item. The push operation is false if the stack
 * is full. The function will return -1 as error and 0 otherwise.
 */
int stack_push(int data)
{
    STACK_ASSERT(stack_ptr != NULL);
    
    if (stack_full()) {
        return -1;
    }
    
    stack_ptr->array[stack_ptr->index++] = data;
    
    /* only check upper boundery, don't need to compare 0 with unsigned type */
    STACK_ASSERT(stack_ptr->index <= STACK_END);
    
    return 0;
}
/* 
 * Pop one integer type data from stack
 * 
 * Update "top" to the address of the previous item and store it in the address
 * of an input variable.If the stack is empty, the pop operations is false and
 * return -1 as error code. Otherwise, it returnn 0 and update "*data".
 */
int stack_pop(int *data)
{
    STACK_ASSERT(stack_ptr != NULL);

    if (stack_empty()) {
        return -1;
    }
    
    *data = stack_ptr->array[--stack_ptr->index];    

    /* only check upper boundery, don't need to compare 0 with unsigned type */
    STACK_ASSERT(stack_ptr->index <= STACK_END);
    
    return 0;
}