#include <stdio.h>

//Start program
int main(int argc, char *argv[]) 
{
    //Input number
    int firstNumber;
    printf("Enter a number: ");
    scanf("%d", &firstNumber);

    int secondNumber;
    printf("Enter a number: ");
    scanf("%d", &secondNumber);


    float c;

    //Casting operation
    c = (float)firstNumber / secondNumber;

    //Output
    printf("The result of first number divided by second number is %.3f\n", c);
    return 0;
}//End program