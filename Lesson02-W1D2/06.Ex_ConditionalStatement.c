#include <stdio.h>


//Day 3
//Start program
int main(int argc, char *argv[]) 
{
    printf("How old are you?\n");

    //Input age
    int age;
    //Read from console
    scanf("%d", &age);

    //Input weight
    float weight;

    printf("How much do you weigh?\n");

    //Read from console
    scanf("%f", &weight);

    //Check age
    if(age<18) // if age<18 and weight<100
    {
        printf("You are eligible to donate blood!\n");
        printf("You are old enough to vote!\n");
    }
    else if(weight<100) //if age>=18 and weight<100
    {
        printf("You are eligible to donate blood!\n");
        printf("You are eligible to donate vote!\n");
    } 
    else //if age>=18 and weight>=100
    {
        printf("You are not eligible to donate blood!\n");
        printf("You are eligible to donate vote\n!");
    }

    return 0;
}

//End of main