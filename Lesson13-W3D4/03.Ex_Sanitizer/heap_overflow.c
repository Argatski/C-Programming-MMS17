#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *s =  malloc(13);
    //No terminating symbol in string
    strcpy(s, "Hello, world!");
    s[12]='A';
    printf("%s\n", s);

    free(s);
    return 0;
}