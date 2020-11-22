 
 

 

















 

  #pragma system_include

 
 

 

  #pragma system_include














 


 
 


  #pragma system_include

 



 

 

 

 
#pragma rtmodel = "__dlib_version", "6"

 


 



























 


  #pragma system_include

 
 
 


  #pragma system_include

 

   

 
 


   #pragma system_include






 




 


 


 


 

 


 

 

 

 

 

 

 

 

 















 



















 











 























 





 



 










 














 













 








 













 













 















 











 








 








 






 





 












 





 













 






 


   


  







 







 




 






 




 




 













 

   




 







 







 







 










 





 

















 


 


 













 

   


 


 



 

 

 
  typedef unsigned int _Wchart;
  typedef unsigned int _Wintt;

 

 
typedef unsigned int     _Sizet;

 
typedef signed char   __int8_t;
typedef unsigned char  __uint8_t;
typedef signed short int   __int16_t;
typedef unsigned short int  __uint16_t;
typedef signed int   __int32_t;
typedef unsigned int  __uint32_t;
   typedef signed long long int   __int64_t;
   typedef unsigned long long int  __uint64_t;
typedef signed int   __intptr_t;
typedef unsigned int  __uintptr_t;

 
typedef struct _Mbstatet
{  
    unsigned int _Wchar;   
    unsigned int _State;   

} _Mbstatet;

 

 
  typedef struct __va_list __Va_list;



 
typedef struct
{
    long long _Off;     
  _Mbstatet _Wstate;
} _Fpost;


 

 
  
   
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_StaticGuard(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_StaticGuard(void);


  typedef void *__iar_Rmtx;

  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Initdynamiclock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Dstdynamiclock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Lockdynamiclock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlockdynamiclock(__iar_Rmtx *);

  






 





    #pragma no_bounds
    __intrinsic __nounwind void __aeabi_assert(char const *, char const *, int);
  #pragma no_bounds
  __intrinsic __nounwind int  __iar_ReportAssert(const char *, const char *,
                                       const char *, const char *);
  _Pragma("object_attribute = __weak")
  __intrinsic __nounwind void __iar_EmptyStepPoint(void);


    
 







 


int stack_init(void);
int stack_empty(void);
int stack_full(void);
int stack_push(int data);
int stack_pop(int *data);


void test_stack(void);


void test_stack(void)
{
    int i,
        result0, result1,
        input, output,
        array[] = {1, 2, 3};
    
     
    
    
    stack_init();  
    
    
    ((1 == stack_empty()) ? (void) 0 : (__aeabi_assert("1 == stack_empty()", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 18), (__iar_EmptyStepPoint()))); 
     
    
     
    
    
    stack_init();
    input = 0xAAAAAAAA;
    output = 0x0;
    
    
    result0 = stack_push(input);
    result1 = stack_pop(&output);
    
    
    ((0 == result0) ? (void) 0 : (__aeabi_assert("0 == result0", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 33), (__iar_EmptyStepPoint())));
    ((0 == result1) ? (void) 0 : (__aeabi_assert("0 == result1", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 34), (__iar_EmptyStepPoint())));
    ((input == output) ? (void) 0 : (__aeabi_assert("input == output", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 35), (__iar_EmptyStepPoint())));
     
    
     
    
    
    stack_init();
    input = 0xAAAAAAAA;
    output = 0x0;
    for (i = 0;i < 3;++i) {
        stack_push(input);
    }
    
    
    result0 = stack_pop(&output);
    result1 = stack_push(input);
    
    
    ((0 == result0) ? (void) 0 : (__aeabi_assert("0 == result0", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 53), (__iar_EmptyStepPoint())));
    ((0 == result1) ? (void) 0 : (__aeabi_assert("0 == result1", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 54), (__iar_EmptyStepPoint())));
    
    output = 0x0;
    ((0 == stack_pop(&output)) ? (void) 0 : (__aeabi_assert("0 == stack_pop(&output)", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 57), (__iar_EmptyStepPoint())));
    ((input == output) ? (void) 0 : (__aeabi_assert("input == output", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 58), (__iar_EmptyStepPoint())));
     
        
     
    
    
    stack_init();
    input = 0xAAAAAAAA;
    for (i = 0;i < 3; ++i) {
        stack_push(input);
    }
    
    
    result0 = stack_full();
    
    
    ((1 == result0) ? (void) 0 : (__aeabi_assert("1 == result0", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 74), (__iar_EmptyStepPoint())));
     
    
     
    
    
    stack_init();
    input = 0xAAAAAAAA;
    for (i = 0;i < 3; ++i) {
        stack_push(input);
    }
     
    
    result0 = stack_push(input);
    
    
    ((-1 == result0) ? (void) 0 : (__aeabi_assert("-1 == result0", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 90), (__iar_EmptyStepPoint())));
     
    
     
    
     
    stack_init();
    output = 0xAAAAAAAA;
     
    
    result0 = stack_pop(&output);
    
    
    ((-1 == result0) ? (void) 0 : (__aeabi_assert("-1 == result0", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 103), (__iar_EmptyStepPoint())));
    ((output == 0xAAAAAAAA) ? (void) 0 : (__aeabi_assert("output == 0xAAAAAAAA", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 104), (__iar_EmptyStepPoint())));
     

     
    
    stack_init();
     
    
    for (i = 0;i < 3;++i) {
        stack_push(array[i]);
    }
    
    
    for (i = 2;i >= 0;--i) {
        output = 0xAAAAAAAA;
        ((0 == stack_pop(&output)) ? (void) 0 : (__aeabi_assert("0 == stack_pop(&output)", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 119), (__iar_EmptyStepPoint())));
        ((array[i] == output) ? (void) 0 : (__aeabi_assert("array[i] == output", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 120), (__iar_EmptyStepPoint())));
    }
     
    
    

 
    
    stack_init();
    for (i = 0;i < 3;++i) {
        stack_push(array[i]);
    }
    stack_pop(&output);
     
    
    stack_init();
    
    
    ((1 == stack_empty()) ? (void) 0 : (__aeabi_assert("1 == stack_empty()", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\test_stack.c", 138), (__iar_EmptyStepPoint())));
     
}
