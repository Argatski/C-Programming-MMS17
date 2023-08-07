#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 30

/*
Създайте масив в динамичната памет от Point.
Задайте случайни начални стойности на точките.
Използвайте qsort за да сортирате масива:
- сортирайте масива в нарастващ ред по x
- сортирайте масива в намаляващ ред по y
sqrt(x*x + y*y)
След всяко сортиране да се изпечата съдържанието на arr.
*/

//Structure point
typedef struct Point
{
    double x;
    double y;
} Point;

//Set point "O"
const Point O ={0.,0.};

//Find distance between two points
double  dist(Point a, Point b)
{
    double x = a.x - b.x,
           y = a.y - b.y;
    return sqrt(x*x + y*y);
    
}
//Print array of points
void print_arr(Point arr[], size_t n) {
    for(size_t i = 0; i < n; i++) {
        printf("%lf %lf %lf\n", arr[i].x, arr[i].y, dist(arr[i], O));
    }
    printf("\n");
}


//Sort points by x and y
int compare_x_int(const void* p1, const void* p2)
{
    //Сортира по Х
    return (((Point*)p1)->x - ((Point*)p2)->x)*1000;
}

int compare_y_int(const void* p1, const void* p2)
{
    //Сортира по Y
    return (((Point*)p1)->y - ((Point*)p2)->y)*1000;
}


int compare_dist(const void* p1, const void* p2)
{
    //Сортира по дистанцията.Сортира масива по разтояние на точката(х,у) от точка (0,0);

    double dist1 = dist(*(Point *)p1, O),         dist2 = dist(*(Point *)p2, O);

    return (dist1-dist2)*1000;
}

int main(int argc, char *argv[]) 
{
    Point *arr =  malloc(N*sizeof(Point));
    //Generate points in range [-1.0000,1.0000]
    for (size_t i=0; i<N; i++) {
        (*(arr+i)).x =(-1000+rand()%2001)*1000.;
        // (*(arr+i)).y = (-1000 + rand()%2001)/1000.;
        // (arr+i)->y = (-1000 + rand()%2001)/1000.;
        arr[i].y = (-1000 + rand()%2001)/1000.;
    }

    qsort(arr, N, sizeof(Point), compare_x_int);
    print_arr(arr, N);

    qsort(arr, N, sizeof(Point), compare_y_int);
    print_arr(arr, N);


    qsort(arr, N, sizeof(Point), compare_dist);
    print_arr(arr, N);

    free(arr);
    return 0;
}
