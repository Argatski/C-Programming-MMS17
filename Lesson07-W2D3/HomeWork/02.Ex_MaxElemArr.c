#include <stddef.h>
#include <stdio.h>


void*findMax(void* arr, size_t n, size_t elem, int (*cmp)(const void*, const void*))
{
    void *max=arr;
    for(size_t i=0;i<n;i++)
    {
        if(cmp(max,arr+i*elem)<0)
        {
            max=arr+i*elem;
        }
    }
    return max;
}

int cmpInt(const void *a, const void *b)
{
    return *(int*)a>*(int*)b?1:-1;

}
int main(int argc, char *argv[]) 
{
    int arr[] = {1,2,-1,3,5,11,12,13,2,100,22};

    size_t len = sizeof(arr)/sizeof(arr[0]);

    int* max = findMax(arr,len,sizeof(int),&cmpInt);

    printf("%d\n",*max); // pint 100

    return 0;
}