#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) 
{
    //Get count of argv
    int count =0;
    while (argv[++count]!=NULL);

    double sum=0;

    //Lenght of size argv
    
    for (int i = 1; i < count ; i++)
    {
        sum += atof(argv[i]);
    }

    //Print sum
    printf("Sum: %.2lf\n", sum);


    return 0;
}

/* //Another solution
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[]) {
    double sum = 0;
    for(size_t i = 1; i < argc; i++) {
        if(strstr(argv[i], ".")) {
            double curNum;
            sscanf(argv[i], "%lf", &curNum);
            sum += curNum;
        } else if(argv[i][0] == '0' && (argv[i][1] == 'x' || argv[i][1] == 'X')) {
            int curNum;
            sscanf(argv[i], "%x", &curNum);
            sum += curNum;
        } else {
            int curNum;
            sscanf(argv[i], "%d", &curNum);
            sum += curNum;
        }
    }
    printf("%lf\n", sum);
    sum = 0;
    for(size_t i = 1; i < argc; i++) {
        sum += atof(argv[i]);
    }
    printf("%lf\n", sum);
    return 0;
} 
 */