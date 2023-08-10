#include <stdint.h>
#include <stdio.h>

//swap byte
void swapBytes(uint16_t* word)
{
    *word = ((*word <<8) & 0xff00) | ((*word >> 8) & 0x00FF);
}

int main(int argc, char *argv[]) {

    uint16_t word = 0x2365;
    printf("Number before swaping : %04x\n", word);
    swapBytes(&word);
    printf("Number after swaping : %04X\n", word);

    return 0;
}
