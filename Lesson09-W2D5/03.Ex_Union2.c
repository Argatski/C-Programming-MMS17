#include<stdio.h>

struct Point3d{
    double x;
    double y;
    double z;
}P1;

struct A{
    char a;//1byte
    //3 bytes padding
    int b;// 4byte

}A;

struct B{
    int a;// 4byte
    char b;// 1byte
    //3 bytes padding
}B;

typedef union C{
    int a;// 4byte
    float b;// 4 byte
    char c;// 1byte
}C;


int main(int argc, char *argv[]) 
{
   //Size of point P1 
   printf("Struct P1 get %lu bites\n",sizeof(P1));

   //Size of struct A 
   printf("Struct A get %lu bites\n",sizeof(A)); 

   //Size of struct B    
   printf("Struct B get %lu bites\n",sizeof(B)); 
   
   //Size of union C    
   printf("Union C get %lu bies\n",sizeof(C));     

}