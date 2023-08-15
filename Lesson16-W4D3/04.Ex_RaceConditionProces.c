#include <bits/types/sigevent_t.h>
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <pthread.h>

///Class work  -  Bank Account threads

#define NUM_THREADS 3 
#define INIT_BALANCE 1000

typedef struct BankAccount 
{
  int balance;//Balance of account

} BankAccount;

BankAccount account;

//Func - Deposit
void* deposit(void *arg) 
{
    int amount = *((int*)arg);//To use the value passed as *arguments
    account.balance += amount;

    return 0;
}

//Fund - Withdraw
void* withdraw(void* arg) 
{
    int amount = *((int*)arg);//To use the value passed as *arguments
    account.balance-=amount;

    return  0;
}



int main(int argc,char* argv[]) 
{   
    //Initialize our account balances
    account.balance=INIT_BALANCE;

    //Create number of threads
    pthread_t threads[NUM_THREADS];

    //Create and initialize the amount to deposit and withdraw
    int deposit_amount = 200;//2 4 and 6 threads deposit = 3*200=>600=>1600;
    int withdraw_amount = 100;//1 3 5 and 7 threads withdraw =4*100=>400=>1200;


    //First for-loop to iterate over the threads
    for(size_t i =0; i<NUM_THREADS;i++)
    {
        //if even - deposit
        if (i%2==0) {
            pthread_create(&threads[i], NULL,deposit,&deposit_amount);

        }
        //if odd - whitdraw
        else
        {
            pthread_create(&threads[i], NULL, withdraw,&withdraw_amount);
        }

        printf("Current balance: %d\n",account.balance);

    }


    //for-loop to iterate over the treads and JOIN threads
    for (size_t i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }


    printf("Finance balance of My Account: %d\n",account.balance);

     return 0;
 }