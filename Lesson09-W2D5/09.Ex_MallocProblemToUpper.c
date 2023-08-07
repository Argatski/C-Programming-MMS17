#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ToUpper
char * toUpper(const char* str)
{
    int i;
    int len = strlen(str);
    char *newStr = (char *)malloc(len * sizeof(char));
    for (i = 0; i < len; i++)
    {
        newStr[i] = toupper(str[i]);
    }
    return newStr;
    
}

//ToUpper2
// RETURNING LOCAL ARRAY - WRONG
char * toUpper2(const char* ptr)
{
    size_t i = 0;
    size_t len = strlen(ptr);
    char* new_str = (char*)malloc(len*sizeof(char));
    //char new_str[strlen(ptr) + 1];
    while(ptr[i] != '\0') {
        if(ptr[i] >= 'a' && ptr[i] <= 'z') {
            *(new_str + i) = ptr[i] - 'a' + 'A';
        } else {
            new_str[i] = ptr[i];
        }
        i++;
    }
    // while(*(ptr+i) !='\0')
    new_str[i] = '\0';
    return new_str;
}


int main(int argc, char *argv[]) 
{
    //Uper read fro CLA
    if (argc!= 2)
    {
        printf("No argumetns:\n");
        return 1;
    }
    char *str = argv[1];
    char *newStr = toUpper(str);
    printf("%s\n", newStr);
    free(newStr);


    //Upper2
    char * str2 = toUpper2("hello world;./");
    printf("%s\n", str2);
    free(str2);
    return 0;

}