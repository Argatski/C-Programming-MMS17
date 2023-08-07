#include <stdarg.h>
#include <stdio.h>

void my_printf(const char *fmt, ...)
{
    va_list args;
        va_start(args, fmt);
        printf("Custom printf");
        vprintf(fmt, args);
        va_end(args);
}

int main()
{
    my_printf("%d %d %d\n", 30, 40, 50);
    my_printf("%s %x\n", "HELLO", 12);
        return 0;
}