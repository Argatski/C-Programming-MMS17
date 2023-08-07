#include <stdio.h>

int linearSearch(int l, int arr[], int key)
{
    //Search in our array.
    for (int i = 0; i < l; i++)
    {
    if (arr[i] == key)
    {
        return i;
    }
    }
    return -1;

}

//Day 5 - Lesson 04 LinSearch
int main(int argc, char *argv[]) 
{
    //Array
    int arr[] ={5,8,2,10,3};

    //Lenght of array
    int l = sizeof(arr) / sizeof(arr[0]);

    //Key
    int key;
    printf("Input key:");
    scanf("%d", &key);

    //Search
    int result = linearSearch(l, arr,key);

    //Print result
    if (result == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element %d is found at index %d\n", key,result);
    }

    return 0;
}

