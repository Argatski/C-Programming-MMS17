#include<stdio.h>
#include<stdlib.h>

typedef struct A {
    int data;
} A;

typedef struct Queue {
    A *arr;
    size_t capacity;
    size_t cur_elem_count;
} Queue;

Queue init_queue(size_t capacity) {
    return (Queue) {
        .arr = calloc(capacity, sizeof(A)),
        .capacity = capacity,
        .cur_elem_count = 0
    };
}

int enqueue(Queue *q, A new_elem) {
    if(q->capacity == q->cur_elem_count) {
        return -1;
    }
    q->arr[q->cur_elem_count] = new_elem;
    q->cur_elem_count++;
    return 0;
}

int dequeue(Queue *q, A *res) {
    if(q->cur_elem_count == 0) {
        return -1;
    }
    if(res) {
        *res = q->arr[0];
    }
    q->cur_elem_count-=1;
    for(size_t i = 0; i < q->cur_elem_count; i++) {
        q->arr[i] = q->arr[i+1];
    }

    // q->arr[q->cur_elem_count] = (A){.data=0};

    // 1 2 3 4 5 _ _ _
    // q->arr[0] = q->arr[1];
    // 2 2 3 4 5 _ _ _
    // q->arr[1] = q->arr[2];
    // 2 3 3 4 5 _ _ _
    // q->arr[2] = q->arr[3];
    // 2 3 4 4 5 _ _ _
    // q->arr[3] = q->arr[4];
    // 2 3 4 5 _ _ _ _
    return 0;
}

void deinit(Queue q) {
    free(q.arr);
}
void print_elems(Queue q) {
    // Печата елементите на стека
    for(size_t i = 0; i < q.capacity; i++) {
        if(i < q.cur_elem_count) {
            printf("%3d ", q.arr[i].data);
        } else {
            printf("___ ");
        }
    }
    printf("\n");
}
int main() {
    Queue q1 = init_queue(10);
    enqueue(&q1, (A){.data = 1});
    print_elems(q1);
    enqueue(&q1, (A){.data = 2});
    print_elems(q1);
    enqueue(&q1, (A){.data = 3});
    print_elems(q1);
    A removed_elem;
    dequeue(&q1, &removed_elem);
    printf("REMOVED ELEMENT: %d\n", removed_elem.data);
    print_elems(q1);
    dequeue(&q1, NULL);
    print_elems(q1);
    enqueue(&q1, (A){.data = 4});
    print_elems(q1);
    enqueue(&q1, (A){.data = 5});
    print_elems(q1);
    enqueue(&q1, (A){.data = 6});
    print_elems(q1);
    dequeue(&q1, NULL);
    print_elems(q1);
    dequeue(&q1, NULL);
    print_elems(q1);
    deinit(q1);
    return 0;
}

// X X X X X
// enqueue(1)
// 1 - - - -
// enqueue(2)
// 1 2 - - -
// enqueue(3)
// 1 2 3 - -
// dequeue()
// 2 3 - - -
// dequeue()
// 3 - - - -



// X X X X X
// enqueue(1)
// 1 - - - -
// s
//   e
// enqueue(2)
// 1 2 - - -
// s   e
// enqueue(3)
// 1 2 3 - -
// s     e
// dequeue()
// - 2 3 - -
//   s   e
// dequeue()
// - - 3 - -
//     s e
// enqueue(4)
// enqueue(5)
// - - 3 4 5
//     s   
// e
// enqueue(6)
// 6 - 3 4 5
//     s 
//   e
// dequeue(7)