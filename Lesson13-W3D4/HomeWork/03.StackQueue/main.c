#include <stdio.h>

#include "stack.h"
#include "queue.h"


int main(int argc, char **argv)
{
    Stack s1;
    int count;
    printf("Input size of stack:\n");
    scanf("%d", &count);
    init_stack_array(count);

    s1.data = 5;
    printf("Input data for stack:\n");
    for(int i = 0; i < count; i++)
    {
        int x;
        scanf("%d", &x);
        s1.data = x;
        push(s1);
    }

    print_elems();

    pop(&s1);
    print_elems();

    Queue q;
    int capacity ;
    printf("Input capacity of queue:\n");
    scanf("%d", &capacity);
    q.buffer_capacity = capacity;

    printf("Input data for stack:\n");
    for(int i = 0; i < capacity; i++)
    {
        double data;
        scanf("%lf", &data);
        enqueue(data);
    }

    print_buffer();

    dequeue();
    dequeue();

    print_buffer();


    

}