#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned char *logMul(unsigned char *vecA, unsigned char *vecB, size_t bitsA, size_t bitsB){

if(vecA && vecB && bitsA && bitsB && (bitsA == bitsB)){


  size_t bytes = ((bitsA - 1) / 8) + 1;

  unsigned char *result = (unsigned char*)calloc(bytes, sizeof(unsigned char));

    if(result){

      for(size_t i = 0; i < bytes; i++){

        result[i] = vecA[i] & vecB[i];
      }
    }
return result;
}
return NULL;
}

unsigned char *logSum(unsigned char *vecA, unsigned char *vecB, size_t bitsA, size_t bitsB){

if(vecA && vecB && bitsA && bitsB && (bitsA == bitsB)){


  size_t bytes = ((bitsA - 1) / 8) + 1;

  unsigned char *result = (unsigned char*)calloc(bytes, sizeof(unsigned char));

    if(result){

      for(size_t i = 0; i < bytes; i++){

        result[i] = vecA[i] | vecB[i];
      }
    }
return result;
}
return NULL;
}

unsigned char *sumMod2(unsigned char *vecA, size_t bitsA, unsigned char *vecB, size_t bitsB){

if(vecA && vecB && bitsA && bitsB && (bitsA == bitsB)){


  size_t bytes = ((bitsA - 1) / 8) + 1;

  unsigned char *result = (unsigned char*)calloc(bytes, sizeof(unsigned char));

    if(result){

      for(size_t i = 0; i < bytes; i++){

        result[i] = vecA[i] ^ vecB[i];
      }
    }
return result;
}
return NULL;
}

int main()
{
    printf("Hello World!\n");
    return 0;
}
