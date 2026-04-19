#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool invert_vec(unsigned char* vec, size_t len){
if(vec){

size_t tail_len = 8 - (len % 8);
unsigned char ones = 0;
ones = ~ones;
ones = ones >> tail_len;

  unsigned char mask = 0;//255;
  mask = ~mask;

  for (int i = 0; i < (len+7)/8; i++){

    vec[i] ^= mask;
  }
  if((len % 8) != 0){

    vec[len/8] &= ones;
  }
    return true;

}

return false;
}

int main()
{
    printf("Hello World!\n");
    return 0;
}
