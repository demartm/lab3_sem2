#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
