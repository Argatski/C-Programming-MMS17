#include <stdio.h>

typedef union A{
    char c;
    double d;
    int i;
} A;
//########
// c
// d
// i

typedef struct Arg{
    A argVal; //8 bytes
    int argType; //4 bytes
    //4 bytes
} Arg;
// ######## ####  ####
// argVal argType padding

typedef struct Arg_Bloated{
    char c;
    double d;
    int i;
    int argType;
} Arg_Bloated;

void print(Arg a)
{
    if (a.argType ==0) {
        printf("%c\n", a.argVal.c);
    }
    if (a.argType ==1) {
        printf("%f\n", a.argVal.d);
    }
    if (a.argType ==2) {
        printf("%d\n", a.argVal.i);
    }
}

int main(int argc, char *argv[]) 
{
    Arg ardChar;
    ardChar.argType = 0;
    ardChar.argVal.c = 'W';
    print(ardChar);

    Arg ardDouble;
    ardDouble.argType = 1;
    ardDouble.argVal.d = 3.141516;
    print(ardDouble);

    Arg ardInt;
    ardInt.argType = 2;
    ardInt.argVal.i = 1231512;
    print(ardInt);

    return 0;
}