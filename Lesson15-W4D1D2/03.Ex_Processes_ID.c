#include <stdio.h>
#include <stdio.h>
#include   <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    // printf("Print getpid %d\n",getpid());
    
    // //{2}
    // printf("Print getppid %d \n",getppid());

    //{5}
    if(pid==0)
    {
        printf("sleep 3 seconds...\n");
        sleep(3);
    }

    //{4}
    printf("Current pid %d, parent pid %d\n",getpid(),getppid());

    // //{6.1} izchakvat se dvete komandi i paranta e chaild chailda e perant.
   // wait(NULL);

    //{6.2} == 6.1 kato otgovor no po dobre da proverqvame s if proverka
    if(pid!=0)
    {
        wait(NULL);
    }

    //DVA PROCESA RABOTQTA PARALELNO 
    //
}