#include<stdio.h>

//Day 4
//Definition of get value with offset:
int getValueWithOffset(int *ptr,int offset)
{
    int *newPointer =  ptr+offset;

    return *newPointer;
}

//Start program
int main(int argc, char *argv[]) 
{
    //Array
    int array[10] = {10,20,30,40,50,60,70};

    //Pointer
    int *arrPtr = array;
    int offset = 3;

    int value =  getValueWithOffset(array, offset);

    //Not working the result must be same 40 
    printf("value at index [%d] is %d\n",offset,value);

    printf("Though array Vaule at index [%d] is %d \n",offset,array[offset]);
    
 
}//End program