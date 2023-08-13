#include <stdio.h>
#include <stdlib.h>

typedef  struct Data
{
  int val;
}Data;

typedef struct Node
{
    Data data;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct QueueMy
{
    struct Node *front;
    struct Node *back;
    int size;

} QueueMy ;

Node * getNode(int data,Node *prev)
{
    Node *cur = malloc(sizeof(Node));

    if(cur == NULL)
    {
        printf("Failed to allocate dynamic memory:\n");
        exit(-1);
    }
    cur->data.val = data;
    cur->next = NULL;
    cur->prev = prev;
    return cur;
}

QueueMy * getQueue()
{
    QueueMy *cur = malloc(sizeof(QueueMy));

    if (cur == NULL) {
        printf("Failed to allocate dynamic memory:\n");
        exit(-1);
    }
    cur->front = NULL;
    cur->back = NULL;
    return cur;
}

int isEmpty(QueueMy * cur)
{
    if(cur->size == 0) {
        return -1;
    }
    else {
    return 0;
    }
}

//Peek functions
int peek(QueueMy * cur)
{
    if (isEmpty(cur)==1) {
    printf("Empty Queue\n");
    return -1;
    }
    else {
    return cur->front->data.val;
    }
}

//Enqueue element back to queue
void enqueueBack(QueueMy * cur,int data)
{
    Node *node=getNode(data, cur->back);
    //If true then new element cannot be added and it is an "Overflow" condition
    if(node==NULL) {
        printf("Empty Queue\n");
        exit(-1);
    }
    else {
        //if deque is em
        if (cur->back == NULL) {
          cur->front = cur->back=node;
        } 
        else {//Insert node at the rear end
          node->prev= cur->back;
          cur->back->next=node;
          cur->back=node;
        }
        cur->size++;
    }
    
}
//Enqueu element front to queue
void enqueueFront(QueueMy * cur,int data)
{
    Node *newNode;

    newNode = getNode(data,cur->front);
    if (newNode == NULL) {
        printf("Overflow\n");
        exit(-1);
    }
    else {
        //If deque is empty
        if(cur->front == NULL) {
            cur->back = cur->front=newNode;
        }
        //Insert node at the front end
        else {
        newNode->next = cur->front;
        cur->front->prev = newNode;
        cur->front=newNode;
        }
        //Increments count of elements by 1
        cur->size++;
    }
    
}

//Dequeue element front to queue 
void dequeueFront(QueueMy * cur)
{
    if (isEmpty(cur)==1) {
        printf("Queue is empty\n");
        exit(-1);
    }
    else {
        Node * temp = cur->front;
        cur->front = cur->front->next;

        if (cur->front == NULL) {
        cur->back = NULL;
        }
        else {
        cur->front->prev = NULL;
        }
        free(temp);
        cur->size--;
    }
}

//Dequeue element back to queue
void dequeueBack(QueueMy * cur)
{
    //If deque is empty then return "Underflow" condition
    if (isEmpty(cur)==1) {
    
        printf("Underflow\n");
        exit(-1);
    }
    //Deletes the node from the back end and makes the adjustment in the links
    else{
        Node * temp = cur->back;
        cur->back = cur->back->prev;
        

        //If only one element was present
        if (cur->back==NULL) {
            cur->front = NULL;
        }
        else {
        cur->back->next =  NULL;
        }
        free(temp);

        //Decrements count of elements by 1
        cur->size--;
    }
}

int isSize(QueueMy * cur)
{
    return cur->size;
}

//Prints all the elements in the queue
void printQdata(QueueMy * ref)
{
   Node * cur = ref->front;
   printf("Queue elements\n");

   while (cur!=NULL) {
   printf("%d ", cur->data.val);
   cur = cur->next;
   }
   printf("\n");
}


int main(int argc, char *argv[])
{
    QueueMy *queue = getQueue();

    //Enqueues element in back to queue
    enqueueBack(queue, 1);
    enqueueBack(queue, 2);
    enqueueBack(queue, 4);
    enqueueBack(queue, 5);
    enqueueBack(queue, 9);

    printQdata(queue);

    //Enqueue element in front of queue
    enqueueFront(queue, 10);
    enqueueFront(queue, 30);

    printQdata(queue);

    //Dequeue element in back of queue
   dequeueBack(queue);
    
    printQdata(queue);

    //Dequeue element in front of queue
    dequeueFront(queue);
    printQdata(queue);

    printf("Size of queue: %d\n", isSize(queue));

    free(queue);

    return 0;
}