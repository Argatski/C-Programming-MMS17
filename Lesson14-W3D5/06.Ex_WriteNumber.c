#include <stdio.h>


int main(int argc, char * argv[])
{
    char *filename = "Number2.txt";

    FILE *f = fopen(filename, "w");

    if (f==NULL) {
        printf("Error opening file %s\n", filename);

        return -1;
    }

    int N;
    printf("Input count of number:\n");

    scanf("%d", &N);

    printf("Set the number:\n");

    for (int i=0; i<N; i++)
    {
        int num;
        scanf("%d", &num);

        fprintf(f,"%d", num);
    }     

    fclose(f);

    return 0;

}