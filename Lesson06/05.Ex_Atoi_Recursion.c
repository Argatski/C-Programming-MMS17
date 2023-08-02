#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

//str  1234
//((1*10+2)*10+3)*10+4 представяне на десетично число 1234
//srt_rev 4321 фунцкия за обръщане на числото
//atoi_rev 4321  =     4+10*atoi_rev (321);
//atoi_rev 321 =       3+10*atoi_rev (21);
//atoi_rev 21 =        2+10*atoi_rev (1);
//atoi_rev 1 =         1+10*atoi_rev ('');
//atoi_rev ('')=       0 



//str_rev is reversed number string with (converts the string argument "str" to an integer(type int))
int atoi_rev(const char* str_rev)
{
    if(!*str_rev) //ако стигнеме терминираща нула спираме рекурсията.
    {   
        return 0;
    }
    
    return (*str_rev -'0') + atoi_rev(str_rev+1)*10;

}

void reverese(const char *str1,char *str2)
{
    str2+=strlen(str1);

    *str2-- ='\0';
    while(*str1)
    {   
        *str2--=*str1;
        str1++;
    } 

}

//Recursion

    
//ERROR
//res is local array (stored on stack)
//After function call to rev2 ends,-
// memory for res array can no longer be used.
//Segmentation fault (core dumped)
char* rev2(const char *str1)
{
    size_t n = strlen(str1);
    char res[n + 1];

    for (int i=n;i>=0;i--) 
    {
        res[i] = *str1++;
    }
}


//Start program
int main(int argc, char *argv[]) 
{


    //Convert string to int
    char str1[100] = "1234",
         str2[100];

    reverese(str1,str2);
    printf("Integer number is:%d\n",atoi_rev(str2));

    //Error
    //Segmentation fault (core dumped)
    char str3[10]="12345";
    char* str4 = rev2(str3);

    int res = atoi_rev(str4);

    printf("%d\n",res);

    return 0;


}