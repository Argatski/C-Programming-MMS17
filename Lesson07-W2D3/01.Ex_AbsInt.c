#include <stdint.h>
#include <stdio.h>


int main(int argc, char *argv[]) 
{
    int64_t a;

    scanf("%lu",&a);
    
    
    int signBitValue = !!(a&(1ull<<63));

    
    //  printf("%lu\n",(~(a-1))*(signBitValue));
    //  printf("%lu\n",a*!signBitValue);

    printf("%lu\n",a*!signBitValue+~(a-1)*signBitValue);

    //unsigned char a=25;
    //00011001
    //a&(1ull<<3)
    //1ULL<<3=== 00001000 (resulter)
    //
    //a&(00001000)
    //00011001
    //&
    //00001000
    //====
    //00001000 === 8
    return 0;


}