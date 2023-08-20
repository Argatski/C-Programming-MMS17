#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    if(pid==-1)
    {
        perror("Fork error");
        exit(-1);
    }
    else if (pid == 0) {
        sleep(1);
        printf("Child process\n");
        printf("Child process\n");
        printf("Child process\n");
        printf("Child process\n");
        printf("Child process\n");
        return 1;
    }
    else {
    sleep(5);
    int wstatus;
    pid_t child_pid = wait(&wstatus);
    printf("Child pid %d\n", child_pid);
    printf("Wstatus value: %d\n", wstatus);
    if (WIFEXITED(wstatus))
    {
        printf("Child exited normally\n");
        printf("Child return code: %d\n", WIFEXITED(wstatus));
    }
    else {
    printf("Child did not exit normally\n");
    }
        printf("Parent process\n");
        printf("Parent process\n");
        printf("Parent process\n");
        printf("Parent process\n");
        printf("Parent process\n");
        printf("Parent process\n");
    }
    return 0;
}