#include<stdio.h>
#include<unistd.h>
int main() {
    char buf[2] = {'4', '8'};
    write(STDOUT_FILENO, buf, sizeof(buf));
    return 1;
}