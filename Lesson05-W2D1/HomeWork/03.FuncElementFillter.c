#include <stddef.h>
#include <stdio.h>

void filterAndMap(const int arr[],size_t n,int(*fillter_f)(int),int (*map_f)(int),int dest[],size_t* dest_cnt)
{
    size_t count = 0; 
    
    for (size_t i=0; i<n; i++)
    {
        if (fillter_f(arr[i]))
        {
            int mappedValue = map_f(arr[i]);
            if (dest!=NULL) {
                dest[count] = mappedValue;
            }
            count++;
        }
    }
    if (dest_cnt!=NULL) {
        *dest_cnt = count;
    }
}

int isPositive(int a) { return a > 0 ? 1 : 0; }

int addOne(int a) 
{ 
    return a+1;
}

//Print array
void printArray(int arr[], int size)
{

    for (size_t i=0; i<size; i++)
    {   
        printf("%d", arr[i]);
        if (i<size-1) 
        {
            printf(", ");
        }
    }
}

int main(int argc, char *argv[]) 
{
 //Input array   
 int arr[8] = {1,2,3,4,-1,-2,11,-100};

 //Output array   
 int dest[10];

 //size_t
 size_t new_size;

 //Filter and Map   
 filterAndMap(arr, 8, isPositive, addOne, dest, &new_size);

 printf("new_size = %zu\n", new_size);
 printf("dest ={");

 // Print new array (dest)
 printArray(dest, new_size);
 printf("};\n");
}