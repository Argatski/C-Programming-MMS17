#include <stdio.h>

#ifndef Queue_H
#define Queue_H 2

typedef struct Queue {
    double *arr;
    size_t buffer_capacity, start_index, end_index;
} Queue;

void print_buffer();
void enqueue(double data);
double dequeue();

#endif