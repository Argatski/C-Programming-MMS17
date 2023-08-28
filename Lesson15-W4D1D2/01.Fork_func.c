#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Important for Linuks


int main    (int argc,char*argv[])
{
    //{1}::.................................................
    // //fork();//Create a new process -so we have to times "Hello"
    // printf("Hello, world\n");

    // // //{2}
    // int pid = fork();
    // sleep(10);

    // printf
    // ("Hello,world from id:%d\n",pid);

    // //{3}
    // if  (pid==0)
    // {
    //     printf("Hello world child procces \n");
    // }
    // else {
    //    printf("Hello world main process \n");
    // }

    // //{4}
    // fork();
    // fork();
    // fork();
    // fork();
    // //Four forks=> of the power of four is 16
    // //If we call fork() gain=>2 of the power of three is 8


    //{5}
    //how to create only 3 processes:
    //the child process has pid 0, so we
    int pid1 =fork();
    printf("Hello, world after first fork() pid1 %d \n", pid1);


    if (pid1!=0) {
    int pid2= fork();
    printf("Hello, world after second fork() pid2 %d \n", pid2);

    }
    else {
    printf("Hello, world from pid1 %d \n", pid1);
    
    }

    

    return 0;

}