#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


//Start program use this syntax
//./05.Ex_WriteNumbersBin number.bin 2000

int main(int argc, char* argv[])
{
    //Write numbers number.txt 10000

    if (argc!=3) {
        fprintf(stderr,"Argc invalid\n");
    }

    //Open file stream
    FILE*  f1 =  fopen(argv[1], "w");

    //Check if file isn`t open
    if (!f1) {
        perror("fopen error");
    }
    
    long long N =  atoi(argv[2]);

    //Wirte number in file
    for (size_t i=0; i<N; i++) {
        fwrite(&i, sizeof(i), 1, f1);

    }

    //Close file stream 
    fclose(f1);

    return 0;
}