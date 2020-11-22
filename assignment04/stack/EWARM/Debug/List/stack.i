 
 

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

  






 
 
 


  #pragma system_include

 
 

 

  #pragma system_include














 



 
  typedef _Sizet size_t;

typedef unsigned int __data_size_t;



 


 
  typedef   signed int ptrdiff_t;

  typedef   _Wchart wchar_t;


    typedef union
    {
      long long _ll;
      long double _ld;
      void *_vp;
    } _Max_align_t;
    typedef _Max_align_t max_align_t;






 
 
 

 

















 

  #pragma system_include

 
 

 

  #pragma system_include














 







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




 


     
typedef struct stack_type stack_t;








 
struct stack_type {
    int array[3 + 1];
    unsigned int index;
};





 
static stack_t stack;




 
static stack_t *stack_ptr = &stack;






 
int stack_init(void)
{
    ((stack_ptr != 0) ? (void) 0 : (__aeabi_assert("stack_ptr != 0", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\stack.c", 55), (__iar_EmptyStepPoint())));;
    
    stack_ptr->index = ((unsigned int)0);
    
    ((stack_ptr->array != 0) ? (void) 0 : (__aeabi_assert("stack_ptr->array != 0", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\stack.c", 59), (__iar_EmptyStepPoint())));;
    
     
    ((stack_ptr->index <= ((unsigned int)3)) ? (void) 0 : (__aeabi_assert("stack_ptr->index <= ((unsigned int)3)", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\stack.c", 62), (__iar_EmptyStepPoint())));;
    
    return 0;
}





 
int stack_empty(void)
{
    ((stack_ptr != 0) ? (void) 0 : (__aeabi_assert("stack_ptr != 0", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\stack.c", 74), (__iar_EmptyStepPoint())));;
    
    return stack_ptr->index == ((unsigned int)0);
}





 
int stack_full(void)
{
    ((stack_ptr != 0) ? (void) 0 : (__aeabi_assert("stack_ptr != 0", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\stack.c", 86), (__iar_EmptyStepPoint())));;
    
    return stack_ptr->index == ((unsigned int)3);
}







 
int stack_push(int data)
{
    ((stack_ptr != 0) ? (void) 0 : (__aeabi_assert("stack_ptr != 0", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\stack.c", 100), (__iar_EmptyStepPoint())));;
    
    if (stack_full()) {
        return -1;
    }
    
    stack_ptr->array[stack_ptr->index++] = data;
    
     
    ((stack_ptr->index <= ((unsigned int)3)) ? (void) 0 : (__aeabi_assert("stack_ptr->index <= ((unsigned int)3)", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\stack.c", 109), (__iar_EmptyStepPoint())));;
    
    return 0;
}






 
int stack_pop(int *data)
{
    ((stack_ptr != 0) ? (void) 0 : (__aeabi_assert("stack_ptr != 0", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\stack.c", 122), (__iar_EmptyStepPoint())));;

    if (stack_empty()) {
        return -1;
    }
    
    *data = stack_ptr->array[--stack_ptr->index];    

     
    ((stack_ptr->index <= ((unsigned int)3)) ? (void) 0 : (__aeabi_assert("stack_ptr->index <= ((unsigned int)3)", "D:\\Documents\\Course\\Certificate Course in UW\\UW_Workspace\\embsys310\\assignment04\\stack\\Application\\Src\\stack.c", 131), (__iar_EmptyStepPoint())));;
    
    return 0;
}
