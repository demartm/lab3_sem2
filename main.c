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

int main()
{
    printf("Hello World!\n");
    return 0;
}
