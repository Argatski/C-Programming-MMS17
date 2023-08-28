#include <bits/types/FILE.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Sort argumets accending order
int cmp(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(int argc, char* argv[])
{
    if (argc == 1) {
        perror("Invalid arguments\n");

        exit(-1);
    }

    
    qsort(argv+1, argc-1, sizeof(char*), cmp);

    char filename[100] ;
    printf("Name of the file: %s\n", filename);
    scanf("%s", filename);


    FILE *f = fopen(filename, "r");
    if (f!=NULL) {
        perror("File  already exists");
        exit(-1);
    }   

    f=fopen(filename, "w");
    if (f==NULL) {
        perror("Connot create file.\n");
        exit(-1);
    }
    
    for(int i = 1; i <argc; i++) {
        fprintf(f, "%s\n", argv[i]);
    }

    fclose(f);

    return 0;
}