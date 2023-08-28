#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void nFile(int argc, char *argv[])
{
    for(int i = 1; i < argc;i++)
    {
        FILE *f = fopen(argv[i], "r");
        if (!f) {
            perror("Couldn't open file\n");
            exit(-1);
        }

        printf("Text %d\n",i);    
        char buf[100];
        while (fgets(buf, sizeof(buf), f) != NULL) {
            printf("%s\n", buf);
        }
        fclose(f);
    }
}

int main(int argc, char*argv[])
{
    if (argc ==1) {

        char buf[100];

        printf("Write your text\n");
        while (fgets(buf,sizeof(buf),stdin) != NULL) {
            printf("%s\n",buf);
        }

    }
    else if(argc ==2) 
    {
        nFile(argc,argv);

    }
    //Можем да използваме и само тази проверка когато подаваме един или повече от един файл
    //Предвид условеито че трябва да имам и за един файл се налага използването и на горната проверка
    else
    {
        nFile(argc, argv);
    }

    return 0;
}