#include <stdio.h>

//Start program
int main(int argc, char *argv[]) 
{
    double fahrenheit,celsius;

    //Input temperature.
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf",&fahrenheit);

    //Convert temperature.
    celsius = (fahrenheit - 32) * 5 / 9;

    //Output temperature.
    printf("Temperature in Celsius: %.2f\n",celsius);

    return 0;
}
//End program