#include <stdio.h>

int num;
int countNumber;

//Day 3
void Print(int num, int countNumber)
{
   for (int i = 1; i<100; i++) {
        if (num==0&&i%2==0)
        {
            printf("%d is Even number:\n",i);
        }
        else if (num==1&&i%2==1)
        {
            printf("%d is Odd number:\n",i);
            continue;
        }     
        if (i==countNumber)
        {
            break;
        }
   }
}


int main(int argc, char *argv[]) 
{
    //Read from console
    //If number is 0 -> Event
    //If number is 1 -> Odd
    printf("Set number:");
    scanf("%d", &num);

    printf("Set count numbers:");
    scanf("%d", &countNumber);
    
    //Print Result
    Print(num,countNumber);
  
    return 0;
}
