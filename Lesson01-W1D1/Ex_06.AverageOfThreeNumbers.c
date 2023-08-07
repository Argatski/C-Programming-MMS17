#include<stdio.h>

//Method to calculate average.
double AverageNumbers(double num1,double num2,double num3)
{
    double result = (num1+num2+num3)/3;
    return result ;
}

//Start program
int main(int argc, char *argv[]) 
{
    double num1,num2,num3;

    //Input first number;
    printf("Enter the first number: ");
    scanf("%lf",&num1);

    //Input second number;
    printf("Enter the second number: ");
    scanf("%lf",&num2);

    //Input third number;
    printf("Enter the third number: ");
    scanf("%lf",&num3);
    
    //Calculate averageNumers
    double result =  AverageNumbers(num1,num2,num3);

    //Print the result
    printf("The average of the three numbers is %.2f\n",result);

    return 0;
}
//End program

