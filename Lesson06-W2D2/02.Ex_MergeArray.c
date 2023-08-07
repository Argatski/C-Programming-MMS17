#include <complex.h>
#include <stddef.h>
#include <stdio.h>

//arr1 i arr2 sortirane za merge
//arr1 i arr2 se sliwat i rezultata se zapisva v dest
//arr1: 1 5 8
//            ^
//arr2: 3 7 10 14
//           ^
//dest: 1    
 void Merge(int *arr1,int n1,int *arr2,int n2,int *dest);

 int main(int argc, char *argv[]) 
 {

   // //Input Array1 and Array2
   
   int arr1[] = {1,5,8,8};
   int arr2[] = {3,7,10,14,16,20,};

   // Lenght Array
    int n1 = sizeof(arr1)/sizeof((arr1[0]));
   int n2 =sizeof(arr2)/sizeof((arr2[0]));


   // Destination Array
   int dest[n1 + n2];

   // Merge
   Merge(arr1, n1, arr2, n2, dest);

   // Print
   for (int i = 0; i < n1 + n2; i++) {
     printf("%d ", dest[i]);
   }

   printf("\n");
   return 0;
 }

void Merge(int *arr1,int n1,int *arr2,int n2,int *dest)
{
    int i1 = 0;
    int i2 = 0;

    while(i1<n1&&i2<n2)
    {
       if (arr1[i1]<arr2[i2])
       {
        *(dest++) = arr1[i1];
           i1++;
       }
       else 
       {
        *(dest++) = arr2[i2];
           i2++;
       }
    
    }
    if (i1<n1)
    {
            for (size_t i=i1; i<n1; i++)    
            {
            *(dest++) = arr1[i];
            }
    } 
    else 
    {
            for (size_t i=i2; i<n2; i++) 
            {
            *(dest++) = arr2[i];
            }
    }

}
