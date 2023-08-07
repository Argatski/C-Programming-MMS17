#include <inttypes.h>
#include <stdio.h>

void print_row(int (*arr)[4]) {
  for (size_t i = 0; i < 4; i++) {
    printf("%d ", (*arr)[i]);
  }
  printf("\n");
}
void print_row_2(int *p) {
  for (size_t i = 0; i < 4; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
}
void print_2d_arr(int arr[3][4]) {
  // int (*p)[4]
  for (size_t i = 0; i < 3; i++) {
    print_row(arr + i);
    print_row_2(arr[i]);
  }
}

void print_2d_arr_2(int arr[][4], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}
void print_2d_arr_3(int *arr, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", arr[i * m + j]);
    }
    printf("\n");
  }
}
int main() {
  int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  // sizeof(arr) == 3*4*sizeof(int)
  // 1 2 3 4 5 6 7 8 9 10 11 12

  int *p = arr[0];
  for (size_t i = 0; i < 3 * 4; i++) {
    printf("%d ", p[i]);
    // p[i]
    // *(p+i)
  }
  printf("\nPrint row first method: \n");

  print_row(arr);

  printf("\n");

  print_2d_arr(arr);

  printf("\n");

  print_2d_arr_2(arr, 3);

  printf("\n");

  print_2d_arr_3(arr[0], 3, 4);

  return 0;
}