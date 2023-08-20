#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define k 10
#define ELEM_SIZE (sizeof(int))

int fd;
unsigned long long file_size_bytes;
unsigned long long child_bytes_count;

char *fname;

// One pipe for each child
int pipes_fd_list[k][2];

void child_fun(int child_index) {
  printf("STARTED CHILD with child_index = %d\n", child_index);

  unsigned long long sum = 0;

  // Open file in child
  fd = open(fname, O_RDONLY);
  if (fd < 0) {
    perror("Could not open file\n");
    exit(1);
  }
  //Sum numbers from file
  lseek(fd,child_index*child_bytes_count, SEEK_SET);
  for(int i =0; i < child_bytes_count/ELEM_SIZE; i+=1)
  {
    int curNum=0;
    read(fd,&curNum,sizeof(int));
    //printf("%d\n",curNum);
    sum += curNum;
  }
  close(fd);
  printf("ENDING CHILD with child_index: %d, SUM: %llu\n", child_index, sum);

  //Write result to pipe for current child
  write(pipes_fd_list[child_index][1], &sum, sizeof(sum));
}

//./program numbers.bin
int main(int argc, char **argv) 
{
    if(argc !=2)
    {
        perror("Invalid argc");
        exit(1);
    }
    //Open file
    fname = argv[1];
    fd=open(fname, O_RDONLY);

    if(fd<0)
    {
        perror("Could not open\n");
        exit(1);
    }

    //Ge file size
    file_size_bytes = lseek(fd, 0, SEEK_END);
    child_bytes_count = file_size_bytes /k;

    printf("File size is: %lld\n", file_size_bytes);
    printf("Child byte count is: %lld\n", child_bytes_count);

    //Close fole - open file later is each child
    close(fd);


    //Create K children
    int pid;
    for(int i=0;i<k;i++)
    {
        //Create pipe for each child
        //TODO: Check for errors
        pipe(pipes_fd_list[i]);

        //Only the parent calls fork
        pid = fork();
        if(pid < 0)
        {
            perror("Fork failed.");
        }
        else if(pid == 0)
        {
            //Child
            child_fun(i);
            return 0;
        }
    }

    //Parent
    //Wait for all K children to finish
    for(int i=0;i<k;i++)
    {
        wait(NULL);
    }

    //Sum partial sums stored in child pipes
    unsigned long long sum_total = 0;
    unsigned long long cur_partial_sum;

    for(int i = 0; i < k; i++)
    {
        read(pipes_fd_list[i][0], &cur_partial_sum,sizeof(cur_partial_sum));
        sum_total += cur_partial_sum;
    }
    printf("SUM: %lld\n",sum_total);
    return 0;
}