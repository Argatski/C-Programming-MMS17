#include <stdio.h>
#include <stdlib.h>

int compare_ints_dec(const void* p1,const void* p2)
{   
    return *(const int*)p2 - *(const int*)p1;//Addres a and address b
}

int compare_ints_inc(const void* p1, const void* p2)
{
    return *(const int*)p1 - *(const int*)p2;
}


int main(int argc, char *argv[]) 
{   
    printf("%p\n",argv);
    printf("%p\n",argv[0]);
    printf("%c\n",argv[0][2]);
    
    int arr[]={4,5,-10,15,31,22,45,1};

    int n=sizeof(arr)/sizeof(arr[0]);
    //Qsort array assending order
    qsort(arr, n, sizeof(int), compare_ints_inc);

    //Print array
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    //Sort arrays descending order
    qsort(arr, n, sizeof(arr[0]), compare_ints_dec);

    //Print array
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}