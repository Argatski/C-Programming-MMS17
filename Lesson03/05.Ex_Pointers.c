#include<stdio.h>

//Day 4 Work woth pointer
//Swap method
void SwapPointer(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{
    int a=5,b=10;

    int*ptrA = &a; //Set value address.
    
    int*ptrB = &b; //Set value address.   

    printf("Before swapping: a = %d and b = %d\n",*ptrA,*ptrB);

    SwapPointer(ptrA, ptrB);

    printf("After swapping: a = %d, b = %d\n", *ptrA, *ptrB);
}