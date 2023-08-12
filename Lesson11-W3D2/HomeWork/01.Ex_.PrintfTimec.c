#include <stdarg.h>
#include <stdio.h>
#include <time.h>

int printf_time(const char *format, ...)
{
    time_t timeR;
    struct tm *timeInfo;
    char buf[24];

    time(&timeR);
    timeInfo = localtime(&timeR);
    strftime(buf, sizeof(buf), "[%d.%m.%Y - %H:%M:%S]", timeInfo);

    printf("%s\n", buf);

    va_list args;
    va_start(args, format);
    //int result = vprintf(format, args);
    va_end(args);
    return 0;
}

int main()
{
    printf_time("%d %d\n", 10,20);
    return 0;
}