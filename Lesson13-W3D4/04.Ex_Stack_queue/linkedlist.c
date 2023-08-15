#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void printLinkedList(LL *ll) {
  Node *head = ll->head;
  // Print all elements of the linked list
  for (; head != NULL; head = head->next) {
    printf("%d ", head->data.val);
  }
  if (ll->tail != NULL) {
    printf("\nLAST ELEMENT VALUE IS: %d\n\n", ll->tail->data.val);
  }
}

void pushBack(Data newData, LL *ll) {
  // Allocate memory for the new data
  Node **head = &(ll->head);
  Node **tail = &(ll->tail);

  Node *newLastNode = malloc(sizeof(Node));
  if (!newLastNode) {
    perror("Cannot allocate memory");
    exit(-1);
  }

  newLastNode->data = newData;
  newLastNode->next = NULL;

  // Empty linked list
  if (*head == NULL) {
    *head = newLastNode;
    *tail = newLastNode;
    return;
  }

  // Last element add new node
  (*tail)->next = newLastNode;

  // tail save address of new node
  *tail = (*tail)->next;
}

void popBack(LL *ll, Data *result) {
  Node **head = &(ll->head);
  Node **tail = &(ll->tail);

  // Empty linked list
  if (!(*head)) {
    perror("Cannot pop from empty linked list\n");
    exit(-1);
  }

  // Only one element in linked list
  if ((*head)->next == NULL) {
    *result = (*head)->data;
    free(*head);
    *head = NULL;
    *tail = NULL;
  }

  //Find second to last element
  Node *curNode = *head;

  //While the next node is not the last one
  while (curNode->next->next != NULL) {
    curNode = curNode->next;
  }

  //After while = curNode is second to last node
  //Afte while - curNode->next to last node
  *result = curNode->next->data;

  //Free last node
  free(curNode);
  curNode->next = NULL;

  //Tail will poin to new last node
  *tail = curNode;
}

void pushFront(Data newData, LL *ll)
{
    Node **head = &(ll->head);
    
    //Allocate memory for the new node
    Node *newFirstNode =  malloc(sizeof(Node));

    if (newFirstNode == NULL) {
        perror("Could't allocate memory for new node\n");
        exit(-1);
    }
    newFirstNode->data = newData;
    newFirstNode->next = NULL;
    *head = newFirstNode;

    //If linked list was empty(tail is null)
    //Must chage tail to point to new first node

    if (ll->tail == NULL) {
        ll->tail = newFirstNode;
    }
}

void popFront(LL *ll, Data *result)
{
    Node **head = &(ll->head);

    if (*head == NULL) {
        perror("Couldn't pop from empty linked list\n");
        exit(-1);
    }

    //If set result to NULL - NOTE not saved
    if (result !=NULL) {
        *result = (*head)->data;
    }

    Node *secondNode = (*head)->next;
    free(*head);
    *head = secondNode;

    // След премахване на първия елемент
    // Ако преди е имало само един елемент
    // Тогава *head Ще е станал NULL
    if(*head == NULL) {
        ll->tail = NULL;
    }
}

// void insert_after(size_t skip_n, Node** head) {
//     // 1. С цикъл пропускаме първите skip_n елемента (ако можем). Цикъла намира стойностите на Node *before, Node* after.
//     // 2. Заделяме памет за нов Node - new_node
//     // before->next = new_node;
//     // new_node->next = after;
// }

LL* initLinkedList()
{
    //Allocate memory for linked list
    LL* ll =  malloc(sizeof(LL));

    if (!ll) {
        perror("Could`t allocate memory for linked list\n");
    exit(-1);
    }

    //Empty linked list
    ll->head = NULL;
    ll->tail = NULL;
    return ll;
}

void deinit_linked_list(LL* ll) {
    // Is linked list empty
    // NODE **head;
    // *head дали е NULL

    // LL *ll;
    // ll->head дали е NULL

    // Is empty
    while(!(ll->head)) {
        // NULL - не искаме никъде да запишем резултата
        popFront(ll, NULL);
    }
    free(ll);
}