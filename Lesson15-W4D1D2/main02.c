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
main 02 - Reads 10 integers from myFIFO files;
*/

int main(int argc,char* argv[])
{
  

    //{1}:Create an array and fill with random numbers

    int myArray[10];

    
    //{3}:OPEN myFIFO and write into it
    int fd=open("myFIFO",O_RDONLY);


    if (fd==-1)
    {
        printf("Failed to open\n");
        return 1;//Code 1 for this case
    }

    if(read(fd, myArray, sizeof(myArray))==-1)
    {
        printf("Failed to read.\n");
        return 2;
    }

    close(fd);

    //{3}
    int i;
    for (i=0; i<10; i++) {
        printf("Received from main01 %d \n",myArray[i]);
    }


    return 0;
}