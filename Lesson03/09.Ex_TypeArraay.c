#include<stdio.h>

//Day 4 -Array
int main(int argc, char *argv[]) 
{
    //Array with set lenght.
    int arr01[5]={15,1,2,3,5};

    //Print array with set lenght.

    for (int i=0; i<5; i++)
    {
        printf("Position of elelment [%d] -> Element: %d\n",i, arr01[i]);
    }


    printf("----------------\n");

    //Array without set lenght.
    int arr02[]= {15,28,33,55,88,89};

    //Calculate array lenght
    int arr_length = sizeof(arr02)/sizeof(arr02[0]);

    //Print array without set lenght.
    for (int i=0; i<arr_length; i++)
    {
        printf("Position of elelment [%d] -> Element: %d\n",i, arr01[i]);
    }


    return 0;
}