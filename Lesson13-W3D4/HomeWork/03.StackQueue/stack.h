#include <stdio.h>

#ifndef STACK_H
#define STACK_H 1

typedef  struct Stack{
    int data;
}Stack;

void init_stack_array(size_t max_elem_count);
int push(Stack element);
int pop(Stack* res);
void print_elems();
void deinitStac(Stack* arr);

#endif