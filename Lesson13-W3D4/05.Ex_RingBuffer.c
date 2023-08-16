#include <stddef.h>
#include <stdio.h>

#define  N 5
typedef struct RingBuffer
{
    double *arr;
    size_t bufferCapacity, startIndex, endIndex;
}RingBuffer;

double arr[N];
// start_index - елементът, който е влязъл най-отдавна в опашката
// end_index - индексът, на който да запазим нов елемент в опашката (end_index - 1 е най-скорошният елемент на опашката)

size_t start_index = 0 , end_index = 0;
// read_pointer write_pointer
// enqueue - добавяме нов елемент при end_index
// dequeue - премахваме елемент от start_index

void print_buffer()
{
    for (size_t i = 0; i<N; i++) {
        if(arr[i]!=0)
        {
            printf("%3.2lf",arr[i]);
        }
        else{
            printf("---- ");
        }
    }
    printf("\n%ld\n\n",end_index - start_index);
}

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

int main() {
    print_buffer();
    enqueue(1);
    print_buffer();
    enqueue(2);
    print_buffer();
    enqueue(3);
    print_buffer();
    enqueue(4);
    print_buffer();
    enqueue(5);
    print_buffer();
    dequeue();
    print_buffer();
    dequeue();
    print_buffer();
    dequeue();
    print_buffer();
    dequeue();
    print_buffer();
    dequeue();
    print_buffer();
    dequeue();
    print_buffer();
    return 0;
}