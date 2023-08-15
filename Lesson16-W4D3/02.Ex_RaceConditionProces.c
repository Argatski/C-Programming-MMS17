#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h> //Importan for threads

int myCount =0;

//My funciton to be executed from threads
//Stop work corect when "i" it is 1000000
void* myTask01()
{
    for (size_t i=0; i<1000; i++) {
        myCount++;
        //edna komanda izpulva 3 neshta
        //read myCounter
        //increment myCounter
        //wriite myCounter
    }
    

    printf("Current counter: %d\n",myCount);
    return 0;
}

int main(int argc,char* argv[])
{
    pthread_t tr1,tr2; //2 threads 

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

    
    //Join threads(as wait() in process)
    if(pthread_join(tr1,NULL)!=0)
    {
        return 3;
    };

    if(pthread_join(tr2, NULL)!=0)
    {
        return 4;
    };

    

    printf("Counter is: %d\n",myCount);

    return 0;
}
// gcc name -lm -pthread -o name -Wall -Wextra -Werorr
//za kompilaciq
//analogichna komanda za da moje da premine prez proceiite e pthread_join anologichno na wait