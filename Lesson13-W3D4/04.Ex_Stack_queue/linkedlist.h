#include <stdio.h>
#include <stdlib.h>

#ifndef  LINKED_LIST_H
#define LINKED_LIST_H 1

typedef struct Data
{
    int val;
}Data;

typedef struct Node{
    Data data;
    struct Node *next;
} Node;

typedef struct LL
{
    Node *head, *tail;
}LL;

void printLinkedList(LL *head);
void pushBack(Data newData,LL *ll);
void pushFront(Data newData,LL *ll);
void popBack(LL *ll, Data *result);
void popFront(LL *ll, Data *result);

LL* initLinkedlist();
void deinitLinkedList(LL *ll);
#endif