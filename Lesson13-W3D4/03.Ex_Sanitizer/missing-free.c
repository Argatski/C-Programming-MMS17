#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]) {
    char *s = malloc(100);
    strcpy(s, "MMS STAR CAMP");
    printf("%s\n", s);
    return 0;
}