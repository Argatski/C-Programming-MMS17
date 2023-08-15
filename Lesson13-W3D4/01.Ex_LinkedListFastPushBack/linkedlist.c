#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void printLinkedList(LL *ll)
{
    Node *head = ll->head;
    //Print all elements of the linked list
    for (; head!=NULL; head=head->next)
    {
        printf("%d ", head->data.val);
    }
    if (ll->tail!=NULL) {
    printf("\nLast element value is: %d\n", ll->tail->data.val);
    }
}

void pushBack(Data newData, LL *ll)
{
    //*head - Node*
    //**Head - Node*
    //Allocate dynamic memory for new node
    Node **head =  &(ll->head);
    Node **tail = &(ll->tail);

    Node *newLastNode = malloc(sizeof(Node));
    if (!newLastNode) {
        perror("Couldn't allocate memory for new node");
        exit(-1);    
    }

    newLastNode->data=newData;
    newLastNode->next=NULL;

    //Empty linked list
    if (*head==NULL) {
        *head=newLastNode;;
        *tail=newLastNode;
    }

    //After last element insert new Noed
    (*tail)->next=newLastNode;
    //*tail save address of new last noed
    *tail=(*tail)->next;
}

void popBack(LL *ll, Data *result)
{
    Node **head=&(ll->head);
    Node **tail=&(ll->tail);

    //Empty linked list
    if(!(*head))
    {
        perror("Cannot pop from empty linked list");
    }
    //Only one element in linked list
    if((*head)->next==NULL)
    {
        *result= (*head)->data;
        free(*head);
        *head=NULL;
        tail=NULL;
        return;
    }
    //Find second to last element

    Node* curNode=*head;
    //While the nex node is not the last one
    while (curNode->next->next!=NULL) {
        curNode=curNode->next;
    }

    //After while - cur node is second to last node
    //After While  - curNode->next to last node
    *result= curNode->data;

    //Free last node
    free(curNode);
    curNode-> next=NULL;

    //Tail will point to new last node
    *tail=curNode;
}

void pushFront(Data newData, LL *ll)
{
    Node** head = &(ll->head);

    //Allocate dynamic memory for new node
    Node* newFirstNode =  malloc(sizeof(Node));
    if(newFirstNode==NULL)
    {
        perror("Could`t allocate dynamic memory\n");
        exit(-1);
    }
    newFirstNode->data=newData;
    newFirstNode->next=*head;
    *head=newFirstNode;

    //If linked list was empty(tail is NULL)
    //Must change tail to point to newfirstNode
    if (ll->tail==NULL) {
        ll->tail=newFirstNode;
    }

}

void popFront(LL *ll, Data *result)
{
    Node** head=&(ll->head);

    if (*head==NULL) {
        perror("Cannot pop from empty list");
        exit(-1);
    }

    // Ако подадем NULL Като втори аргумент - не записваме премахнатия NODE никъде
    if (result!=NULL) {
    *result = (*head)->data;
    }

    Node* secondNode=(*head)->next;
    free(head);
    *head=secondNode;

    // След премахване на първия елемент
    // Ако преди е имало само един елемент
    // Тогава *head Ще е станал NULL
    if(*head==NULL)
    {
        ll->tail=NULL;
    }
}

LL* initLinkedList()
{
    //Allocate memory for linked list
    LL* ll = malloc(sizeof(LL));

    if (!ll) {
        perror("Couldn't allocate memory for linked list\n");
        exit(-1);
    }

    //Empty linked list
    ll->head=NULL;
    ll->tail=NULL;
    return ll;
}

void deinitLinkedList(LL *ll)
{
    //Is linked list empty
    //Node **head
    //*head is NULL 

    //Is empty linked list
    while (!(ll->head)) {
        popFront(ll, NULL);
    }

    free(ll);
}
