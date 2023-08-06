#include <stdint.h>
#include <stdio.h>

//
int main(int argc, char *argv[]) {
  double num;
  scanf("%lf", &num);

  // UB
  uint64_t res =
      *(uint64_t *)&num; // Побитово представяне на числото.Но не
                         // желателно да се използва.Тъй като губиме прецизност
                         // защото превържаме double to integrate.

  res = res & ~(1ULL << 63); 

  //UB
  num = *(double *)&res;
  printf("%lf\n", num);

  return 0;
}