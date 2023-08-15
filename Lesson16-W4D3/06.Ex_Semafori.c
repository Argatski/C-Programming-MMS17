#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h> //import from threads
#include <semaphore.h> //import when use semafor method 

#define THREAD_NUMBER 12

//Setting semafor
sem_t mySem;

//1. sem_t mySem
//2. lock -set_wait(); // in myFunc
//3  unlock - sem_post()//in myFunc
//4 sem_init(...)
//5 sem_destroy

void* myFunc(void* arg)
{
    sem_wait(&mySem);//Decrement counter

    sleep(1);
    printf("Hello from thread: %d\n",*(int*)arg);//TODO

    free(arg);// to free memory occupied by this argument

    sem_post(&mySem);//Increment counter

    return 0;
}

int main(int argc,char* argv[])
{
    pthread_t threads[THREAD_NUMBER];

    //Init 
    sem_init(&mySem, 0, 3);// 0 2, 0 4 , 0 6



    //CREATE THREADS
    for (size_t i = 0; i<THREAD_NUMBER;i++)
    {
        //Create variable by memory allocation
        int* a = malloc(sizeof(int));
        *a=i;

        if(pthread_create(&threads[i],NULL,&myFunc,a)!=0)
        {
            printf("Error creating thread\n");
        }
    
    }

    //JOIN TREADS
    for (size_t i = 0; i<THREAD_NUMBER;i++)
    {
        if(pthread_join(threads[i],NULL)!=0)
        {
            printf("Error joining thread\n");
        }
    
    }

    sem_destroy(&mySem);

    return 0;
}