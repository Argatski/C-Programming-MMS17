#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>


int main(int argc, char *argv[]) 
{
    //
    unsigned int a,i;

    printf("%u", a >> i);

    printf("%u", a & ((1 << i) - 1));

    printf("\n");
    return 0;
}