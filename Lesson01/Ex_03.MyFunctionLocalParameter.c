#include <stdio.h>

//Funcuton
void myFunction()
{
    int myVar = 5;//Declared inside the funciton
    printf("myVar inside myFunction(): %d\n", myVar);
}


//Start point
int  main (void)
{
    myFunction();

    //printf("myVar outside myFunction(): %d\n'",myVar"); This line would cause an error

    return 0; 

}
//End point