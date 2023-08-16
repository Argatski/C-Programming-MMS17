#include "linkedlist.h"

#ifndef QUEUE_H
#define QUEUE_H 1

typedef LL Stack;

Stack* init_queue() {
    return init_linked_list();
}

void push(Data new_elem, Stack *q) {
    push_back(new_elem, q);
}
void pop(Data *new_elem, Stack *q) {
    pop_back(q, new_elem);
}

void print_queue(Stack q) {
    print_linked_list(&q);
}

void deinit_queue(Stack *q) {
    deinit_linked_list(q);
}
#endif