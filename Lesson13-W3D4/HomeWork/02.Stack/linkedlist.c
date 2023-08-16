#include "linkedlist.h"
void print_linked_list(LL *ll) {
    Node *head = ll->head;
    // Да изпечатаме всеки елемент на свързания списък
    for(;head != NULL; head=head->next) {
        printf("%d ", head->d.val);
    }
    if(ll->tail != NULL) {
        printf("\nLAST ELEMENT VALUE IS: %d\n\n", ll->tail->d.val);
    }
}
// Node NODE1 = .....;
// Node *MY_HEAD_5 = &NODE1;
void push_back(Data new_data, LL *ll) {
    // *head - Node*
    // **head - Node
    // Allocate dynamic memory for new node
    Node **head = &(ll->head);
    Node **tail = &(ll->tail);

    Node *new_last_node = malloc(sizeof(Node));
    if(!new_last_node) {
        perror("Could not malloc\n");
        exit(-1);
    }
    new_last_node->d = new_data;
    new_last_node->next = NULL;

    // Empty linked list
    if(*head == NULL) {
        *head = new_last_node;
        *tail = new_last_node;
        return;
    }

    // След последния елемент добавяме нов Node
    (*tail) -> next = new_last_node;
    // *tail ще пази адреса на новия последен елемент
    *tail = (*tail) -> next;
}
// n1 -----> n2 -------> n3

void pop_back(LL *ll, Data *result) {
    Node **head = &(ll->head);
    Node **tail = &(ll->tail);

    // Empty linked list
    if(!(*head)) { // *head == NULL
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }
    // Only one element in linked list
    if((*head)->next == NULL) {
        *result = (*head)->d;
        free(*head);
        *head = NULL; 
        *tail = NULL;
        return;
    }
    // Find second to last element
    Node *cur_node = *head;
    // While the next node is not the last one
    while(cur_node->next->next != NULL) {
        cur_node = cur_node->next;
    }
    // After while - cur_node is second to last node
    // After while - cur_node->next to last node
    *result = cur_node->next->d;
    // Free last node
    free(cur_node->next);
    cur_node->next = NULL;

    // Tail will point to new last node
    *tail = cur_node;
}


LL* init_linked_list() {
    // Allocate memory for LL
    LL *ll = (LL*)malloc(sizeof(LL));
    if(!ll) {
        perror("Could not malloc\n");
        exit(-1);
    }
    // Empty linked list
    ll -> head = NULL; 
    ll -> tail = NULL;
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
        pop_back(ll, NULL);
    }
    free(ll);
}