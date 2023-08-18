///Procesi izpolzvane na fifo files za komunikaciq mejdu dva fiala


#include <asm-generic/errno-base.h>
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

/* sled 06.Ex
main 01 - writes 10 integers in myFIFO files;
*/

int main(int argc,char* argv[])
{
  //{1}: Creating myFIFO file
  if (mkfifo("myFIFO", 0777) == -1) {
    if (errno != EEXIST) {
      printf("Couldn`t create FIFO-file: \n");
      return 1;
    }
  };

    //{2}:Create an array and fill with random numbers

    int myArray[10];

    int i;

    for (i=0; i<10; i++) {
        myArray[i]=rand()%100;
        printf("Generated %d \n",myArray[i]);
    }

    //{3}:OPEN myFIFO and write into it
    int fd=open("myFIFO",O_WRONLY);


    if (fd==-1)
    {
        printf("Failed to open\n");
        return 2;//Code 1 for this case
    }

    if(write(fd, myArray, sizeof(myArray))==-1)
    {
        printf("Failed to write.\n");
        return 3;
    }

    close(fd);

    return 0;
}