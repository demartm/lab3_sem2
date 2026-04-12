#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char *convertLongBvToStr(unsigned char *vec, size_t sz){
if(vec){

  int len = 8 * sz + 1;
  unsigned char *str = (unsigned char*)calloc(len, sizeof(unsigned char));

  if(str){

  int ix = 0;

    for(int i = 0; i < len; i++){
      unsigned char mask = 1;

      for(int j = 0; (j < 8) && (ix < len); j++){

        if(vec[i] & mask){

          str[ix] = '1';
        } else {

          str[ix] = '0';
        }

        mask = mask << 1;
        ix++;

    }

  }

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
