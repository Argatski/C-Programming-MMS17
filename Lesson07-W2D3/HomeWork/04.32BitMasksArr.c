#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int clearBits(uint32_t *maskArr, size_t nitems, size_t bit_index) {
  if (maskArr == NULL || bit_index >= 32) {
    return -1;
  }

  for (size_t i = 0; i < nitems; i++) {
    maskArr[i] &= ~(1 << bit_index);
  }
  return 0;
}

int setBits(uint32_t *maskArr, size_t nitems, size_t bit_index) {
  if (maskArr == NULL || bit_index >= 32) {
    return -1;
  }

  for (size_t i = 0; i < nitems; i++) {
    maskArr[i] |= (1 << bit_index);
  }
  return 0;
}

int checkBits(uint32_t *maskArr, size_t len, size_t bit_index) {
  if (maskArr == NULL || bit_index >= 32) {
    return -1;
  }

  int allbitsZeros = 1;
  int allBitsOne = 1;

  for (size_t i = 0; i < len; i++) {
    int value = (maskArr[i] >> bit_index) & 1;
    if (value == 0) {
      allBitsOne = 0;
    } else {
      allbitsZeros = 0;
    }
    maskArr[i] &= ~(1 << bit_index);
  }

  if (allBitsOne || allbitsZeros) {
    return allBitsOne;
  } else {
    return -1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  // uint32_t maskArr[] = {1, 2, 3, 4, 5};
  uint32_t maskArr[] = {0xFFFFFFFF, 0x0000FFFF, 0xFFFF0000};

  size_t len = sizeof(maskArr) / sizeof(uint32_t);

  // Read the index of console
  size_t bit_index = 0;
  printf("Reading index of console :");
  scanf("%lu", &bit_index);

  int resut;

  // Clear bits index
  resut = clearBits(maskArr, len, bit_index);
  if (resut == 0) {
    printf("Clearing bit is successful bit index %lu\n result %d\n.", bit_index,
           resut);
  } else {
    printf("Clearing bit is not successful bit index %lu\n result %d\n.",
           bit_index, resut);
  }

  // Read the index of console
  printf("Reading index of console :");
    scanf("%lu", &bit_index);

  // Set bits index
  resut = setBits(maskArr, len, bit_index);
  if (resut == 0) {
    printf("Setting bit is successful bit index %lu\n result %d\n.", bit_index,
           resut);
  } else {
    printf("Setting bit is not successful bit index %lu\n result %d\n.",
           bit_index, resut);
  }

  // Read the index of console
  printf("Reading index of console :");
  scanf("%lu", &bit_index);

  // Check bits index
  resut = checkBits(maskArr, len, bit_index);
  if (resut == 0) {
    printf("Checking bit is successful bit index %lu\n result %d\n.", bit_index,
           resut);
  } else if (resut == 1) {
    printf("Checking bit is successful bit index %lu\n result %d\n.", bit_index,
           resut);
  }

  else {
    printf("Checking bit is not successful bit index %lu\n result %d\n.",
           bit_index, resut);
  }

  return 0;
}
