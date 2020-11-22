#ifndef __STACK_H__
#define __STACK_H__

#define DEBUG_ON

int stack_init(void);
int stack_empty(void);
int stack_full(void);
int stack_push(int data);
int stack_pop(int *data);

#endif