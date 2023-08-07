#include <stdio.h>

//Направете извикване на myMap ,което въвежда всички ел. на arr от конзолата.
//Направете извикване на myMap ,което изпечатва.
//Направете извикване на myMap, което повдига всеки ел. на на квадрат.

//Read all element fro console.
void myMap(int arr[],int n, int (*f)(int));

int addOne(int a);
int scanEl(int a);
int square(int a);
int printEl(int a);

int main(int argc, char *argv[]) 
{
    //Array
    int arr[100];
    myMap(arr, 5,scanEl);//Read all element fro console.

    printf("Original array:\n");
    myMap(arr, 5,printEl);
    printf("\n");


    printf("Add one on every index in array:\n");

    myMap(arr,5 , addOne);
    myMap(arr, 5,printEl);
    printf("\n");

    //Suqare all elements in array
    printf("Suqare all elements in array:\n");
    myMap(arr, 3,square);
    myMap(arr, 5,printEl);
    printf("\n");

    return 0;

}

//Add one
int addOne(int a)
{
    return a+1;
}

int scanEl(int a)
{
    int temp;
    scanf("%d\n",&temp);

    return temp;
}

int square(int a)
{
    return a*a;
}

//Print element
int printEl(int el)
{
    printf("%d ",el);


    return el;
}


void myMap(int arr[],int n, int (*f)(int))
{
    //sizeof(arr)== sizeof(int*);
    for (size_t i = 0; i < n; i++) 
    {
      arr[i] = f(arr[i]);
    }
}