#include <stddef.h>
#include <stdio.h>
#define CHECK_BIT(a,i) (!!(a&(1ULL<<i)))

typedef struct char_bits{
    unsigned int b1:1; // 0 или 1 
    unsigned int b2:1;
    unsigned int b3:1;
    unsigned int b4:1;
    unsigned int b5:1;
    unsigned int b6:1;
    unsigned int b7:1;
    unsigned int b8:1;
    //zapisa b1:1 ruchno zadavane na razmera na tipa dani.
    //cqlata strutura zadelq 4byte zaradi izpolzvaniq tip int koito se nujdae ot 4byte

} char_bits ;

typedef union C{
    char c;
    char_bits bits;
} C;

int main(int argc, char *argv[]) 
{
    char c =7;

    //Convert decimal to binary format 7 to 00000111
    for (size_t i=8; i>0; i--) {
        printf("%u", CHECK_BIT(c,(i-1)));
    }

    printf("\n");

    C c1;
    //8bits == 1bytes
    // ########
    
    c1.c = -7;

    //11111001
    //^
    //c1.c
    //11111001
    //^
    //b8
    // ^
    // b7
    //  ^
    //  b6
    
    //Convert decimal to binary -7 to 11111001
    printf("%u", c1.bits.b8);
    printf("%u", c1.bits.b7);
    printf("%u", c1.bits.b6);
    printf("%u", c1.bits.b5);
    printf("%u", c1.bits.b4);
    printf("%u", c1.bits.b3);
    printf("%u", c1.bits.b2);
    printf("%u\n", c1.bits.b1);

    printf("%lu\n", sizeof(char_bits));

    return 0;
}