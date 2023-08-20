#include <stdint.h>
#include <stdio.h>

#define ITEM_COUNT 1;

typedef struct BankAccount
{
    uint16_t number;
    char name[101];
    double amount;
    char valued[5];
}BankAccount;

BankAccount bankAcc[ITEM_COUNT];
int main(int argc, char** argv)
{
    
}