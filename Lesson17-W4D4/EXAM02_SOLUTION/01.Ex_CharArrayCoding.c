#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const char odd_symbols[] = "!#/~='\\>.,";

// A B C \0
// 0 1 2 3
char *encode_str(const char *str) {
    size_t n = strlen(str);
    char *new_str = malloc(sizeof(char)*(n+1));
    for(size_t i = 0; i < n; i++) {
        if(i%2 == 0) {
            // Четна позиция
            // str[i]: 48 - '0', 49 - '1', 50 - '2'. ....
            //         65 - 'A', 66 - 'B', 67 - 'C'
            new_str[i] = str[i] - '0' + 'A';
        } else {
            // Нечетна позиция
            new_str[i] = odd_symbols[str[i] - '0'];
        }
    }
    return new_str;
}
int main() {
    char input[501];
    scanf("%s", input);
    char *result = encode_str(input);
    printf("%s\n", result);
    free(result);
    return 0;
}