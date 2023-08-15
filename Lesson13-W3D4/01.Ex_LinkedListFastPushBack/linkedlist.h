#include <stdio.h>
#include <stdlib.h>

#ifndef  LINKED_LIST_H
#define  LINKED_LIST_H 1

typedef struct Data
{
    int val;
}Data;

typedef struct Node
{
    Data data;
    struct Node *next;
} Node;

typedef struct LL
{
    Node *head;
    Node *tail;
}LL;

void printLinkedList(LL *ll);
void pushBack(Data newData,LL *ll);
void popBack(LL *ll, Data *result);
void pushFront( Data newData,LL *ll);
void popFront(LL *ll, Data *result);
LL* initLinkedList();
void deinitLinkedList(LL *ll);

#endif