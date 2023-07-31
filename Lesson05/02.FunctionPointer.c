#include <stdio.h>

//Day 6 Pointer Func

void printHeight(int a)
{
    printf("My height is: %d\n",a);
}

void printMsg(void(*f)(int))
{   
    printf("Hello: ");
    f(10);
}

void printAge(int a)
{
    printf("My age is: %d\n",a);
}

int main(int argc, char *argv[]) 
{
    void (*f)(int) = printHeight; 
    printf("Address: %p\n",f);
    printf("Size of: %luBits\n",sizeof((0)));

    f(20);// My height is: 20

    printMsg(printHeight);//Set f(10).Print Hello: My height is 10

    printMsg(printAge);//Set f(10).Print Hello: My age is 10

    return 0;
}