#include <stdio.h>
#define PI 3.14

int cylinder(double r, double h, double* V, double* S)
{
    if (r<=0 || h<=0) {
        return -1;
    }
    *V = r*r*PI*h;
    *S = 2*r*PI*h;
    return 0;
}

int main(int argc, char** argv)
{
    double r, h,V,S;

    scanf("%lf %lf", &r, &h);

    while (r!=0 && h!=0) {
        if (cylinder(r, h, &V, &S)==-1) {
            printf("Invalid data\n");
        }
        else {
         printf("Area: %.2lf  Volume: %.2lf",V,S);
        }
        scanf("%lf %lf", &r, &h);
    
    }
 return 0;
}