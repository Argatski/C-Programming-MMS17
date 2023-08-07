#include<stdio.h>

typedef struct A
    {
        char a; // 1byte
        //3bytes padding
        int b;//4bytes 

    }A;

    typedef struct B
    {
        int a; // 4byte
        char b; // 1byte
        //3bytes padding

    } B;

    typedef struct C
    {
        double a; //8bytes
        int b; //4bytes
        //4bytes padding
    } C;
    
    typedef struct D
    {
        char name[6];// 6 bytes
        //2bytes padding
        double height; //8bytes
        short age; //2bytes
        //6bytes padding
    } D;

    typedef struct E 
    {
        short a; //1byte
        //7bytes padding
        double b; //8bytes
    }E;

int main(int argc, char *argv[])
{
    printf("Size of A: %lu bytes\n", sizeof(A)); // size of A=8
    printf("Size of B: %lu bytes\n", sizeof(B)); // size of A=8
    printf("Size of C: %lu bytes\n", sizeof(C)); // size of A=16
    printf("Size of D: %lu bytes\n", sizeof(D)); // size of A=24
    printf("Size of E: %lu bytes\n", sizeof(E)); // size of A=16
    
    return 0;
    
}
