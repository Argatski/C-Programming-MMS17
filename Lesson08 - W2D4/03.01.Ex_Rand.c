#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  unsigned int A = 100, B = 300;
  // Случайни числа в интервала [A,B]
  //  А=100, B=300
  // 100+ случайно число в диапазаона [0,200]
  // 300- случайно число в диапазона [0,300-100)

  srand(time(NULL));

  for (int i = 0; i < 10; i++) {
    printf("%u\n", A + rand() % B + A);
  }

  return 0;
}