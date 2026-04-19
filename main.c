#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void shiftRight(unsigned char *vec, size_t bits, size_t k){

if(vec && bits && k){

  size_t bytes = ((bits - 1) / 8) + 1;

  size_t tail_len = 8 - (bits % 8);
  unsigned char ones = 0;
  ones = ~ones;
  ones = ones >> tail_len;

  for(size_t i = bytes; i > 0; i--){
    unsigned char mask = 0;

    vec[i] = vec[i] << k;

    mask = vec[i - 1];
    mask = mask >> (8 - k);
    vec[i] = vec[i] | mask;
  }

  vec[0] = vec[0] << k;

  vec[bytes - 1] = vec[bytes - 1] & ones;
}

}

void shiftLeft(unsigned char *vec, size_t bits, size_t k){

if(vec && bits && k){

  size_t bytes = ((bits - 1) / 8) + 1;

  size_t tail_len = 8 - (bits % 8);
  unsigned char ones = 0;
  ones = ~ones;
  ones = ones << tail_len;

  for(size_t i = 0; i < (bytes - 1); i++){
    unsigned char mask = 0;

    vec[i] = vec[i] >> k;

    mask = vec[i + 1];
    mask = mask << (8 - k);
    vec[i] = vec[i] | mask;
  }

  vec[bytes - 1] = vec[bytes - 1] >> k;
}

}

int main()
{
    printf("Hello World!\n");
    return 0;
}
