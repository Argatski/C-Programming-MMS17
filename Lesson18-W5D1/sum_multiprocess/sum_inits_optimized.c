#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define READ_INT_COUNT 10000
int main() {
    int *num_buf = malloc(READ_INT_COUNT*sizeof(int));
    unsigned long long sum = 0;
    int num_read;
    do {
        // Syscall for each 4 bytes in input - slow
        num_read = read(STDIN_FILENO, num_buf, sizeof(int)*READ_INT_COUNT);
        // printf("num_read: %3d, curNum(HEX): %10x, curNum(DEC): %5d\n", num_read, curNum, curNum);
        asm("nop");
        for(size_t i = 0; i < num_read/sizeof(int); i++) {
            sum += num_buf[i];
        }
        asm("nop");
    } while(num_read > 0);
    printf("%lld\n", sum);
    free(num_buf);
    return 0;
}