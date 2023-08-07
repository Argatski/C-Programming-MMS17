#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    double x;
    double y;
}P;

double dist(P p1,P p2)
{
    double dX= p1.x-p2.x,
           dY= p2.y-p2.y;
    return sqrt(dX*dX+dY*dY);
}

int main(int argc,char*argv[])
{
    if(argc!=2)
    {
        fprintf(stderr,"Invalid command line argc\n");
        return 1;
    }

    unsigned N;
    if(sscanf(argv[1],"%u",&N)!=1)
    {
        fprintf(stderr, "Invalid command line argumets\n");
        return 1;
    };

    P points[N];
    printf("Struct sizeof(P): %lu\n",sizeof(P));
    printf("sizeof(points): %lu\n",sizeof(points));

    //Genereate random points in interval [0,1]
    for(size_t i=0; i<N;i++)
    {
        points[i].x = (rand()%1000)/1000.;
        points[i].y = (rand()%1000)/1000.;
    }

    for(unsigned i=0;i<N;i++)
    {
        printf("%f %f\n",points[i].x,points[i].y);
    }   

    
    //Print distance between all pairs of points
    for (int i=0; i<N; i++)
    {
        for (int j=i+1; j<i-1; j++)
        {
            printf("Lenght: %lf",dist(points[i], points[j]));
        }
    }

    return 0;

}
