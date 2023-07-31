#include <stdio.h>

int strlen_(char *str);// Return lenght char array

void strcpy_(char *dest,char *src);

void strcat_(char *dest,char *src);

int strcmp_(char*s1,char *s2);

//Day 6 String Func

int main(int argc, char *argv[]) 
{   

    char str[100]="Hello world";
    char str1[100]="Hello world";
    
    //String lenght  (Дължина на символния низ.)
    printf("String %s\n",str);
    printf("Lenght: %d\n",strlen_(str));

    //String copy
    char str2[100]="AGSADASVASDEGADSKJLJELEW", str3[100]="HELLO";
    strcpy_(str2,str3);
    printf("Strcpy: %s\n",str2);


    //String concatenation
    char str4[100]="HELLO",str5[100]="World!";
    strcat_(str4,str5);
    printf("Strcat: %s\n",str4);

    printf("Strcat2: %s\n",str4);


    //String comparison
    printf("Euqual array: %d",strcmp_(str,str1));

    return 0;
}

//Copy array in to another array
void strcpy_(char *dest,char *src)
{
    while (*src)
    {
        *(dest++)=*(src++);    
    
        //Another solution
    /*
        *dest= *src;
        dest++;
        src++;
    */
    }
    *dest='\0';

}


//Are equal s1 and s2
int strcmp_(char *s1, char *s2)
{
    while (*s1 == *s2   && *s1)
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

//Добавя scr към края на dest.
//scr --> World
void strcat_(char *dest,char *src)
{
    //printf("%p\n",dest);

    dest+=strlen_(dest);

    //printf("%p\n",dest);
    
    while (*src)
    {
        *dest= *src;
        dest++;
        src++;
    }
    *dest='\0';
}

void strcat2(char *dest,char *src)
{
    strcpy_(dest+strlen_(dest), src);
}


//Return lenght char array
int strlen_( char *str)
{
    int result;

    for(result = 0; str[result]!= '\0'; result++);
//Anathor solution    
    /*
    while (str[result]!='\0')
    {
        result++;
    }  
    */
//Another solution
    /*    while (*(str++))
    {
        result++;
    }
    */
    
    return result;
}