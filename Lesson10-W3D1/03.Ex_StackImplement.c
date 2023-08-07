#include <stdio.h>
#include <stdlib.h>
//Импементация на стек с масив.
//Реализаирате следите функци.
//Добавяне и премахване на  елементи.

typedef  struct A{
    int data;
}A;

size_t capacity,cur_elem_count;
A* arr_begin;
//cur_elem_count is the number of elements stack
//capacity is max the number of elements stack

void init_stack_array(size_t max_elem_count) {
    // Заделя масив с max_elem_count на брой елементи в динамичната памет
    capacity = max_elem_count;
    cur_elem_count = 0;
    arr_begin = calloc(max_elem_count, sizeof(A));
}


//Push element to stack
int push(A element)
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

//Pop element from stack
int pop(A* res)
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

//Print element of steck
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

int main(int argc, char *argv[]) 
{
    init_stack_array(10);
    // A elem;
    // elem.data = 1;
    push((A){ .data = 1});
    print_elems();
    push((A){ .data = 2});
    print_elems();
    push((A){ .data = 3});
    print_elems();
    pop(NULL);
    print_elems();
    push((A){ .data = 4});
    print_elems();
    pop(NULL);
    print_elems();
    pop(NULL);
    print_elems();
    free(arr_begin);
    init_stack_array(20);
    return 0;
}