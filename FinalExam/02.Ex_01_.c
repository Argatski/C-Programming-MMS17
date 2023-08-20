#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    //./02.Ex_01_ numbers.bin 10000
    if(argc!=3)
    {
        perror("Argc invalid\n");
        exit(-1);

        //Another solution is
        fprintf(stderr, "Invalid arguments\n");
    }

    FILE *f = fopen(argv[1], "w");

    if (!f) {
        perror("fopen failed");
        exit(-1);
    }
    size_t N = atoi(argv[2]);

    for (size_t i =0; i<N; i++) {

        fwrite(&i, sizeof(i), 1, f);
    }

    fclose(f);

    return 0;

}