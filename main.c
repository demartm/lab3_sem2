#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char *convertStrToLongBv(char *str, int *cells) {

if(str && cells){

  int len = 0;
  int i = 0;
  int ix = 0;

  len = strlen(str);
  *cells = ((len - 1) / 8) + 1;

  unsigned char *vec = (unsigned char*)calloc((*cells), sizeof(unsigned char));

  for(int i = 0; i < (*cells); i++){
    unsigned char mask = 1;
    for(int j = 0; (j < 8) && (ix < len); j++){

      if(str[ix] != '0'){

        vec[i] |= mask;
      }

    mask = mask << 1;
    ix++;
    }
  }
  return vec;

}

return NULL;
}

int main()
{
    printf("Hello World!\n");
    return 0;
}
