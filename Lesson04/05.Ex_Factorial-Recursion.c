#include <stdio.h>
//FACTORIAL BY RECURSION IMPLEMENTATION
long factorial(int n)// use long or long long
{
    if (n==0||n==1)
    {
        return 1;// Print base number.
    }
    else
    {
        return n*factorial(n-1);
    }
}

//FACTORIAL BY FOR IMPLEMENTATION

long fact_for(int size) // use long or long long
{
    long result=1;

    for (long i=1; i<=size; i++)
    {
        result*=i;
    };

    return result;   

}

int main(int argc, char *argv[]) 
{
    //Input number
    int n;
    printf("Enter a number(!): ");
    scanf("%d", &n);
    
    //Factorial by recursion
    printf("Factorial by RECURSION %d is %ld\n", n, factorial(n));

    //Factorial by for loop
    printf("Factorial by FOR %d is %ld\n",n,fact_for(n));

    return 0;

}
