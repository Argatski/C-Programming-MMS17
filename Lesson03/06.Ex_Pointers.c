#include <stdio.h>


//Day 4
int main(int argc, char *argv[]) 
{
    //Def number
    int num =10;

    //Print number
    printf("Number: %d\n",num);

    //Def pointer
    int *ptr = &num;

    //Print pointer
    printf("Adress(Pointer): %p\n",ptr);
    
    //Def Value
    int value = *ptr;

    
    // Print value
    printf("Value by Pointers: %d\n",value);


    //Print value prisfoqvame stoinosta na num kum value.
    printf("Value though Pointers: %d\n",value);
    
    if(num==value)
    {
        printf("Number and value are equal\n");
    }

    //Assignment of 20 to number through pointer.
    *ptr = 20;
    printf("Value by Pointers: %d\n",value);
    printf("Number: %d\n",num);
    
    

    return 0;
}