#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
    int val;
}Data;

typedef struct Node
{
    Data d;
    struct Node *next;
}Node;

typedef struct LL
{
    Node *head;
}LL;

//Print functions
void printLinkedList(Node *head)
{
    //Print all elements in the linked list
    while(head!= NULL)
    {
        printf("%d ", head->d.val);
        head = head->next;
    }
    printf("\n");
}

//Push back element in the linked list
void pushBack(Data newData, Node** head)
{
    //*head == Node*
    //**head = Node
    //Allocate dynamic memory for the new node
    Node *newLastNode = malloc(sizeof(Node));

    //Check if new last node isn`t allocated memory
    if (!newLastNode){
        perror("Couldn't allocate memory\n");
        exit(-1);
    }
    newLastNode->d = newData;//las element have new data
    newLastNode->next = NULL; //last element get pointer to null

    if(*head==NULL)
    {
        *head = newLastNode;
        return;
    }

    //Get address of firest node
    Node *cur_node =*head;

    while(cur_node->next!=NULL)
    {
        cur_node->next = newLastNode;
    }
    //Agter wile loop = current node keeps addres of last node
    cur_node->next =   newLastNode;

}

void popBack(Node **head,Data *result)
{
    //Emoty linked list
    if (!(*head)) {
        perror("Connow pop for empty linked list\n");
        exit(-1);
    }

    //Only one element in linked list
    if ((*head)->next == NULL) {
        *result = (*head)->d;
        free(*head);
        *head = NULL;
    }

    //Find second to last element
    Node *cur_node = *head;
    //While the next node is not the last one
    while (cur_node->next->next != NULL) {
    cur_node = cur_node->next;
    }
    //After while - cur_node is second to last node
    //After while - cur_node-next to last node

    *result = cur_node->next->d;

    //Free last node
    free(cur_node->next);
    cur_node->next=NULL;
}

void pushFront(Data newData,Node**head)
{
    //Allocate dynamic memory for the new node
    Node *newFirstNode = malloc(sizeof(Node));

    if (newFirstNode==NULL) {
    perror("Could not malloc");
    exit(-1);
    }   

    newFirstNode->d = newData;
    newFirstNode->next = *head;
    *head = newFirstNode;
}

void popFront(Node **head,Data* res)
{
    if (*head==NULL) {
        perror("Could not pop from empty linked list\n");
        exit(-1);
    }

    *res = (*head)->d;
    Node *secondNode = (*head)->next;
    free(*head);
    *head = secondNode;
}

struct Node* insertAfter(size_t skip_n,Node **head,int element)
{
    // 1. С цикъл пропускаме първите skip_n елемента (ако можем). Цикъла намира стойностите на Node *before, Node* after.
    // 2. Заделяме памет за нов Node - new_node
    // before->next = new_node;
    // new_node->next = after;
    Node *newNode = malloc(sizeof(Node));
    newNode->d.val=element;

    if (*head!=NULL) {
        for (size_t i=0; i<skip_n; i++) {
            *head=(*head)->next;
        }
        newNode->next = (*head)->next;
        (*head)->next =newNode;
    }
    else {
    newNode->next = newNode;
    return newNode;
    }
    return newNode;
}

int main(int argc, char **argv)
{
    Node *head = NULL;
    Data res;
    pushBack((Data){100}, &head);
    printLinkedList(head);

    pushFront((Data){58}, &head);
    printLinkedList(head);

    insertAfter(0, &head, 52);
    printLinkedList(head);

    popBack(&head,&res);
    printLinkedList(head);
    
    popFront(&head,&res);
    printLinkedList(head);


    return 0;
}