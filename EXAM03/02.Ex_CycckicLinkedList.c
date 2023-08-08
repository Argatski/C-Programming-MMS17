#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count=0;

/*ЗАДАЧА 2: - 10 т.
Цикличен свързан списък (cyclic linked list) е свързан списък, в който последният елемент пази указател (pointer) към първия елемент. 

Направете структурата Node, за която да се съхраняват следните данни::
int data;
struct Node *next; (Указател към следващия елемент на цикличния свързан списък)

(3т.) От стандартния вход се въвеждат числото N>0 и след това N цели  числа, разделени със SPACE. Създайте цикличен свързан списък в динамичната памет, чиито елементи са въведените числа. Погрижете се за освобождаването на динамичната памет.

(3т.) Напишете функцията void print(struct Node *cll), която приема указател към елемент на цикличен свързан списък (cll) като параметър. Функцията печата всичките елементи на cll на стандартния изход, точно по веднъж. Тествайте функцията, като я извикате в main.

(4т.) Напишете функцията:

struct Node* insertAfter(struct Node *cll, int skipCount, int newElem) 

Функцията приема следните параметри:
указател към първия елемент на цикличен свързан списък (cll)
брой позиции, които ще бъдат пропуснати (0 <= skipCount <= 1000000)
нов елемент, който да бъде добавен (newElem).

Функцията започва от cll, пропуска следващите skipCount на брой елемента и след това добавя новата стойност (newElem). Функцията връща указател към новодобавения елемент.

Тествайте функцията, като я извиквате в main, с различни тестови аргументи.

*/

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct LL
{
    Node *head;
}LL;

typedef struct Node node;

void pushBackCycle(int d,Node **h)
{
    //Dynamic memory
    Node *lastN = (Node*)malloc(sizeof(Node));
    if(!lastN)
    {
        printf("Not malloced\n");
        exit(-1);
    }
    lastN->data = d;
    lastN->next = NULL;

    if(*h==NULL)
    {
        *h = lastN;
        return;
    }
    //Get address of first node
    Node *firstN = *h;
    while(firstN->next!=NULL)
    {
        firstN = firstN->next;
    }

    firstN->next = lastN;
}

struct Node* insertAfter(struct Node *cll, int skipCount, int newElem)
{
    struct Node *newNode;
newNode = malloc(sizeof(Node));
newNode->data = newElem;

//Temp struct

struct Node *temp=cll;

for(int i=2; i < skipCount; i++) {
  if(temp->next != NULL) {
    temp = temp->next;
  }
}
newNode->next = temp->next;
temp->next = newNode;
}

//Print the cycle linked list
void printCycle(Node *h)
{
    if(h==NULL)
    {
        printf("Empty list\n");
        return;
    }
    Node *firstN = h;
    while(firstN->next!=NULL)
    {
        printf("%d ",firstN->data);
        firstN = firstN->next;
    }
    printf("%d\n",firstN->data);
}

int main(int argc, char *argv[]) 
{
    
    //Read N from console
    int n = 0;
    scanf("%d", &n);

     //Get count of argv[2]
    char array;
    scanf("%c", &array);

    //Length of char array
    int length = strlen(&array);


    //Dynamic memory
    LL *cll = (LL*)malloc(sizeof(LL));
    if(!cll)
    {
        printf("Not malloced\n");
        exit(-1);
    }
    cll->head = NULL;

   //Get number in char array;
    int number = 0;
    for(int i = 0; i < length; i++)
    {
        number = number * 10 + array - '0';
        pushBackCycle(number, &cll->head);
    }
    
    //Insert number in cll

    //Print the cycle linked list
    printCycle(cll->head);

    //Insert after
    int skipCount;
    int newElem;
    scanf("%d %d",&skipCount,&newElem);
    cll->head = insertAfter(cll->head,skipCount,newElem);

    //Print the cycle linked list
    printCycle(cll->head);


    //Dynamic memory
    free(cll);

    return 0;
    
}