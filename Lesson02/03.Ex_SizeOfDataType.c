#include <stdio.h>

//Start Program
int main(int argc, char *argv[]) 
{
     //Character type.
    char c ='c';
    printf("Size of char: %lu\n",sizeof(c));

    //Whole numbers
    short s = 128;
    printf("Size of whole number: %lu\n",sizeof(s));

    int i = 100;
    printf("Size of whole number: %lu\n",sizeof(i));
    
    long l = 1000;
    printf("Size of whole number: %lu\n",sizeof(l));

    // Decimal numbers
    float d = 3.14;
    printf("Size decimal number: %lu\n", sizeof(d));

    double dec = 3.14159265359;
    printf("Size decimal number: %lu\n", sizeof(dec));

    _Bool myBool = 1;
    printf("Size boolean: %lu\n", sizeof(myBool));

    return 0;
}