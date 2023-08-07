#include "stdio.h"

int myVar = 5; // Declared outside the function

void myFunction()
{
    printf("Current myVar is: %d\n",myVar);

    // Chage the value;
    myVar = 7; 

    
}

int main(int argc, char *argv[]) 
{
    //Use my function.
    myFunction();

    //Print number after change.()
    printf("Number after change: %d \n",myVar);

    return 0;
}