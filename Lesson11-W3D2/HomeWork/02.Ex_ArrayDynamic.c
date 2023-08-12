#include <stdio.h>
#include <stdlib.h>
//Initialize the array
void initArray(double *arr, int currentPosition,int size,double min,double max)
{
    for(int i = currentPosition; i < size;i++)
    {
        arr[i] = ((double)rand()/RAND_MAX) * (max-min)+min;
    }
}

//Print the array
void printArray(double *arr,int size)
{
    printf("Array:\n");
    for(int i = 0; i < size;i++)
    {
        printf("%f ",arr[i]);
    }
    printf("\n");
}


int main()
{
    size_t n,m,p;

    //Read 'n'
    printf("Input argument 'n': ");
    scanf("%zu",&n);
    int curPosition = 0;

    double *arr = malloc(n*sizeof(double));
    
    //Initialize the array
    initArray(arr,curPosition, n, 0.1, 1.0);
    //Print the array
    printArray(arr, n);

    //Read 'm'
    printf("Input argument 'm': ");
    scanf("%zu",&m);

    //Realocate the array
    arr= realloc(arr, (n+m)*sizeof(arr));
    curPosition=n;

    //Initialize the array
    initArray(arr, curPosition,curPosition+m, 1.0, 2.0);

    //Print the array
    printArray(arr, curPosition+m);


    //Read the "p"
    printf("Input argument 'p': ");
    scanf("%zu",&p);

    //Realocate the array
    arr= realloc(arr, (n+m+p)*sizeof(arr));
    curPosition+=m;

    initArray(arr, curPosition, curPosition+p, 2.0, 3.0);

    //Print the array
    printArray(arr, curPosition+p);

    free(arr);

    return 0;
}