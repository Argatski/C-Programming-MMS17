#include <stdbool.h>
#include <stdio.h>

void filterAndMap(const int arr[], size_t n, int (*fillter_f)(int),
                  int (*map_f)(int), int dest[]) {
  int count = 0;

  for (size_t i = 0; i < n; i++) {

    if (fillter_f(arr[i])) {
      int mappedValue = map_f(arr[i]);

      dest[count] = mappedValue;
      count++;
    }
  }
}

int eveneNumber(int a) { return a % 2 == 0; }

int squarePrimeNumber(int a) {
  if (a <= 1) {
    return false;
  }
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}
int powNum(int a) { return a * a; }

int returnNumber(int a)
{
  return a;
}

int countBits(int num) {
  int count = 0;

  if (num < 0) {
    return 0;
  }

  while (num) {
    count += num & 1;
    num >>= 1;
  }
  return count;
}

// Print array
void printArray(int arr[], int size) {
  for (size_t i = 0; i < size; i++) {
    if (arr[i] == '\0') {
      return;
    }
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
 {

  // Input array
  int arr[8] = {1, 2, 3, 4, -1, -2, 11, -100};

  // Output array
  int dest[8];

  // Print even number of elements
  filterAndMap(arr, 8, eveneNumber, returnNumber, dest);
  printArray(dest, 10);
  printf("\n");

  // Print square prime number
  filterAndMap(arr, 8, squarePrimeNumber, powNum, dest);
  printArray(dest, 10);
  printf("\n");

  // Print bits count
  filterAndMap(arr, 8, eveneNumber, countBits, dest);
  printArray(dest, 10);
  printf("\n");
  //We have arra 2 4 -2 -100
  //print bits count for 2 4
  //result  1 1

  

  return 0;
}
