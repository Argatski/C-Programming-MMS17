#include <limits.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>

//Sizeof(A)=4
typedef union A
{
    unsigned int ui;
    unsigned char bytes[4]; // za da go vijdame v prav kod
} A;

//Printirane na chislo ot desetichno v hexadec(16-tichno)
void printBytes(A a)
{
    for (size_t i=0; i<4;i++)
     {
        printf("%02x ", a.bytes[i]);
    }
    printf("\n");
}

//unsigned int i =UINT_MAX -1 
//BIG:            FF FF FF FE 
//                 ^  ^  ^  ^          
//address          1  2  3  4
//========================>
//LITTLE ENDIA    FE FF FF FF
//                ^  ^  ^  ^
//Address         1  2  3  4
int main()
{
    A u1;
    u1.ui = 254;

    printBytes(u1);

    u1.ui=UINT_MAX -2;
    printBytes(u1);

    u1.ui = 9;
    printBytes(u1);


    return 0;
}