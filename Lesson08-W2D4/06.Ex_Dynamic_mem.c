#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mallocHelloStr()
{
  char *p = malloc(6*sizeof(char));

  strcpy(p, "Hello");

  return p;
}


char* brokenHelloStr()
{
  char str[]= "Hello"; //Segmentation fault(core dump)
  return str;
}


int main(int argc, char *argv[]) 
{
  double *p = malloc(sizeof(double));//zadelqne na pamet v adresa *p

    *p = 13.0;

    printf("%f\n", *p);//printirane na stoinosta na *p

  free(p);// pochistvane na pamet

  char *str1=mallocHelloStr();//Hello 
  printf("%s\n", str1);//Hello 

  char *str2=brokenHelloStr();//Segment fault(core dump)
  printf("%s\n", str2);//Segment fault(core dump)

  free(str1);//Free space

  return 0;
}