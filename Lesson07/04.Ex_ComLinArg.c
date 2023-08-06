#include <stdio.h>


int main(int argc, char *argv[]) 
{
    //Execute the command
    // ./cla These are the command line arguments!
    printf("%d\n", argc);
    printf("%s\n", argv[0]);// ./cla
    printf("%s\n", argv[1]);// These
    printf("%s\n", argv[2]);// are
    printf("%s\n", argv[3]);// the
    printf("%s\n", argv[4]);// command 
    printf("%s\n", argv[5]);// line
    printf("%s\n", argv[6]);// arguments!

    return 0;
}