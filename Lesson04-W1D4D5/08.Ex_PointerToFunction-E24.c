#include <stdio.h>
#include <stdlib.h>

//извикване на фунцкията директно
int multip_a_b(int a,int b);

//Day 5 - Pointer to funciton.
int main(int argc, char *argv[]) 
{
    //извикване на фунцкията директно
    int result = multip_a_b(10, 2);
    printf("Result through funcion call: %d\n", result);

    //изикване на функция през указател (поинтер)::
    int (*mlpPtr)(int a,int b);//define finction pointer
    mlpPtr = multip_a_b;//assign function pointer

    //FULL notation
    result = (*mlpPtr)(20, 2);
    printf("Result through pointer/long/: %d\n",result);

    //SHORT notation
    result = mlpPtr(30, 2);
    printf("Result through pointer/long/: %d\n",result);

    return 0;
}

int multip_a_b(int a,int b)
{
    return a*b;
};