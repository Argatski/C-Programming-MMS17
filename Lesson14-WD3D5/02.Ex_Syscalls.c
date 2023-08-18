#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct A {
  char a;
  // 3 bytes
  int b;
} A;

const char *errOpen = "Error opening file";

int main(int argc, char *argv[]) {
  int fd = open("test1000.txt", O_CREAT | O_WRONLY, 0777);
  
  if (fd == -1) {
    write(2, errOpen, strlen(errOpen));
  }

  size_t K =1000;
  A a = {'#',500};
  write(fd, "205",3);
  write(fd, &K, sizeof(K));
  write(fd, &a, sizeof(a));

  close(fd);

  return 0;
}