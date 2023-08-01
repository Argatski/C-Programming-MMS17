#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) 
{
    //Get count of argv
    int count =0;
    while (argv[++count]!=NULL);

    double sum=0;

    //Lenght of size argv
    
    for (int i = 1; i < count ; i++)
    {
        sum += atof(argv[i]);
    }

    //Print sum
    printf("Sum: %.2lf\n", sum);


    return 0;
}