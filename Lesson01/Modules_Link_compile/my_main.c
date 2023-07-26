#include <stdio.h>
#include "my_math.h"


int main(int argc, char *argv[]) 
{
    //Input the number
    double num;
    printf("Enter a number: \n");

    scanf("%lf", &num);


    //Calculate square
    double sq = square(num);
    
    //Calculate cube
    double cub = cube(num);

    //Print the result
    printf("The square of %.5f is %.5f\n", num, sq);
    printf("The cube of %.5f is %.5f\n", num, cub);

    return 0;
    
}