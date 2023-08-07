#include <stddef.h>
#include <stdio.h>


//Day 07
//Add funciton
int add(int a,int b)
{
    return a+b;
}

//Multiply
int mult(int a,int b)
{
    return a*b;
}

//Aggregate
int aggregate(int*arr,int n,int init,int(*f)(int,int));

//Square array index
int addSquare(int sum,int a)
{
    return sum+=a*a;
}

//Agragete
int main(int argc, char *argv[]) 
{
    int arr[6];
    //Input array
    // int arr[]={1,2,3,4,5,6};

    //Read array from console
    int s =  sizeof(arr)/sizeof(arr[0]);
    for(size_t i = 0; i<s;i++)
    {
        scanf("%d",&arr[i]);
    }

    //((((15+1)+2)+3)+4)+5
    printf( "%d\n", aggregate(arr,5,15,add));

    //((((9*)*)2*)3*)4)*5
    printf( "%d\n", aggregate(arr,5,9,mult));
    return 0;

    //Suqrae
    printf("%d\n",aggregate(arr, 5,0,addSquare));
}


//Aggragate
int aggregate(int*arr,int n,int init,int(*f)(int,int))
{
    int result=init;

    for(int i=0;i<n;i++)
    {
        result=f(result,arr[i]);
    }

    return result;
}