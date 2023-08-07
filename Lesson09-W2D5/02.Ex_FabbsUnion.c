#include <stdint.h>
#include <stdio.h>

typedef union A
{
    double d; // 8 bytes
    uint16_t u; // 8 bytes
} A;

//sizeOf(A) = 8 bytes

int main()
{
    A a;
    scanf("%lf", &(a.d));
    a.u =a.u &~(1ULL <<63);
    printf("%lf\n", a.d);
    return 0;
}


