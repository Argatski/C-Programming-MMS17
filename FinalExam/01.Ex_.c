#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEM_COUNT 2

typedef struct BankAccount {
  unsigned short number;
  char name[100];
  double bal;
  char valued[4];

  struct BankAccount *next;

} BankAccount;


// Символни низове за валутите
const char *valued[] = {"BGN", "USD", "EUR", "GBP"};

// номер - цяло положително 16 битово число - уникално за всеки елемент в
// списъка;
unsigned short randomNum() 
{ 
    return (unsigned short)rand() % (65536);
}

// наличност - реално число между 0.00лв и 100 000.00лв;
double randoDouble(double min, double max) {
  return (double)rand() / RAND_MAX * (max - min) + min;
}

// име на притежател - Съдържа между 2 и 5 произволни думи, разделени с
// интервал. Всяка дума е между 1 и 20 произволни символа (малки или главни
// латински букви).  Всяка дума започва с главна буква.

// char *word()
// {
//     int len =  rand() %(5-2+1)+1;
//     char buffer[len];

//     size_t r = rand() % 25;

//     if (r <= 25) {
//       buffer[0] = 'A' + r;
//     }

//     for(int i = 1; i < len; i++)
//     {
//         if (r<=25) {
//             buffer[i] = 'a'+r;
//         }
//     }
//     buffer[len] = '\0';
// }

void randomName(char *name) 
{
    int len =  rand() %(5-2+1)+1;
    char buffer[len];

    size_t r = rand() % 25;

    if (r <= 25) {
      buffer[0] = 'A' + r;
    }

    for(int i = 1; i < len; i++)
    {
        if (r<=25) {
            buffer[i] = 'a'+r;
        }
    }
    buffer[len] = ' ';

    strcat(name, buffer);
    strcat(name, "");

    len =  rand() %(5-2+1)+1;
    buffer[len];

    if (r <= 25) {
      buffer[0] = 'A' + r;
    }

    for(int i = 1; i < len; i++)
    {
        if (r<=25) {
            buffer[i] = 'a'+r;
        }
    }
    buffer[len] = '\0';

    strcat(name, buffer);
}


double totalBalance(BankAccount *head) {
  double totalBalance = -1;
  while (head != NULL) {
    totalBalance += head->bal;
    head = head->next;
  }

  return totalBalance;
}

BankAccount *maxBalance(BankAccount *head) {
  BankAccount *maxAccount = NULL;
  double max = 0;

  while (head != NULL) {
    if (max < head->bal){
      max = head->bal;
    maxAccount = head;}

    head =head->next;
  }

  return maxAccount;
}

BankAccount *init_Bank() {
  BankAccount *acc = malloc(sizeof(BankAccount));
  acc->number = randomNum();
  randomName(acc->name);
  acc->bal = randoDouble(0., 100000.);
  strcpy(acc->valued, valued[rand() % 4]);

  acc->next = NULL;
  return acc;
}

int main(int argc, char **argv) 
{
    BankAccount* head = NULL;
    BankAccount* tail = NULL;

    // initialize
    for(int i = 0; i < ITEM_COUNT; i++)
    {
        BankAccount * new =  init_Bank();
        if (head == NULL) {
        head = new;
        tail = new;
        }
        else {
            tail->next = new;
            tail=new;
        }
    }

    printf("Bank Accounts\n");

    BankAccount* cur =  head;

    while (cur!=NULL) {
        printf("Number: %hu, Name:%s, Balance: %.2lf \n",cur->number,cur->name,cur->bal);
        cur = cur->next;
    }

    double total = totalBalance(head);
    printf("Balance: %lf",total);

    BankAccount * highAcc = maxBalance(head);
    if (highAcc != NULL) {
        printf("Number: %hu, Name:%s, Balance: %.2lf\n",highAcc->number,highAcc->name,highAcc->bal);
    }
    else
    {
        printf("Haven`t bank accounts.\n");
    }

    //Free dynamic memory
    cur = head;
    while (cur != NULL) {
        BankAccount* t = cur;
        cur=cur->next;
        free(t);
     }

}