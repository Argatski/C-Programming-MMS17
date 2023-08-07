#include <stdio.h>
#include <stdlib.h>
//Genere Type array
void *genArray(void(*init_elem)(void*),size_t elem_c,size_t eleme_size)
{
    void *arr = malloc(elem_c*eleme_size);

    //address of el. 0: array
    //address of el. 1 :(char*) arr + 1*elem_size
    //address of el. 2 :(char*) arr + 2*elem_size
    //address of el. 3 :(char*) arr + 3*elem_size
    //........................................
    for (size_t i=0; i<elem_c; i++) 
    {
      //printf("Calling function init_elem with address: %p\n", (char*)arr + i*eleme_size);  
      init_elem((char *)arr + i * eleme_size);
    }; 
    
    return arr;
}


void init_int_to_100(void* ptr)
{   int *int_ptr = (int*) ptr;
    *(int*)ptr = 100;//.................
}

void init_double_to_random(void* ptr)
{
    *((double*)ptr) = rand()/(double)RAND_MAX;
}


int main(int argc, char *argv[]) 
{
    int *arr = genArray(init_int_to_100, 33, sizeof(int));

    for (size_t i=0; i<33; i++) {
        printf("%d ", arr[i]);
    };

    printf("\n");

    double *arr2 = genArray(init_double_to_random, 10,sizeof(double));

    for (size_t i=0; i<10; i++) {
        printf("%f ", arr2[i]);
    };

    printf("\n");

    free(arr);

    return 0;
}