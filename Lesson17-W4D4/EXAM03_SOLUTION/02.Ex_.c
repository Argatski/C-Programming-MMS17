#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;   // 4 byte
    struct Node* next;  // 8 byte
} Node;
void print(Node *head) {
    if(head == NULL) {
        printf("Empty list\n");
        return;
    }
    Node* cur_node = head->next;
    
    printf("%d ", head->data);
    while(cur_node != head) {
        printf("%d ", cur_node->data);
        cur_node = cur_node->next;
    }
    printf("\n");
}
struct Node* insertAfter(struct Node *cll, int skipCount, int newElem) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = newElem;

    // Skip skipCount nodes
    if (cll != NULL)
    {
        for (size_t i = 0; i < skipCount; i++)
        {
            cll = cll->next;
        }
        newNode->next = cll->next;
        cll->next = newNode;
    } else {
        newNode->next = newNode;
        return newNode;
    }
    return newNode;
}

int main() {
    int N;
    scanf("%d", &N);

    Node *head = NULL, *last_node = NULL;

    if (N > 0)
    {
        // Allocate memory for first node
        head = malloc(sizeof(Node));
        scanf("%d", &(head->data));
        last_node = head;


        // Allocate memory for nodes
        // Read node data from stdin
        for (size_t i = 1; i < N; i++)
        {
            Node *cur_node = malloc(sizeof(Node));
            scanf("%d", &(cur_node->data));

            last_node->next = cur_node;
            last_node = cur_node;
        }
        // Make cyclic linked list
        last_node->next = head;
    }

    

    print(head);
    head = insertAfter(head, 0, 9999);
    head = insertAfter(head, 0, 1);
    head = insertAfter(head, 0, 2);
    head = insertAfter(head, 0, 3);
    head = insertAfter(head, 0, 4);
    head = insertAfter(head, 0, 5);
    print(head);


    // Free dynamic memory, allocated for nodes
    Node *cur_node = head->next;
    while(cur_node != head) {
        Node *deleted_node = cur_node;
        cur_node = cur_node->next;
        free(deleted_node);
    }
    free(head);
    return 0;
}