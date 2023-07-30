#include <stdio.h>

//Start Selection
void bubbleSort(int arr[], int size)
{
_Bool swapped=0;
//Optimization process with this counter.
int counter=0; 

//Nested loop
  do {
        swapped =0;
        for (int j=0;j<size-1-counter;j++)
        {
            if (arr[j]>arr[j+1])
            {
                //Swap currently min elelemnt at right position
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                swapped =1;
            }
        }
        counter++;
  
  }while (swapped);

}//End of Seleciton

//Day 5 - Lesson 04 Bubble Sort

int main(int argc, char *argv[]) 
{
    //Array
    int arr[5] = {5, 4, 3, 2, 1};

    //Size Array
    int size = sizeof(arr)/sizeof(arr[0]);

    //Print before
    printf("Array before selection sort.\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
   
    //Sort
    bubbleSort(arr, size);
    
    //Print after
    printf("\nArray after selection sort.\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

   