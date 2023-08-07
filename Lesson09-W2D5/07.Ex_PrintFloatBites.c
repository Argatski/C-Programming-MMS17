#include <stdio.h>

typedef struct float_comp{
    unsigned int mantissa:23;
    unsigned int exponent:8;
    unsigned int sign:1;
}float_comp;

typedef union F{
    float f;
    float_comp c;
}F;

struct test{
    signed int a:1;
};

int main()
{
    F f1;
    scanf("%f", &(f1.f));
    printf("SIGN: %u EXPONENT: %u MANTISSA:%u\n",f1.c.sign,f1.c.exponent,f1.c.mantissa);
}
