#include <stdio.h>


int main(int argc, char* argv[])
{
    FILE *f1 = fopen("test.txt", "r");

    char c;
    while ((c = fgetc(f1)) != EOF) {
        putchar(c);
    
    }

    putchar('\n');
    putchar('\n');

    fseek(f1, 0, SEEK_SET);
    char buf[10];

    while (fgets(buf,sizeof(buf),f1)!=NULL) {
    fputs(buf,stdout);
    }

    putchar('\n');
    putchar('\n');

    fseek(f1,0, SEEK_SET);
    while (fscanf(f1, "%10s",buf)==1) {
     fprintf(stdout, "%s",buf);
    }
    putchar('\n');
    putchar('\n');

    size_t numRead;
    while ((numRead =fread(buf,sizeof(char),sizeof(buf),f1))>0) {
    fwrite(buf, sizeof(char), numRead,stdout);
    }

    //Another solution
    while (1) {
        c = fgetc(f1);
        if (feof(f1)){
            break;
        }
        printf("%c", c);
    }

    fclose(f1);

    return 0;
}