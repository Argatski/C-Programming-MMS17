#include <stdio.h>

//Struct Point have two points x,y  and typedef "P".
typedef struct Point
{
    double x;
    double y;
    int d;
} P;

//Second tupe to define struct
typedef struct 
{
    int houseNumber;
    char streetName[30];
    char *residentName[10];
    P cordinates;


} ADR;

int main(int argc, char *argv[]) 
{
    //Set values in struct "a"
    P a;
    printf("%d\n",a.d);

    a.x =15.6;
    a.y = 12.3;
    printf("%f\n",a.x);
    printf("%f\n",a.y);

    //Set values in struct "b"
    P b ={30.2,45.1};
    printf("%lf\n",b.x);
    printf("%lf\n",b.y);

    //Set values in struct "c"
    P c = {.x = 30.2, .y = 45.1 };
    printf("%lf\n",c.x);
    printf("%lf\n",c.y);

    //Set values in struct "ADR"
    char  name1[] = "Ivan",
          name2[] = "Petrov";

    ADR adr1 = 
    {
        120,
        "Chernivruh",
        {name1,name2},
        {22.3,60.5}
    };

    ADR *p1 = &adr1;
    printf("Longitude: %lf\n",(*p1).cordinates.x);
    printf("Latitude: %lf\n",(*p1).cordinates.y);

    return 0;
}