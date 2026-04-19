#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printBV(unsigned char *vec, size_t bits){
if(vec && bits){

  size_t bytes = ((bits - 1) / 8) + 1;
  size_t ix = 0;

  for(size_t i = 0; i < bytes; i++){

    unsigned char mask = 1;

    for(size_t j = 0; j < 8 && (ix < bits); j++){

      if(vec[i] & mask){

        printf("1");
      } else {

        printf("0");
      }

      mask = mask << 1;
      ix++;
    }

  }


}

}

unsigned char *convertStrToLongBv(char *str, int *cells){
if(str && cells){

  size_t len = strlen(str);
  *cells = ((len - 1) / 8) + 1;

  size_t ix = 0;

  unsigned char *vec = (unsigned char*)calloc(len, sizeof(unsigned char));

  if(vec){
    for(size_t i = 0; i < (*cells); i++){

      unsigned char mask = 1;

      for(size_t j = 0; (j < 8) && (ix < len); j++){

        if(str[ix] != '0'){

          vec[i] = vec[i] | mask;
        }

        ix++;
        mask = mask << 1;
      }


    }
return vec;
}

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

unsigned char *convertLongBvToStr(char *vec, size_t bytes){

if(vec && bytes){
  size_t len = bytes * 8;

  size_t ix = 0;
  unsigned char *str = (unsigned char*)calloc(len + 1, sizeof(unsigned char));

  if(str){

    for(size_t i = 0; i < len; i++){
      unsigned char mask = 1;

      for(size_t j = 0; (j < 8) && (ix < len); j ++){

        if(vec[i] & mask){
          str[ix] = '1';
        } else {
          str[ix] = '0';
        }

        ix++;
        mask = mask << 1;
      }

    }
  str[len + 1] = '\0';
  return str;
  }


}
return NULL;

}


int main()
{
    printf("Hello World!\n");
    return 0;
}
