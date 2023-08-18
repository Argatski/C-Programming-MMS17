#include <stdio.h>
#include <stdlib.h>


//Read number.txt file and calculate sum of numbers 
//Use this syntax to work with program ./04.Ex_SumNumberOfFile number.txt
int main(int argc, char* argv[])
{
    //Check if arguments is biger than 2 elements
    if(argc != 2)
    {
        perror("Invalid arguments");
        exit(-1);

    }

    //Create file with name f1 and open to read;
    FILE *f1 = fopen(argv[1], "r");

    //If file is NULL
    if (!f1) {
        perror("Fopen error");
        exit(-1);
    }

    size_t curNum;
    size_t sum = 0;

    while (fscanf(f1,"%lu",&curNum) == 1) {
        sum += curNum;
    }

    fprintf(stdout,"Sum: %lu\n",sum);

    return 0;
}