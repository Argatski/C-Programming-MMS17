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
    //07777 atrubut za dostupp i kontrol na failla

    if( mkfifo("myFIFO",0777)==-1)
    {
        printf("Couldn`t create FIFO-file: \n");
                return 1;
    };

    printf("Opening.....");

    int fd = open("myFIFO", O_WRONLY);

    printf("Opened! \n");

    int myVal = 97;

    if(write(fd,&myVal,sizeof(myVal))==-1){
        printf("Problem with writing!\n");
        return 2;
    };

    printf("Wirtten \n");

    close(fd);
    printf("Closed! \n");

    return 0;
}