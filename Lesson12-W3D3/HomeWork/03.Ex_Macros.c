#include <stdio.h>
//1.1
#define MAX(x,y,z) (((x)>(y))?(((x)>(z))?(x):(z)):(((y)>(z))?(y):(z)))
//1.2
#define MIN(x,y,z) (((x)<(y))?(((x)<(z))?(x):(z)):(((y)<(z))?(y):(z)))
//1.3
#define SETBIT(mask,bit) ((mask)|=(1<<(bit)))
//1.4
#define CLEARBIT(mask,bit) ((mask) &= ~(1<<(bit)))
//1.5
#define  INVERSEBIT(mask,bit) ((mask)^=(1<<(bit)))
//1.6
#define CHECHBIT(mask,bit) ((mask)&((1<<(bit))))
//1.7
#define SWAP(a,b) do{(a) ^= (b);(b) ^= (a);(a) ^= (b);}while(0)





int main(int argc, char *argv[])
{
    int x=5, y=7, z=11;
    //Max number 
    printf("MAX: %d\n", MAX(x,y,z));

    //Min number
    printf("MIN: %d\n", MIN(x,y,z));

    unsigned int mask = 0;
    //Set bit mask
    SETBIT(mask, 3);
    printf("SETBIT: %u\n",mask);

    //CLear bit mask
    CLEARBIT(mask, 3);
    printf("CLEARBIT: %u\n",mask);

    //INVERSE bit mask
    INVERSEBIT(mask, 2);
    printf("INVERSEBIT: %u\n",mask);

    //CHECK bit mask
    unsigned int mask2 = 0b10101010;
    int s = CHECHBIT(mask2, 3);
    printf("CHECK bit mask: %u\n",s);

    int a =4,b=10;
    SWAP(a, b);
    printf("SWAPBIT: a=%d ,b=%d\n",a,b);
    
    return 0;
}
