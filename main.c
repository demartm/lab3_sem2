#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void set1(unsigned char *vec, size_t bits, size_t bit){

if(vec && bits && bit && (bits >= bit)){

  int byte = bit / 8;
  int k = bit % 8;
  unsigned char mask = 1;

  mask = mask << k;

  vec[byte] = vec[byte] | mask;

}

}

void set0(unsigned char *vec, size_t bits, size_t bit){

if(vec && bits && bit && (bits >= bit)){

  int byte = bit / 8;
  int k = bit % 8;
  unsigned char mask = 1;

  mask = mask << k;

  vec[byte] = vec[byte] & (~mask);

}

}

int main()
{
    printf("Hello World!\n");
    return 0;
}
