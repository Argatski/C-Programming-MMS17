#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void onInterrupt(int sigNum) {
    printf("cannot be interupted\n");
    exit(0);
}
void onTerminate(int sigNum) {
    printf("Stopping program\n");
    exit(-1);
}
int main() {
    signal(SIGINT, onInterrupt);
    signal(SIGTERM, onTerminate);
    signal(SIGKILL, onTerminate);
    while(1) {
        printf("Hello world!\n");
    }
    return 0;
}