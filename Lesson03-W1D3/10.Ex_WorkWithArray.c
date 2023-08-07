#include <math.h>
#include <stdint.h>
#include <stdio.h>


//Day-4 Work with array.Int min value.Int max value.Avarage.
int main(int argc, char *argv[]) 
{
    //Input array.
    int arr[10]={15,28,33,45,90,95,53,60,36,57};
    
    int max_value =  INT16_MIN;
    int min_value =  INT16_MAX;
    double avg_value = -1;

    //Lenght array
    int arrLenght = sizeof(arr)/sizeof(arr[0]);

    //Search in array use for loop.
    for (int i=0; i<arrLenght;i++ )
    {   
        //If value is min.
        if (arr[i]<min_value)
        {
            min_value=arr[i];            
        }
        //If value is max.
        if (arr[i]>max_value) 
        {
            max_value=arr[i];
        }

        //Result sum of all elements.
        avg_value += arr[i];

    }

    //Avarage result
    avg_value /= arrLenght;

    //Print result.
    printf("Max: %d\n",max_value);
    printf("Min: %d\n",min_value);
    printf("Avarage: %.2f\n",avg_value);
}