#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]) {
    char *s = malloc(100);
    free(s);
    printf("%s", s);
    return 0;
}