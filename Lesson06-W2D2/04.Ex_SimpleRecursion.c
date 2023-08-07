#include <stdio.h>

//n
//n*(n-1)*(n-2)*(n-3)*(n-4)........*2*1

int factoriel(int n)
{
    if(n==0){
        return 1;
    }
    return n * factoriel(n - 1);
}

int main(int argc, char *argv[]) 
{   
    int n=0;
        scanf("%d", &n);
        printf("%d\n", factoriel(n));

        return 0;
}