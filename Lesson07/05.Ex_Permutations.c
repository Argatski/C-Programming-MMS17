#include <stdio.h> 

//Long time to recurse.
// int arr[11]={1,2,3,4,5,6,7,8,9,10,11};

int arr[] = {1, 2, 3,4};

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

//Recursion permutations
void permutations(int begin,int total_count)
{
    //Base case
    if(begin==total_count)
    {
        for(int i=0;i<total_count;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }

    //Recursion case
    for (int i = begin; i < total_count; i++) 
    {
        swap(&arr[begin], &arr[i]);
        permutations(begin + 1, total_count);
        swap(&arr[begin], &arr[i]);
    }
}

int main(int argc, char *argv[]) 
{
    int len = sizeof(arr)/sizeof(arr[0]);
    permutations(0,len);

    return 0;
}


