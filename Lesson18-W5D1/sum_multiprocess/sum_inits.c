#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int curNum;
    unsigned long long sum = 0;
    int num_read;
    do {
    curNum = 0;
    //Syscall for each 4 bytes in input - slow
    num_read = read(STDIN_FILENO, &curNum,sizeof(curNum));

    sum += curNum;
    }while (num_read ==sizeof(curNum));

    printf("%lld\n",sum);
    return 0;
}