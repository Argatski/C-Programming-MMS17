#include <stdio.h>

//Start Program
int main(int argc, char *argv[]) 
{

    //Character type.
    char symbol='c';
    printf("Character: %c\n",symbol);

    //Whole numbers
    int number = 100;
    printf("Whole number: %d\n",number);
    
    // Decimal numbers
    float decimal = 3.14;
    printf("Decimal number: %f\n", decimal);

    double dec = 3.14159265359;
    printf("Decimal number: %lf\n", dec);

    _Bool myBool = 1;
    printf("Boolean: %d\n", myBool);

    return 0;
}
//End Program