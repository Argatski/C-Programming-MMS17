#include <stdio.h>

//Start programa
int main(int argc, char *argv[]) 
{
    int num;

    //Read of console
    printf("Enter a number: ");

    scanf("%d",&num);

    int currentNumber;

    //Binary
    int base = 2;

    while (num>0) 
    {
        currentNumber=num%base;

        //Print result
        printf("%d\n",currentNumber);
        
        num/=base;
    }   

    return 0;
    //After end of program our result is mirror.
}