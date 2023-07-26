
//Prototype of function:
int square(int num);

//Main funcution:
//Int main(void)
#include <stdio.h>
int main(int argc, char* argv[])
{

    int num;

    printf("Input number : ");
    // Read console.
    scanf("%d", &num); 

    // Call function square number
    int result =  square(num); 

    // Print result 
    printf("%d squared is %d \n", num,result); 

}

//Declare and Defin function:
int square(int num)
{
    return num*num;    
}
