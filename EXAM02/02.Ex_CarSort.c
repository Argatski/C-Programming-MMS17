#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

typedef struct Car {
  char model[20];
  uint8_t maxSpeed;
  double price;

} Car;

// Compare car by model in acending oreder

int compareModelA(const void *a, const void *b) {
  return strcmp(((Car *)a)->model, ((Car *)b)->model);
}

// Compare car by model in descending order
int compareModelD(const void *a, const void *b) {
  return strcmp(((Car *)b)->model, ((Car *)a)->model);
}

// Compare car by maxSpeed in acending oreder
int compareMaxSpeedA(const void *a, const void *b) {
  return ((Car *)a)->maxSpeed - ((Car *)b)->maxSpeed;
}

// Compare car by maxSpeed in descending order
int compareMaxSpeedD(const void *b, const void *a) {
  return ((Car *)b)->maxSpeed - ((Car *)a)->maxSpeed;
}

// Compare car by price in acending order
int comparePriceA(const void *a, const void *b) {
  return ((Car *)a)->price - ((Car *)b)->price;
}

// Compare car by price in descending order

int comparePriceD(const void *b, const void *a) {
  return ((Car *)b)->price - ((Car *)a)->price;
}

int (*getComparator(int n))(const void *, const void *) {

  switch (n) {
  case 1:
    return compareModelA;
  case 2:
    return compareModelD;
  case 3:
    return compareMaxSpeedA;
  case 4:
    return compareMaxSpeedD;
  case 5:
    return comparePriceA;
  case 6:
    return comparePriceD;
  default:
    return NULL;
  }
}

void printResult(Car arr[], size_t c) {
  for (size_t i = 0; i < c; i++) {

    printf("%s %d %lf\n", arr[i].model, arr[i].maxSpeed, arr[i].price);
  }
}

int main(int argc, char *argv[]) {
  Car *car = malloc(N * sizeof(Car));

  for (int i = 0; i < N; i++) {
    // Read car value
    scanf("%s %hhu %lf", car[i].model, &car[i].maxSpeed, &car[i].price);
  }

  int n;
  printf("Input number in range[1-6]:\n");
  scanf("%d", &n);

  qsort(car, N, sizeof(Car), getComparator(n));
  printResult(car, N);


  free(car);

  return 0;
}