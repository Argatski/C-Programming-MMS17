
#include<stdio.h>
// Напишете функция, която намира стойността на максималния елемент в масив и неговия адрес в паметта
// Като резултат се предава максималната стойност чрез указател и адреса на максималната стойност чрез указател.
void find_max_ptr(int arr[], size_t n, int *max_elem, int **max_ptr) {
    printf("Address of int* max_ptr from main: %p\n", max_ptr);
    printf("Address of int int_var from main: %p\n", *max_ptr);
    printf("Value of int int_var from main: %d\n", **max_ptr);
    for(size_t i = 1; i < n; i++) {
        if(arr[i] > *max_elem) {
            *max_elem = arr[i];
            *max_ptr = arr + i;
        }
    }
}
int main() {
    int arr[] = {1,2, -5, 100, 12, 3};
    int int_var = 100;
    int *max_ptr = &int_var;
    int max_elem;
    find_max_ptr(arr, 6, &max_elem, &max_ptr);
    printf("MAX VALUE: %d\n", max_elem);
    printf("MAX VALUE address: %p\n", max_ptr);
    printf("MAX VALUE address: %d\n", *max_ptr);
}