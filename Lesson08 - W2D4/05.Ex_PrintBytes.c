#include <limits.h>
#include <stdio.h>
#include <string.h>

typedef struct A {
  unsigned char b;
  unsigned int a;

} A;

void printBytes(const void *p, int numBytes) {
  unsigned char buf[numBytes];

  memcpy(buf, p, numBytes);

  for (size_t i = 0; i < numBytes; i++) 
  {
    printf("%02x ", buf[i]);
  }
  printf("\n");
}

int main()
{
  A a = {254, UINT_MAX - 1};
  //&a; //(A*)
  //UINT_MAX        0xff ff ff ff
  //UINT_MAX - 1    0xff ff ff fe

  printBytes(&a,sizeof(A));

  return 0;
}

//0xAB CD
//Little endian
//----------->
//CD AB
//0x0000000000000000F1  0x0000000000000000F2


//Big endian
//----------->
//AB CD
//0x0000000000000000F1 0x0000000000000000F

