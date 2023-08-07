#include <stdio.h>

void AdditionOperation(int f,int s)
{
    printf("Addition operation: %d + %d = %d\n", f,s, f+s);
}

void SubtractionOperation(int f,int s)
{
    printf("Subtraction operation: %d - %d = %d\n",f,s,f-s);
}

void MultiplicationOperation(int f, int s)
{ 
    printf("Multiplication operation: %d * %d = %d\n", f,s,f * s); 
}

void DivisionOperation(int f,int s)
{
    printf("Division operation: %d / %d = %d\n",f,s,f/s);
}

void ModulusOperation(int f,int s)
{
    printf("Modulus operation: %d %% %d = %d\n",f,s,f%s);
}

int main(int argc, char *argv[]) 
{
    //Input
    int firstNumber;
    printf("Set first number: ");
    scanf("%d", &firstNumber);

    int secondNumber;
    printf("Set second number: ");
    scanf("%d", &secondNumber);

    //Addition operation
    AdditionOperation(firstNumber, secondNumber);

    //Subtraction operation
    SubtractionOperation(firstNumber, secondNumber);

    //Multiplication operation
    MultiplicationOperation(firstNumber,secondNumber);

    //Division operation
    DivisionOperation(firstNumber, secondNumber);

    //Modulus operation
    ModulusOperation(firstNumber,secondNumber);

    return 0;
}