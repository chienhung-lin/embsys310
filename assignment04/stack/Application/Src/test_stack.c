#include <assert.h>
#include "stack.h"
#include "test_stack.h"

void test_stack(void)
{
    int i,
        result0, result1,
        input, output,
        array[] = {1, 2, 3};
    
    /* Test case 1: initialization and empty function */
    
    // Arrange and Act
    stack_init();  
    
    // Act and Assert
    assert(1 == stack_empty()); 
    /* --------------------------------------------- */
    
    /* Test case 2: push and pop when the stack is emtpy */
    
    // Arrange
    stack_init();
    input = 0xAAAAAAAA;
    output = 0x0;
    
    // Act
    result0 = stack_push(input);
    result1 = stack_pop(&output);
    
    // Assert
    assert(0 == result0);
    assert(0 == result1);
    assert(input == output);
    /* --------------------------------------------- */
    
    /* Test case 3: pop and push when the stack is full */
    
    // Arrange
    stack_init();
    input = 0xAAAAAAAA;
    output = 0x0;
    for (i = 0;i < 3;++i) {
        stack_push(input);
    }
    
    // Act
    result0 = stack_pop(&output);
    result1 = stack_push(input);
    
    // Assert
    assert(0 == result0);
    assert(0 == result1);
    
    output = 0x0;
    assert(0 == stack_pop(&output));
    assert(input == output);
    /* --------------------------------------------- */
        
    /* Test case 4: full function */
    
    // Arrange
    stack_init();
    input = 0xAAAAAAAA;
    for (i = 0;i < 3; ++i) {
        stack_push(input);
    }
    
    // Act
    result0 = stack_full();
    
    // Assert
    assert(1 == result0);
    /* --------------------------------------------- */
    
    /* Test case 5: push if the stack is full */
    
    // Arrange
    stack_init();
    input = 0xAAAAAAAA;
    for (i = 0;i < 3; ++i) {
        stack_push(input);
    }
     
    // Act
    result0 = stack_push(input);
    
    // Assert
    assert(-1 == result0);
    /* --------------------------------------------- */
    
    /* Test case 6: pop if the stack is empty */
    
     // Arrange
    stack_init();
    output = 0xAAAAAAAA;
     
    // Act
    result0 = stack_pop(&output);
    
    // Assert
    assert(-1 == result0);
    assert(output == 0xAAAAAAAA);
    /* --------------------------------------------- */

    /* Test case 7: data stored in an inversed order */
    // Arrange
    stack_init();
     
    // Act    
    for (i = 0;i < 3;++i) {
        stack_push(array[i]);
    }
    
    // Assert
    for (i = 2;i >= 0;--i) {
        output = 0xAAAAAAAA;
        assert(0 == stack_pop(&output));
        assert(array[i] == output);
    }
    /* --------------------------------------------- */
    
    /* Test case 8: 
     *     test initialization and emtpy after pop and push operations
     */
    // Arrange
    stack_init();
    for (i = 0;i < 3;++i) {
        stack_push(array[i]);
    }
    stack_pop(&output);
     
    // Act
    stack_init();
    
    // Assert
    assert(1 == stack_empty());
    /* --------------------------------------------- */
}