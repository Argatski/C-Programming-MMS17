#include "linkedlist.h"

#ifndef QUEUE_H
#define  QUEUE_H 1

typedef LL Queue ;

Queue* initQueue()
{
    return initLinkedlist();
}

void enqueue(Data newElem,Queue* q)
{
    pushBack(newElem, q);
}

void dequeue(Data *newElem,Queue* q)
{
    popFront(q,newElem);
}

void printQueue(Queue q)
{
    printLinkedList(&q);
}

void deinitQueue(Queue *q)
{
    deinitLinkedList(q);
}

#endif 