#include <limits.h>
#include <stdio.h>
#include<inttypes.h>

//Day 09
int main(int argc, char *argv[]) 
{
    //Undefined Behavior access to uninitialized local variables
    int a;
    a=a+5;
    printf("%d\n",a);

    //UB: access to element outside of array bounds
    int b[5]={0,1,2,3,4};

    //b[5]=2;

    //UB: dereference null pointer
    int *c=NULL;
    printf("%d\n",*c); //Return segmentation fault (core dumped memory)

    //UB: signed integer overflow
    int d =INT_MAX;
    d++;

    //UB: access of object though pointer to incompatible type
    double e = 3.14159;
    uint64_t *p2= &e;
    *p2=1;

    return 0;
}