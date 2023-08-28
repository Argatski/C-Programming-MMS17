#include <stdio.h>  
#include <stdlib.h>

// fopen
// putchar puts printf fprintf fputc fputs
// fscanf scanf fgetc fgets getchar
// fclose
// fseek, ftell, rewind

int main(int argc, char **argv)
{
    FILE *my_standartout=fopen("test.txt", "r");

    if(!my_standartout)
    {
        perror("fopen error");
        exit(-1);
    }
    char buf[10];
    fgets(buf,sizeof(buf),my_standartout);
    puts(buf);
    fseek(my_standartout,-4,SEEK_END);
    printf("%ld\n",ftell(my_standartout));

    fgets(buf,sizeof(buf),my_standartout);
    puts(buf);
    
    fclose(my_standartout);

    return 0;
}