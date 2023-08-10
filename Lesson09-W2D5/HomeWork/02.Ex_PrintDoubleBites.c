#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleStrs
{
    uint64_t mantissa:52;
    uint16_t exponent:11;
    uint8_t sign:1;
}DoubleStr;

typedef union D
{
    double d;
    DoubleStr s;
}D;

void printSingExponentMantissa(double num)
{
    D f1;
    f1.d = num;
    printf("Standard for Floating-Point Arithmetic:\n"); 
    printf("SIGN: %hu EXPONENT: %hu MANTISSA: %lu\n",f1.s.sign,f1.s.exponent,f1.s.mantissa);
}

void printByts(double num)
{
    unsigned char * desmond = (unsigned char *) & num;
    int i;

    printf("Bytes:\n");
    for (size_t i = 0; i < sizeof (num); i++) {
         printf ("%02X ", desmond[i]);
    }
    printf ("\n");
}

void printBits(double num)
{
    unsigned char * desmond = (unsigned char *) & num;
    int i;

    printf ("Bits:\n");
    for (size_t i = 0; i < sizeof (num); i++) {
         printf ("%08b ", desmond[i]);
    }
    printf ("\n");
}

int main() 
{   
    double num;
    printf("Enter floating point number: ");
    scanf("%lf", &num);

   
    printSingExponentMantissa(num);

    printBits(num);

    printByts(num);

    
    return 0;
}