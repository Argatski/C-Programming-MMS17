#include <stdio.h>

typedef struct A
{ 
  //Важи са за тези типове данни не важи за char или double 

  unsigned int a : 3;
  //This bit-field a is an unsigned integer with 3 bits. The range of an unsigned integer with 3 bits is from 0 to (2^3 - 1), which is 0 to 7. So, the valid values for a are 0 to 7.

  signed int b : 7;
  /*
  This bit-field b is a signed integer with 7 bits. The range of a signed integer with 7 bits is from -2^(7-1) to (2^(7-1) - 1), which is -64 to 63. So, the valid values for b are -64 to 63.
  */

  int c:5;
  //signed int c;5;
  //[-2^(5-1),2^(5-1)-]

  
  unsigned int d : 30; 
  /*
  This bit-field d is an unsigned integer with 30 bits. The range of an unsigned integer with 30 bits is from 0 to (2^30 - 1), which is 0 to 1073741823. So, the valid values for d are 0 to 1073741823.
  */
}A;

//
int main()
{
    A a;
    a.a=4;
    a.b = -63;
    a.c=2;

    printf("%lu\n",sizeof(A));

    //printf("%p",&(a.a)); ne e vazmojno
    return 0;
}