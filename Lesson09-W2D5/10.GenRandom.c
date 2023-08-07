#include <time.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int* genRandom(size_t element_c)
{
    int minValue = -100;
    int maxValue = 100;

    int* arr =  (int*)malloc(element_c *sizeof(int));

    srand(time(NULL));

    for (size_t i = 0; i < element_c; i++)
    {
        arr[i] = - minValue + rand() % (maxValue - minValue + 1) + minValue;
    }

    //      [-100, 99]
        // rand()%100  === 0-99
        // rand()%200  === 0-199
        // rand()%100 - 100 === -100-0
        // *(arr + i) = ...

    return arr;
}

int main(int argc, char *argv[]) 
{
    int n;
    scanf("%d",&n);
    int *arr = genRandom(n);

    for (size_t i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    
    }
    printf("\n");

    free(arr);
    return 0;
}
