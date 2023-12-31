#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<string.h>
typedef struct Car {
    char model[20];
    uint8_t maxspeed;
    double price;
} Car;

Car cars[10];

// a b c d e f .... z   A  B  C  D  E. .... Z  4  5  6  7  8  9  
// 0 1 2 3 4 5      25  26 27 28 29 30      51 52 53 54 55 56 57      j
void gen_random_str(char *str) {
    size_t n = 1 + rand()%19; // 1,2,3,4....19
    for(size_t i = 0; i < n; i++) {
        size_t j = rand()%58;
        if(j <= 25) {
            str[i] = j + 'a';
        } else if(j <= 51) {
            str[i] = j - 26 + 'A';
        } else {
            str[i] = j - 52 + '4';
        }
    }
    str[n] = '\0';
}
void init_cars() {
    for(size_t i = 0; i < 10; i++) {
        gen_random_str(cars[i].model);
        cars[i].maxspeed = rand()%256;
        // 1. случайно число от 100000 до 10000000
        // 2. разделям полученото нецелочислено на 100.
        cars[i].price = (rand()%(10000000 - 100000) + 100000)/100.;
    }
}
void print_cars() {
    for(size_t i = 0; i <10; i++) {
        printf("CAR NUMBER %3ld, MODEL: %20s, MAXSPEED: %3u, PRICE: %10f\n", i, cars[i].model, cars[i].maxspeed, cars[i].price);
    }
    return ;
}
int cmp_model(const void *a, const void *b) {
    return strcmp(((const Car *)a)->model, ((const Car *)b)->model);
}
int cmp_model_desc(const void *a, const void *b) {
    return cmp_model(b,a);
}
int cmp_max_speed(const void *a, const void *b) {
    return ((const Car *)a)->maxspeed - ((const Car *)b)->maxspeed;
}
int cmp_max_speed_desc(const void *a, const void *b) {
    return -cmp_max_speed(a,b);
}
int cmp_price(const void *a, const void *b) {
    return (((const Car *)a)->price - ((const Car *)b)->price)*100;
}
int cmp_price_desc(const void *a, const void *b) {
    return cmp_price(b,a);
}
int (*getComparator(int n))(const void*, const void*) {
    int (*comp_arr[6])(const void*, const void*) = {cmp_model, cmp_model_desc, cmp_max_speed, cmp_max_speed_desc, cmp_price, cmp_price_desc};
    return comp_arr[n];
}
int main() {
    init_cars();
    print_cars();

    int n;
    printf("Set comparator number [0-5] : ");
    scanf("%d", &n);
    qsort(cars, 10, sizeof(Car), getComparator(n));
    print_cars();

    return 0;
}