#include <inttypes.h>
#include <stdio.h>
#include <unistd.h>
#define flip_bits(X, i) X = X ^ (1ULL << i)

// flip_bit(255, 4)
// 1ULL << 4
// 00010000
//
// 255 = 11111111
//
// 11111111
// ^
// 00010000
// 11101111

// flip_bit(0, 4)
// 0 = 00000000
// 00000000
// ^
// 00010000
// 00010000

// uint8_t X
// ^
// 10101010
// същото като да извикаме
// flip_bits(X, 1)
// flip_bits(X, 3)
// flip_bits(X, 5)
// flip_bits(X, 7)

// 11111111
// ^
// 10101010
// =
// 01010101

void flip_odd_bits(uint8_t *mask) {
  // *mask ^= 0b10101010; // solution 1

  // solution 2
  for(size_t i = 0; i < 8; i++) 
  {
    if(i%2==1)
    {
        flip_bits(*mask, i);
    }
  }
}

int main()
{
    uint8_t A = 255;
    flip_odd_bits(&A);
    printf("%u\n", A);
    return 0;
}