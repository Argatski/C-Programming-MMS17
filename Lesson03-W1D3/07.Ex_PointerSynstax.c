#include <stdio.h>

//Ден 4 - Pointers


int main(int argc, char *argv[]) 
{
    int *pc,c;

    c=22;

    printf("Address of c: %p\n",&c);
    printf("Value of c: %d\n",c);

    pc = &c;

    printf("Address of pointer pc: %p\n",pc);
    printf("Value of pointer pc: %d\n",*pc);

    c=11;

    printf("Address of pointer pc: %p\n",pc);
    printf("Value of pointer pc: %d\n",*pc);

    *pc=7;

    printf("Address of pointer pc: %p\n",pc);
    printf("Value of pointer pc: %d\n",*pc);

    //Някои чести грешки които допускам

    //pc=7;

    /*
    pc is address,but 'c' isn`t;

    pc=c;
    */

    /*&c (referenciqta) is address,but *pc ISN`T

    *pc=&c;    
    
    */


    /*both 'c' and *pc are values
    *pc=c;
    */

    return 0;
}