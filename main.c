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
  if(len == 0){
    return NULL;
  }
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
}
return NULL;
}
unsigned char *convertLongBvToStr(char *vec, size_t len){

if(vec && len){
  //size_t len = bytes * 8;

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

void inversion(unsigned char *vec, size_t len){//bool invert_vec(unsigned char* vec, size_t len){
if(vec && len){

size_t tail_len = 8 - (len % 8);
unsigned char ones = 0;
ones = ~ones;
ones = ones >> tail_len;

  unsigned char mask = 0;//255;
  mask = ~mask;

  for (int i = 0; i < ((len - 1) / 8) + 1; i++){

    vec[i] ^= mask;
  }
  if((len % 8) != 0){

    vec[len/8] &= ones;
  }

}

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

void shiftRight(unsigned char *vec, size_t bits, size_t k){

if(vec && bits && k){

  size_t bytes = ((bits - 1) / 8) + 1;

  size_t tail_len = 8 - (bits % 8);
  unsigned char ones = 0;
  ones = ~ones;
  ones = ones >> tail_len;

  for(size_t i = (bytes - 1); i > 0; i--){
    unsigned char mask = 0;

    vec[i] = vec[i] << k;

    mask = vec[i - 1];
    mask = mask >> (8 - k);
    vec[i] = vec[i] | mask;
  }

  vec[0] = vec[0] << k;
 if(bits % 8){
  vec[bytes - 1] = vec[bytes - 1] & ones;
}
}

}

void shiftLeft(unsigned char *vec, size_t bits, size_t k){

if(vec && bits && k){

  size_t bytes = ((bits - 1) / 8) + 1;

  // size_t tail_len = 8 - (bits % 8);
  // unsigned char ones = 0;
  // ones = ~ones;
  // ones = ones << tail_len;

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
int cells = 0;
// unsigned char test[6] = "100001";
// unsigned char *bv = convertStrToLongBv(test,&cells);
// printBV(bv,6);
//"100001"

unsigned char test[16] = "1000111010110101";
unsigned char *bv = convertStrToLongBv(test,&cells);
// printBV(bv,16);
//1000111010110101111

// unsigned char test[4] = "10110";
// unsigned char *bv = convertStrToLongBv(test,&cells);
// printf("%d",bv[0]);
// return 0;

// unsigned char test[16] = "0000000000000000";
// unsigned char *bv = convertStrToLongBv(test,&cells);
//0000000000000000

// unsigned char test[] = "00111000011011100001101110000010001110110100111011010011101110011100001101110000110111000001000111011010011101101001110111";
// unsigned char *bv = convertStrToLongBv(test,&cells);
// printBV(bv,122);
//00111000011011100001101110000010001110110100111011010011101110011100001101110000110111000001000111011010011101101001110111

// unsigned char test[13] = "text000test00";
// unsigned char *bv = convertStrToLongBv(test,&cells);
// printBV(bv,13);
//1111000111100

// unsigned char test[13] = "1";
// unsigned char *bv = convertStrToLongBv(test,&cells);
// printBV(bv,1);
//1

//unsigned char test[16] = "";
//unsigned char *bv = convertStrToLongBv(test,&cells);
//error converting str

//unsigned char *bv = convertStrToLongBv(test,NULL);
//error converting str

// unsigned char *bv = convertStrToLongBv(NULL,&cells);
//error converting str

//unsigned char *bv = convertStrToLongBv(NULL,NULL);
//error converting str

if(!bv){
  printf("error converting str");
  return 0;
}
printBV(bv,16);
free(bv);
bv = NULL;

printf("\n\n-----------------------------------\nConverting and re-converting:\n\n");

// unsigned char test2[] = "1000111100111110";
// size_t bits = 16;
// 1000111100111110
// 1000111100111110

// unsigned char test2[] = "10001111001111100101";
// size_t bits = 20;
// 10001111001111100101
// 10001111001111100101

unsigned char test2[] = "00111000011011100001101110000010001110110100111011010011101110011100001101110000110111000001000111011010011101101001110111";
size_t bits = 122;

// 00111000011011100001101110000010001110110100111011010011101110011100001101110000110111000001000111011010011101101001110111
// 00111000011011100001101110000010001110110100111011010011101110011100001101110000110111000001000111011010011101101001110111

// unsigned char test2[] = "1";
// size_t bits = 20;
// 10000000000000000000
// 10000000000000000000

// unsigned char test2[] = "1";
// size_t bits = 1;
//1
//1


unsigned char *test_conv = convertStrToLongBv(test2,&cells);
// unsigned char *test_conv = convertStrToLongBv(NULL,&cells);
//error converting

// unsigned char *test_conv = convertStrToLongBv(test2,NULL);
//error converting

// unsigned char *test_conv = convertStrToLongBv(NULL,NULL);
//error converting

if(!test_conv){
  printf("error converting");
  return 0;
}
printBV(test_conv,bits);
unsigned char *test_reconv = convertLongBvToStr(test_conv,bits);

// unsigned char *test_reconv = convertLongBvToStr(NULL,bits);
//error reconverting

// unsigned char *test_reconv = convertLongBvToStr(test_conv,0);
//error reconverting

// unsigned char *test_reconv = convertLongBvToStr(NULL,0);
//error reconverting


if(!test_reconv){
  printf("\nerror reconverting");
  free(test_conv);
  return 0;
}
printf("\n%s",test_reconv);

free(test_conv);
test_conv = NULL;
free(test_reconv);
test_reconv = NULL;

printf("\n\n-----------------------------------\nSum Mod2:\n\n");

// unsigned char test3_1[] = "1000101101";
// unsigned char test3_2[] = "1111101110";
// size_t bits3 = 10;
/*
1000101101
1111101110
0111000011*/

// unsigned char test3_1[] = "1";
// unsigned char test3_2[] = "1";
// size_t bits3 = 1;
/*1
1
0*/

unsigned char test3_1[] = "1100010110110001011011000101101100010110110001011011000101101";
unsigned char test3_2[] = "1111110111011111011101111101100100101101100010110110001011010";
size_t bits3 = 61;
/*1100010110110001011011000101101100010110110001011011000101101
1111110111011111011101111101100100101101100010110110001011010
0011100001101110000110111000001000111011010011101101001110111*/

// size_t bits3 = 0;
//error sumMod2

unsigned char *vec3_1 = convertStrToLongBv(test3_1,&cells);
if(!vec3_1){
  printf("error converting");
  return 0;
}

printBV(vec3_1,bits3);
printf("\n");

unsigned char *vec3_2 = convertStrToLongBv(test3_2,&cells);
if(!vec3_2){
  printf("error converting");
  free(vec3_1);
  return 0;
}

printBV(vec3_2,bits3);
printf("\n");

unsigned char *vec3_3= sumMod2(vec3_1,bits3, vec3_2,bits3);

// unsigned char *vec3_3= sumMod2(NULL,bits3, vec3_2,bits3);
// //error sumMod2

// unsigned char *vec3_3= sumMod2(vec3_1,bits3, NULL,bits3);
// //error sumMod2

// unsigned char *vec3_3= sumMod2(NULL,bits3, NULL,bits3);
//error sumMod2

// unsigned char *vec3_3= sumMod2(vec3_1,bits3 + 1, vec3_2,bits3);
//error sumMod2

//unsigned char *vec3_3= sumMod2(vec3_1,bits3, vec3_2,bits3 + 1);
// //error sumMod2

if(!vec3_3){
  printf("error sumMod2");
  free(vec3_1);
  free(vec3_2);
  return 0;
}
printBV(vec3_3,bits3);
free(vec3_1);
vec3_1 = NULL;
free(vec3_2);
vec3_2 = NULL;
free(vec3_3);
vec3_3 = NULL;

printf("\n\n-----------------------------------\nInversion:\n\n");
unsigned char test4[] = "1000111010110011";
size_t bits4 = 16;
/*1000111010110011
0111000101001100*/


// unsigned char test4[] = "1111111111111111";
// size_t bits4 = 16;
/*1111111111111111
0000000000000000*/

// unsigned char test4[] = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
// size_t bits4 = 128;
/*11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000*/

// unsigned char test4[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
// size_t bits4 = 128;
/*00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111*/

// unsigned char test4[] = "1";
// size_t bits4 = 1;
// 1
// 0

// unsigned char test4[] = "";
// size_t bits4 = 1;
//error converting

// unsigned char test4[] = "1010101";
// size_t bits4 = 0;
//(нет вывода)

unsigned char *vec4 = convertStrToLongBv(test4,&cells);

if(!vec4){
  printf("error converting");
  return 0;
}

printBV(vec4,bits4);
printf("\n");

inversion(vec4,bits4);
//inversion(NULL,bits4);

printBV(vec4,bits4);
free(vec4);
vec4 = NULL;


printf("\n\n-----------------------------------\nShift right:\n\n");
unsigned char test5[] = "100011101011001";
size_t bits5 = 15;
size_t k = 2;
unsigned char *vec5 = convertStrToLongBv(test5,&cells);
if(!vec5){
  printf("error converting");
  return 0;
}

printBV(vec5,bits5+5);
printf("\n");

shiftRight(vec5,bits,k);

printBV(vec5,bits5+5);

printf("\nShift back:\n");


shiftLeft(vec5,bits,k);
printBV(vec5,bits5+5);

return 0;
}
