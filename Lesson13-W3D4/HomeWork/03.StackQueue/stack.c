#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

size_t capacity,cur_elem_count;
Stack* arr_begin;
void init_stack_array(size_t max_elem_count) {
    capacity = max_elem_count;
    cur_elem_count = 0;
    arr_begin = calloc(max_elem_count, sizeof(Stack));
}


int push(Stack element)
{
    //Проверява дали има място в сетека
    if(cur_elem_count == capacity)
    {
        printf("Stack is full\n");
        return -1;
    }
    //Добавяне на елемент в първата свободна позиция
    arr_begin[cur_elem_count] = element;
    cur_elem_count++;
    return 0;
}

int pop(Stack* res)
{
    //Проверява дали има място в сетека
    if(cur_elem_count == 0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    //Премахва последния елемент на стека и го предава чрез указателя res, само ако res != NULL
    if (res) {
        *res = arr_begin[cur_elem_count - 1];
    }
    cur_elem_count--;
    return 0;
}

void print_elems()
{
    for(int i = 0; i < capacity; i++)
    {
        if (i<cur_elem_count) {
            
            printf("%3d ", arr_begin[i].data);
        }
        else {
         printf("___ ");
        }
    }
    printf("\n");
}


void deinitStac(Stack* arr)
{
    while (!(arr->data)) {
        pop(arr);
    }
    free(arr);
}