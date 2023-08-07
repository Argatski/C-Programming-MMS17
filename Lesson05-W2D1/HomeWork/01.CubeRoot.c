#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double abs_n(double x) {
    return x < 0 ? -x : x;
}

//Cube root use bitwise operator
double cube_root(double x) {
    if (x == 0.0)
        return 0.0;

    double precision = 1e-6; 

    double guess = x; 
    //Use method  of Newtonian
    while (abs_n(guess * guess * guess - x) > precision) {
        
        guess = (2 * guess + x / (guess * guess)) / 3;
    }

    return guess;
}

int main() {
    double number = 0.0;
    printf("Read number from console:");
    scanf("%lf", &number);

    double result = cube_root(number);
    printf("Cube root of number %.2f is : %.4f\n", number, result);

    return 0;
}

