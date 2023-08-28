#include <stdio.h>
#include <stdlib.h>


#define  BUF_SIZE 1000

int main(int argc, char *argv[])
{
    // ./07.Ex_WriteNumber number3.txt 1000

    if (argc!=3) {
        fprintf(stderr, "Argc invalid\n");
        exit(-1);
    }

    FILE *f = fopen(argv[1],"w");

    if (!f) {
        perror("Fopen error");
        exit(-1);
    }

    size_t N = atoi(argv[2]);
    size_t buf[BUF_SIZE];

    for(size_t i = 0; i < N;i++) {
        if (i% BUF_SIZE ==0 && i != 0) {
            fwrite(buf, sizeof(*buf),BUF_SIZE,f);
        }
        buf[i%BUF_SIZE] =i;
    }

    fclose(f);
    return 0;
}