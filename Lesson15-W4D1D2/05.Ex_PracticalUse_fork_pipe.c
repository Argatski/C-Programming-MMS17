#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
да напишем програма в която
1. definirame ednomeren masiw ot celi `isla;
2.Suzdavame dwa procesa
3.CHILD procesa `ete elemenite ot 0 do sredata: i gi sumira
4.Parent procesa `ete elementite ot sredata do kraq i gi sumira
5.CHILD procesa zapisva kanal svoq  resultata i da 6.Parent - procesa prochita
po kanal rezultata na CHILD - procesa sumira dwete stojnosti i gi prazprechatva
na sumata;
*/

int main() {
  //{1}
  int myArray[] = {7, 18, 9, 11, 15, 8, 22, 26, 29, 36};

  int start, end;
  int arrSize = sizeof(myArray) / sizeof(myArray[0]);

  // Create pipe
  int fd[2];

  if (pipe(fd) == -1) {
    printf("An error occurred opening pipe!\n");
    return 1;
  }

  int pid = fork(); // create a new process

  if (pid == -1) {
    printf("An error occirred with fork !\n");
    return 2;
  }

  // Logic to divide the array:
  if (pid == 0) {
    start = 0;
    end = arrSize / 2;


  } else {
    start = arrSize / 2;
    end = arrSize;


  }
int sum=0;
int i;//for-cycle variables
for (i=start; i<end; i++) 
{
  sum+=myArray[i];
}

if(pid==0)
{
printf("Calculated CHILD-sum %d\n",sum);
}
else
{
printf("Calculated PARNET-sum %d\n",sum);
}


//Chechk processes
if(pid==0)
{//CHILD
  //
  close(fd[0]);//close read

  if(write(fd[1], &sum, sizeof(int)==-1))
  {
    return 1;
  }

  close(fd[1]);//close write
}
else {//Parent
  int sumFormChild;
  close(fd[1]);
  
  if(read(fd[0],&sumFormChild,sizeof(int)))
  {
    return 2;
  };

  close(fd[0]);

  printf("Read from child: %d\n",sumFormChild);

  int totalSum=sum+totalSum;

  printf("Total sum: %d\n",totalSum);
}





  // // check the process
  // if (pid == 0) {
  //   // we are in CHILD process
  //   close(fd[0]); //[0] closed for reading
  //   int A;
  //   printf("Please input the value: ");

  //   scanf("%d", &A);

  //   if (write(fd[1], &A, sizeof(A)) == -1) {
  //     printf("An error occurred with writing to the pipe !");
  //     return 3; // error writing into pipe
  //   };
  //   close(fd[1]); //[1] closed for writing

  // } else {
  //   // we are in the parent proc
  //   close(fd[1]); //[1] closed for writing

  //   int B;

  //   read(fd[0], &B, sizeof(B));

  //   if (read(fd[0], &B, sizeof(B) == -1)) {
  //     printf("An error occurred with reading from the pipe !\n");
  //     return 4;
  //   }

  //   printf("Read form Child process: %d\n", B);

  //   B *= 10;
  //   printf("Resul%d\n", B);
  //   close(fd[0]);

  //   return 0;
  // }


  return 0;
}