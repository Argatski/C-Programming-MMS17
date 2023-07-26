#include <stdio.h>
#define PI 3.14159 //Definition number PI.We can use in all place.

//Calculate Circumference.
double Calculate(double radius)
{
    double circumference = 2*PI * radius; 
    return circumference;
}

//Start point
int main(void) 
{
    double radius;

    //Read
    printf("Input the radius:");

    //Write
    scanf( "%lf", &radius);
    
    //Calculate
    double result =  Calculate(radius);

    //Print result
    printf("The circumference of a circle with radius %.2lf is %.2lf\n",radius,result);

    return 0;

}  
//End Point


