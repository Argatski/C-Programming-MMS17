#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define K 2

int pipe_fd[2][K];
int main(int argc,char **argv)
{
   // ./filesSum file1 file2 file3 file4 file5

    if (argc<2) {
        perror("Invalid arguments\n");
        exit(-1);
    }


    long long sum = 0;

    pipe(pipe_fd);

    for (size_t i=1;i<argc; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("Fork failed\n");
            return 1;
        }
        else if (pid == 0) //Child process
        {
            char *name = argv[i];
            FILE *f = fopen(argv[i], "r");

            if (!f) {
                perror(name);
                exit(-1);
            }

            uint64_t n;
            long long sum = 0;

            while ((fread(&n, sizeof(uint64_t), 1, f))==1) {
                
                while (n>0) {
                    if (write(pipe_fd[n][1], &i, sizeof(i)) != sizeof(n)) {
                        perror("Write error");
                    }
                    sum += n%10;
                    n/=10;
                }
                
            }

            printf("%s - %llu\n", name, sum);

            fclose(f);

            return 0;    
        
        }
        

    }

    //Parent process
    for(int i = 1; i <argc; i++)
    {
        int wstatus;
        wait(&wstatus);
        if (!WIFEXITED(wstatus)) {
            perror("Child dod not exit normally\n");
        }
    }

    unsigned long long sum_total = 0;
    unsigned long long cur_partial_sum;

    for(int i = 0; i < argc; i++) {
        read(pipe_fd[i][0], &cur_partial_sum, sizeof(cur_partial_sum));
        sum_total += cur_partial_sum;
    }
    printf("Total sum of digits - %llu\n", sum_total);

}