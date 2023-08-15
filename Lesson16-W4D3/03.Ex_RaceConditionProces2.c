#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h> //Importan for threads

int myCount =0;



//My funciton to be executed from threads
void* myTask01()
{
    for (size_t i=0; i<10000; i++) {
        myCount++;
        //edna komanda izpulva 3 neshta
        //read myCounter
        //increment myCounter
        //wriite myCounter
    }
    

    printf("Current counter: %d\n",myCount);
    return 0;
}

void* myTask02()
{
    for (size_t i=0; i<2; i++) {
     myTask01();
    }
    return 0;
}

int main(int argc,char* argv[])
{
    pthread_t tr1,tr2,tr3,tr4; //4 threads 

    //Create threads - (suntaksis)
    //Thread 1
    if(pthread_create(&tr1,NULL, &myTask01,NULL)!=0)
    {
        return 1;//Error code 1  int this case
    };
    //Thread 2
    if(pthread_create(&tr2,NULL, &myTask01,NULL)!=0)
    {
        return 2;
    };

    //Thread 3
    if(pthread_create(&tr3,NULL, &myTask02,NULL)!=0)
    {
        return 3;
    };

    //Thread4
    if(pthread_create(&tr4,NULL, &myTask02,NULL)!=0)
    {
        return 4;
    };
    
    //Join threads(as wait() in process)
    if(pthread_join(tr1,NULL)!=0)
    {
        return 5;
    };

    if(pthread_join(tr2, NULL)!=0)
    {
        return 6;
    };

    if(pthread_join(tr3,NULL)!=0)
    {
        return 7;
    };

    if(pthread_join(tr4, NULL)!=0)
    {
        return 8;
    };


    printf("Counter is: %d\n",myCount);

    return 0;
}
// gcc name -lm -pthread -o name -Wall -Wextra -Werorr
//za kompilaciq
//analogichna komanda za da moje da premine prez proceiite e pthread_join anologichno na wait