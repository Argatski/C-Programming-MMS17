#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) 
{
    double a;
    uint64_t b;
    printf("Set negative number:\n");
    scanf("%lf", &a);

    printf("%f\n", a);

    //memcopy copies the values from src to dst
    memcpy(&b, &a, 8);

    //Before converting
    printf("Before conversion\n");

    for (size_t i=64; i>=1; i--)
    {
        printf("%d",!!(b & (1UL << (i-1)))); 
    }

    printf("\n");

    //Convert negative numbers to positive use bites's formula (sifting evry bit 63 times)
    b=b&~(1UL << 63);

    //After converting
    printf("After conversion\n");

    for (size_t i=64; i>=1; i--)
    {   
        printf("%d",!!(b & (1UL << (i-1))));
    }
    printf("\n");
    
    memcpy(&a, &b,8);

    printf("Converted number:\n");
    printf("%lf\n",a);
}