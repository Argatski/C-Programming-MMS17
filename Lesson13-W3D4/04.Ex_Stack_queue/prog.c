#include "linkedlist.h"
#include "queue.h"

Data d1;
int main() {
    LL *ll = initLinkedlist();
    pushBack((Data){1}, ll);
    printLinkedList(ll);
    pushBack((Data){2}, ll);
    printLinkedList(ll);
    pushBack((Data){3}, ll);
    printLinkedList(ll);
    pushBack((Data){4}, ll);
    printLinkedList(ll);
    Data d;
    popBack(ll, &d);
    printLinkedList(ll);
    popFront(ll, NULL);
    printLinkedList(ll);
    popFront(ll, NULL);
    printLinkedList(ll);
    deinitLinkedList(ll);

    Queue *q1 = initQueue();
    enqueue((Data){10}, q1);
    printQueue(*q1);
    enqueue((Data){20}, q1);
    printQueue(*q1);
    enqueue((Data){30}, q1);
    printQueue(*q1);

    Data *d3 = malloc(sizeof(Data));
    (*d3).val = 100;
    d3->val = 200;
    // d3->val will be overwritten over 
    dequeue(d3, q1);

    printQueue(*q1);
    enqueue((Data){40}, q1);
    printQueue(*q1);

    dequeue(&d1, q1);
    printQueue(*q1);
    dequeue(&d1, q1);
    printQueue(*q1);

    deinitQueue(q1);
    return 0;
}