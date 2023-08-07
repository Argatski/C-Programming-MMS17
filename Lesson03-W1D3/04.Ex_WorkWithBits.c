#include <stdio.h>
#include <stdint.h>

//Day-4 Work with bits

//CheBit()
int checkBit(uint16_t mask, int bit)
{
    return(mask&(1<<bit)? 1 :0);
}

//SetBit()
uint16_t setBit(uint16_t mask,int bit)
{

    return mask | (1<<bit);
}

//ClearBit()
uint16_t clearBit(uint16_t mask,int bit)
{
    return mask & ~(1<<bit);
}

//PrintBits()
void print_bits(uint16_t mask)
{
    printf("Print Bits:");

    for (int i =16-1; i>=0; i--)
    {
        printf("%d",checkBit(mask,i));

    }

    printf("\n");
}

int main(int argc, char *argv[]) 
{
    uint16_t digit = 0xffff; // 1111 1111  1111 1111 <= 2 bytes x 8
    

    //Print bits
    print_bits(digit);
    
    printf("Check bit %d is %d \n",4,checkBit(digit, 4));
    
   

    //4 bit - clear Bits
    printf("Print bits after clear bits funciton:\n");
    digit= clearBit(digit,4 );

    print_bits(digit);

    printf("Check bit %d is %d \n",4,checkBit(digit, 4));

    //Set Bits
    printf("Set bit %d\n",4);
    
    digit = setBit(digit, 4);

    print_bits(digit);  

    printf("Check bit %d is %d \n",4,checkBit(digit, 4));

        return 0;
}  