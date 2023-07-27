#include <stdio.h>

//Day 3
int main(int argc, char *argv[]) 
{
    printf("Input number?\n");

    //Input number
    int number;

    //Read from console
    scanf("%d", &number);

    if(number%2==1)
    {
        printf("%d is odd number.\n", number);
    }
    else
    {
        printf("%d is even number.\n", number);
    }
    
    return 0;
}