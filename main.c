#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool set_bit(unsigned char *vec, bool bit, size_t k){
if(vec){

  int byte = k / 8;
  int bit = k % 8;
  unsigned char mask = 1;
  // if(!bit){
  //   mask = 0;
  // }

  mask = mask << bit;
  if(bit){
  vec[byte] |= mask;

  } else {
  vec[byte] &= ~mask;
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
