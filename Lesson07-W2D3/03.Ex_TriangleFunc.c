#include <math.h>
#include <stdio.h>

int triangle(double a, double b, double c, double *P,double *A)
{
    if (a<=0||b<=0||c<=0|| a+b<=c|| b+c<=a|| c+a<=b)
    {
        return -1;
    }
    
    *P=a+b+c;//Perimeter
    double HP = *P/2; //half perimeter
    *A=sqrt(HP*(HP-a)*(HP-b)*(HP-c));//Area
    return 0;
}



int main() 
{
    double a,b,c,A,P;

   while (scanf("%lf %lf %lf", &a, &b, &c)==3) 
   {
    if (triangle(a,  b,  c,&P,&A)==-1) 
    {
        printf("Invalid input\n");
        printf("Set valid input:\n");
    }
    else {
        printf("Perimeter:%.2lf Area:%.2lf\n", P, A);
        
        return 0;
    }
   }
   return 0;
}