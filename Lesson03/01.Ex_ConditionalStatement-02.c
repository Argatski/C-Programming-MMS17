#include <stdio.h>

//Day 3
int main(int argc, char *argv[]) 
{
    int num;
    printf("Enter a number\n");
    scanf("%d", &num);

    if(num>20)
    {
        printf("%d is greater than or equal 20\n",num);
    }
    else if(num>5)
    {
        printf("%d is greater than 5 but less than 20\n",num);
    }
    else
    {
        printf("%d is less than or equal 5\n",num);
    }
    
    return 0;
}