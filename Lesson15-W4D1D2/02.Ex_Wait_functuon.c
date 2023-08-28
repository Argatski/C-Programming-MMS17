#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <time.h>
#include <sys/wait.h>



int main()
{
    int pid =fork();
    int n;

    if (pid==0) {
        n=1;
        //printf("\nHi,from the child, n is %d:\n",n);//we are in the CHILD process
    
    }
    else {
        n=6;
        //printf("\nHi,from the main, n is %d:\n",n);//We are in the PARENT process
    }

    //{2}
    if(pid !=0)//If we are in the parant process, wait for the child process to
    {
        //Sunronizira dvata procesa  taka se izpulnqva parent sled tova child
        wait(NULL);
    }

    int i;
    for (i=n; i<n+5;i++) {
        printf("%d ",i);
        //fflush(stdout);
    
    }
    printf("\n");

    //{}


    return 0;
}