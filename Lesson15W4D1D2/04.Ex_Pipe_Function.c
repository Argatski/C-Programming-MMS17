#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
да напишем програма в която да се изполваме дава процеса и да използваме пипр()
функция за да осъшестви комуникация.
*/

int main() {
  //{1}
  // Create pipe
  int fd[2];

  pipe(fd);

  if (pipe(fd) == -1) {
    printf("An error occurred opening pipe!\n");
    return 1;
  }

  int pid = fork(); // create a new process

  if (pid == -1) {
    printf("An error occirred with fork !\n");
    return 2;
  }
  // else {
  //  printf("An error occirred \n!");
  //     return 1;
  // }

  // check the process
  if (pid == 0) {
    // we are in CHILD process
    close(fd[0]); //[0] closed for reading
    int A;
    printf("Please input the value: ");

    scanf("%d", &A);

    if (write(fd[1], &A, sizeof(A)) == -1) {
      printf("An error occurred with writing to the pipe !");
      return 3; // error writing into pipe
    };
    close(fd[1]); //[1] closed for writing

  } else {
    // we are in the parent proc
    close(fd[1]); //[1] closed for writing

    int B;

    read(fd[0], &B, sizeof(B));

    if (read(fd[0], &B, sizeof(B) == -1)) {
      printf("An error occurred with reading from the pipe !\n");
      return 4;
    }

    printf("Read form Child process: %d\n",B);

    B*=10;
    printf("Resul%d\n",B);
    close(fd[0]);

    return 0;
  }
}