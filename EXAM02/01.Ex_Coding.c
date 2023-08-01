# include <stdio.h>
#include <stdlib.h>
#include <string.h>

char chageSym2(int position)
{
    switch (position) {
        case 0:
        return '!';
        case 1:
        return '#';
        case 2:
        return '/';
        case 3:
        return '~';
        case 4:
        return '=';
        case 5:
        return '`';
        case 6:
        return '\'';
        case 7:
        return '>';        
        case 8:
        return '.';
        case 9:
        return ',';
    }
}

char chageSym(int position)
{
    switch (position) {
        case 0:
            return 'A';
        case 1:
            return 'B';
        case 2:
            return 'C';
        case 3:
            return 'D';
        case 4:
            return 'E';
        case 5:
            return 'F';
        case 6:
            return 'G';
        case 7:
            return 'H';
        case 8:
            return 'I';
        case 9:
            return 'J';
    }
}

///Coding char arr
char* codingArr(char *str1)
{
    int len = strlen(str1);
    char* res = malloc(len);

    for (int i=0; i<len; i++) {
        if (i%2==1)
        {
            res[i] = chageSym(str1[i]);
        }
        else {
            res[i] = chageSym2(str1[i]);
        }
    
    }

    return res;
}


int main(int argc, char *argv[]) 
{
    char *str1 = "";

    //Read str1
    scanf("%s", str1);


    //Print 
    printf("%s\n", codingArr(str1));
    return 0;
}