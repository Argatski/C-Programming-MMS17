#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/stat.h>

#include <sys/errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    //{1}: Create FD and PIPE
    int fd[2];
    //[0] - read
    //[1] - write

    if(pipe(fd)==-1){
    return 1;    //return 1 for erro
    }


    //{2}: Create a new process (fork)
    int pid = fork();
    if(pid==-1)
    {
        return 2;
    }

    //{3}: Swiching between proceses and send string
    //CHILD process send string:
    if(pid==0)
    {
        close(fd[0]); //close read

        char myString[255];

        printf("Please input string:\n");
        fgets(myString,255,stdin);
        myString[strlen(myString)-1]='\0';//remove the termination system character
        //strlen -1 gives the index of last char in array

        int size = strlen(myString);

        if(write(fd[1], &myString, size)<0)
        {
            return 3;
        }


        printf("Size of string: %d\n",size);
        printf("String send to PARENT process : %s\n",myString);
        close(fd[1]);
    }
    //PARENT receive string and printing: 
    else
    {
        close(fd[1]);//close write
        
        char myString[255];

        if(read(fd[0], &myString, sizeof(myString))<0)
        {
            return 4;//return 4 for error
        }

        printf("Received from CHILD process: %s\n",myString);
        close(fd[0]);//close read
        
        wait(NULL);

    }

    return 0;
}