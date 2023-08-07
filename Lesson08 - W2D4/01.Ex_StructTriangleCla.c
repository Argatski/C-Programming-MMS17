#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Input ./triangle 1.2 3.5 7.8
//stdout - стандартен изход
//stderr - стандартен изход за грешки
//stdin - стандартен вход
//FILE *stdout,* stderr,*stdin

//Function calculate Perimeter and Area
int triangle(double a, double b, double c, double *P, double *A) {
    if(a <= 0 || b <= 0 || c <= 0 || a + b <= c || b + c <= a || c + a <= b) {
        return -1;
    }
    *P = a+b+c;
    double HP = *P/2;
    *A = sqrt(HP*(HP - a)*(HP - b)*(HP - c));
    return 0;
}

//Day 9 - Struct
int main(int argc, char *argv[]) 
{
    if(argc!=4)
    {
      fprintf(stderr, "Invalid number of argumets\n");
       return 1;
    }
    
    double a,b,c;

    // double a =atof(argv[1]),
    //        b =atof(argv[2]),
    //        c =atof(argv[3]);

    //doouble a = strtod(argv[1,NULL]),
            //   b = strtod(argv[2,NULL),
            //   c = strtod(argv[3,NULL]);

    //if (sscanf(argv[1],"%lf",&a)==0 || 
        //sscanf(argv[2],"%lf",&b ==0 ||
        //sscanf(argv[3],"%lf",&c ==0))
    //{

    int argv_len = strlen(argv[1]),
        argv_len1 = strlen(argv[2]),
        argv_len2 = strlen(argv[3]);

    char buf[argv_len + argv_len1 + argv_len + 2 + 1];
    strcpy(buf, argv[1]);
    buf[argv_len] = ' ';
    strcpy(buf + argv_len + 1, argv[2]);
    buf[argv_len + argv_len1 + 1] = ' ';
    strcpy(buf + argv_len + argv_len1 + 2, argv[3]);
    

    //strcat вместо strcpy
    if (sscanf(buf,"%lf %lf %lf",&a,&b,&c)!=3)
    {
        fprintf(stderr,"Incalid CLA\n");
        return 1;
    }
    
    printf("%lf %lf %lf\n",a,b,c);
    double P,A;

    if (triangle(a, b, c, &P, &A))
    {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }
    else {
    fprintf(stdout,"AREA %lf Perimeter: %lf\n",A,P);
    }

    return 0;
}

