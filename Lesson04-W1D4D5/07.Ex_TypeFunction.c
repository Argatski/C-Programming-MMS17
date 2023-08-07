#include <math.h>
#include <stdio.h>

void printMyName();
void multipl_a_b(int a, int b);
int div_a_b(int a, int b);

//Day-5 Type function.

int main(int argc, char *argv[]) 
{
    //Function without parameters not return result.
    printMyName();

    //Function with parameters not return result.
    multipl_a_b(7, 12);


    //Function with parameters and return result.
    int result = div_a_b(30, 2);
    printf("Result: %d\n",result);
}

//Function without parameters not return result.
void printMyName() 
{
    printf("Kris\n");
}

//Function with parameters not return result.
void multipl_a_b(int a, int b)
{
    int result = a*b;

    printf("Number is: %d\n", result);
}

//Function with parameters and return result.
int div_a_b(int a, int b)
{
    return a/b;
}