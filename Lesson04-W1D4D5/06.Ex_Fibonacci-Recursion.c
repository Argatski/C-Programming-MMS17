#include <stdio.h>

long fibRec(int size);
long fibLoop(int size);

//Day-5 Fibonacci Recursion.
//Start program
int main(int argc, char *argv[])
{
    //Read number.
    int n;
    printf("Enter a number fibonacci: ");
    scanf("%d", &n);

    //Result Recursion
    long result = fibRec(n);
    printf("The value to (%d) element is %ld\n", n, result);

    //Result Loop
    result = fibLoop(n);
    printf("The value to (%d) element is %ld\n", n, result);

    return 0;
}//End program

//Fibonacci RECURSION
long fibRec(int size)
{
    if (size ==0)//base case
    {
        return 0;
    }
    else if (size ==1)//base case
    {
        return 1;
    }
    else
    {
        return fibRec(size-1)+fibRec(size-2);
    }

}//End method fibonacci

//Fibonacci LOOP
long fibLoop(int size)
{
    long a = 0;
    long b = 1;
    if (size == 0) 
    {
        return 0;
    }
    for (int i = 1; i < size; i++)
    {
        long c = a + b;
        a = b;
        b = c;
    }
    return b;
}//End method fibonacci