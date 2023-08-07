#include <stdio.h>

//Day 3
int main(int argc, char *argv[]) 
{
    unsigned short A;
    unsigned short B;   

    //Read first number "A": (0 to 100)
    printf("Set number A:");

    scanf("%hu", &A);

    //Read second number "B": (0 to 100)
    printf("Set number B:");

    scanf("%hu", &B);
    
    //Bitwise AND
    printf("A & B: %hd\n" ,A&B);

    //Bitwise OR
    printf("A | B: %hd\n",A|B);

    //Bitwise xOR
    printf("A ^ B: %u\n",A^B);

    //Bitwise NOT!
    printf("~A: %d\n", ~A);

    //Bitwise NOT!
    printf("~B: %d\n",~B);

    //Bitwise SHIFT LEFT
    printf("A<<1: %d\n",A<<1);

    //Bitwise SHIFT LEFT
    printf("B<<1: %d\n",B<<1);

    //Bitwise SHIFT RIGHT
    printf("A>>1: %d\n", A>>1);

    //Bitwise SHIFT RIGHT
    printf("B>>1: %d\n",B>>1);

    return 0;

}