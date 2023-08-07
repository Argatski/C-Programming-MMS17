#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Point {
  double x;
  double y;
  double z;
} Point;

int distPoint(const void *a,const void *b)
{
  Point *pointA=(Point*) a;
  Point *pointB=(Point*) b;

  double distA = (pointA->x *pointA->x + pointA->y *pointA->y +pointA->z *pointA->z*pointA->z);
  double distB = (pointB->x *pointB->x + pointB->y *pointB->y +pointB->z *pointB->z*pointB->z);

  return (distA > distB)-(distA < distB);
}


typedef struct Human {
  double weightKg;
  double heightCm;
} Human;

int distHuman(const void *a,const void *b)
{
  Human *humanA=(Human*) a;
  Human *humanB=(Human*) b;

  double distA = (humanA->weightKg *humanA->weightKg + humanA->heightCm *humanA->heightCm*humanA->heightCm);
  double distB = (humanB->weightKg *humanB->weightKg + humanB->heightCm *humanB->heightCm*humanB->heightCm);

  return (distA > distB)-(distA < distB);
}


void *findMax(void *arr, size_t n, size_t elem,
              int (*cmp)(const void *, const void *)) {
  void *max = arr;
  for (size_t i = 0; i < n; i++) {
    if (cmp(max, arr + i * elem) < 0) {
      max = arr + i * elem;
    }
  }
  return max;
}


int cmpInt(const void *a, const void *b) {
  return *(int *)a > *(int *)b ? 1 : -1;
}

int main() {
  //За да намерите най-големия елемент в масив от тип uint64_t.
  // Find the biggest element in array uint64_t;

  uint64_t arr[] = {1,  2,  3,  4,  200,  6,  7,  8};

   size_t len = sizeof(arr)/sizeof(arr[0]);
  uint64_t *max = findMax(arr, len, sizeof(uint64_t), cmpInt);
  printf("The biggest element in array uint64_t is %lu\n", *max);


  //За да намерите точката, която е на най-голямо (евклидово) разстояние от (0, 0, 0) в масив от тип Point. 
  //Array of pointers

  Point points [] = {{1, 2, 3}, {-4, 5, -6}, {7, -8, 9}};

  int lenP = sizeof(points)/sizeof(points[0]);

  Point *maxPoint = findMax(points, lenP, sizeof(Point), distPoint);

  //Pirnt point of maximum distance
  printf("The point of maximum distance is (%.2f, %.2f, %.2f)\n", maxPoint->x, maxPoint->y, maxPoint->z);


  //За да намерите човека с най-нисък Body Mass Index в масив от тип Human.
  Human people []={[0]={.weightKg=50, .heightCm=150},[1]={.weightKg=50, .heightCm=170},[2]={.weightKg=50, .heightCm=180}};

  int lenH = sizeof(people)/sizeof(people[0]);

  Human *maxHuman = findMax(people, lenH, sizeof(Human), cmpInt);

  //Print human with littel body mass index
  printf("The human with littel body mass index is (%.2f, %.2f)\n", maxHuman->weightKg, maxHuman->heightCm);

  return 0;
}