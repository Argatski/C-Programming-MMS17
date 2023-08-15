#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h> //Importan for threads

//My funciton to be executed from threads
void* myTask01()
{
    printf("Hello from my Taks01!\n");

    sleep(3);

    printf("Ending thread!\n");

    return 0;
}

int main(int argc,char* argv[])
{
    pthread_t tr1,tr2; //2 threads promenlivi 

    //Create threads - (suntaksis)
    if(pthread_create(&tr1,NULL, &myTask01,NULL)!=0)
    {
        return 1;//Error code 1  int this case
    };

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


    return 0;
}
// gcc name -lm -pthread -o name -Wall -Wextra -Werorr
//za kompilaciq
//analogichna komanda za da moje da premine prez proceiite e pthread_join anologichno na wait