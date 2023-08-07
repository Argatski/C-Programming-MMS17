#include<stdio.h>
#include<stdarg.h>

int sum_variadic(int c, ...) {
    va_list args;
    va_start(args, c);
    int sum = 0;
    for(size_t i = 0; i < c; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

int main() {
    printf("%d\n", sum_variadic(9, 10, 20, 30, 40, 50, 60, 70, 10, 20));


     //printf("%d", sum_variadic(3, 20, 30, 40));

    return 0;
}