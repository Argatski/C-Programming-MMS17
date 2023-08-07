#include <stdio.h>

//Start Selection
void selectionSort(int arr[], int size)
{
    //Nested for loop
  for (int i = 0; i < size-1; i++)
  {
    int min = i;

    for (int j = i+1; j<size; j++)
    {
        if (arr[j]<arr[min])
        {
            min = j;
        }

        //Swap element
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
  }
}//End of Seleciton


//Day 5 - Lesson 04 Selection Sort

int main(int argc, char *argv[]) 
{
    //Array
    int arr[5] = {5, 4, 3, 2, 1};

    //Size Array
    int size = sizeof(arr)/sizeof(arr[0]);

    //Print befor
    printf("Array before selection sort.\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
   
    //Sort
    selectionSort(arr, size);
    
    //Print after
    printf("\nArray after selection sort.\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
   return 0;
}

