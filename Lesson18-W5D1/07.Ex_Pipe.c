#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main(int argc, char **argv)
{
    int pipe_fd[2];
    //pipe_fd[0] is fd ,open to read;
    //pipe_fd[1] is fd ,open to write

    pipe(pipe_fd);

    int pid = fork();

    if (pid < 0) {
      perror("Could not fork\n");
      exit(-1);
    }
    else if (pid == 0) {
        //close(pipe_fd[0]); // child doesn`t read from pipe
        //Child
        int n = rand() % 1000;
        
        //Write to pipe
        printf("Will write %d to pipe\n", n);

        if (write(pipe_fd[1],&n, sizeof(n))!=sizeof(n)) {
            perror("Write error\n");
        }

        //close(pipe_fd[1]); // Child has finished writing to pipe
        return 0;
    }
    else
    {
        //close(pipe_fd[1]); //Parent does not write to pipe
        //Parent
        int res;
        if (read(pipe_fd[0],&res, sizeof(res))!=sizeof(res)) {
        perror("read error\n");
        }

        printf("Res from child %d\n", res);

    }
}