#include <complex.h>
#include <stdarg.h>
#include <stdio.h>

int my_printf(const char * fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    const char * p = fmt;
    int pCh =0;
    while (*p!='\0') {
        if (*p == '%') {
            p++;
            switch (*p) {
                case 'd':
                pCh += printf("%d",va_arg(args, int));
                break;
                case 'c':
                pCh += printf("%c",va_arg(args, int));
                break;
                case 'f':
                pCh += printf("%f",va_arg(args,double));
                break;
                default:
                putchar(*p);
                pCh++;
                break;
            }
        }
        else {
            putchar(*p);
            pCh++;
        }
        p++;
    }
    va_end(args);
    return pCh;
}

int main(){
    int num = 42;
    double floating = 3.14;
    char character = 'A';

    int printed = my_printf("Integer: %d\n", num);
    printed += my_printf("Floating-point: %f\n", floating);
    printed += my_printf("Character: %c\n", character);

    printf("Total printed characters: %d\n", printed);

    return 0;
}