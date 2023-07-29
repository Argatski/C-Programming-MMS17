#include<stdio.h>

//Day 4
int main(int argc, char *argv[]) 
{
    //Input grade
    char grade;

    printf("Enter your grade: ");
    scanf("%c", &grade);

    switch (grade) 
    {
        case 'A':
            printf("Excellent:\n");
            printf("Excellent:\n");
        break;
        case 'B':
        case 'C':
            printf("Well done:\n");
        break;
        case 'D':
            printf("You passed:\n");
        break;

        case 'F':
            printf("Better try again:\n");
        break;
        default:
        printf("Invalid grade:");
    }
}