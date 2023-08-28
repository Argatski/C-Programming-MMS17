#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char* argv[])
{
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    int pid;
    if((pid = fork()) == 0) {
        // Child process
        printf("%s %s %s \n", argv[0], argv[1], argv[2]);
        execvp(argv[1], argv+1);
        perror("EXEC FAILED");
        exit(-1);
    } else if(pid > 0) {
        int child_return_status;
        waitpid(pid, &child_return_status, 0);
        if(child_return_status) {
            perror("Child did not finish successfully!\n");
            exit(-1);
        }
        gettimeofday(&stop, NULL);
        printf("\t\t\tTook %f s\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec)/1000000.);
        exit(0);

    } else if(pid == -1) {
        perror("Fork failed");
        exit(-1);
    }
    return 0;
}