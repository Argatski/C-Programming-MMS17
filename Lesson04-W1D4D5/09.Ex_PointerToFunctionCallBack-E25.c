#include <stdio.h>

int multiply(int a);

void processing(int data,int(*callback)());

int main(int argc, char *argv[]) 
{
    processing(17,multiply);

    return  0;
}

int multiply(int a)
{
    return a*2;    
}

void processing(int data,int(*callback)(int))
{
    int result = callback(data);

    printf("Result: %d\n",result);
}