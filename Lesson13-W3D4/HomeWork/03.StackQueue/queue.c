#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define N 100

double arr[N];
size_t start_index = 0, end_index = 0;

void enqueue(double data) {
    if(start_index > N) {
        start_index -= N;
        end_index -= N;
    }
    if(end_index - start_index == N) {
        perror("Ring buffer is full.");
        return;
    }
    arr[end_index%N] = data;
    end_index++;
}

double dequeue() {
    if(end_index - start_index == 0) {
        perror("Ring bufffer is empty");
        return 0;
    }
    size_t old_start = start_index;
    arr[old_start] = 0; // Unnecesarry
    start_index++;
    return arr[old_start%N];
}

void print_buffer()
{
     for(size_t i = 0; i < N; i++) {
        if(arr[i] != 0) {
            printf("%3.2lf ", arr[i]);
        } else {
            printf("---- ");
        }
    }
    printf("\n%ld\n\n", end_index - start_index);
}
