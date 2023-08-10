#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct Product
{
     double old_price;
     double new_price;
     unsigned int id;
     char product_type;
     char product_name[3];
} Product;

Product arr[40];

char *names[] = {"AB", "BC", "CD", "DD", "DA", "AA"};
void init_arr() {
     
    for(size_t i = 0; i < 40; i++) {
        // 1. Числа от 499 до 10045
        // 2. Делим на 100.
        arr[i].old_price = (rand()%(10045 - 499) + 499)/100.;
        arr[i].new_price = (rand()%(10045 - 499) + 499)/100.;
        arr[i].id = i;
        arr[i].product_type = rand()%4 + 'A';
        strcpy(arr[i].product_name, names[rand()%6]);
    }
}
void print_arr() {
    for(size_t i = 0; i < 40; i++) {
        printf("id: %4u, new_p: %7.2f, old_p: %7.2f, type:%2c, name: %3s, price_delta: %f\n", arr[i].id, arr[i].new_price, arr[i].old_price, arr[i].product_type, arr[i].product_name, arr[i].new_price - arr[i].old_price);
    }
    printf("\n");
}
int cmp(const void *a, const void *b) {
    const Product *A = a, *B = b;
    double price_d_a = A->new_price - A->old_price;
    double price_d_b = B->new_price - B->old_price;

    if(fabs(price_d_a - price_d_b) >= 0.01) {
        return (price_d_a - price_d_b)*100;
    } else if(A->product_type != B->product_type) {
        return B->product_type - A->product_type;
    } else if(strcmp(A->product_name, B->product_name)) {
        return strcmp(A->product_name, B->product_name);
    } else {
        return A->id - B->id;
    }
}
int main() {
    init_arr();
    arr[0].new_price = 0;
    arr[0].old_price = 0;
    arr[1].new_price = 0;
    arr[1].old_price = 0;
    arr[2].new_price = 0;
    arr[2].old_price = 0;
    print_arr();
    qsort(arr, 40, sizeof(arr[0]), cmp);
    print_arr();

    FILE *f1 = fopen("output.bin", "w");
    fwrite(arr, sizeof(Product), 40, f1);
    fclose(f1);

    FILE *f2 = fopen("output.bin", "r");
    fread(arr, sizeof(Product), 40, f2);
    fclose(f2);
    return 0;
}