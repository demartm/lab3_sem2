#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Реализовать все предложенные операции для булева вектора произвольной длины.

Способ представление булева вектора в памяти обсуждалось на занятии. Уметь его рассказать.

Продемонстрировать работу всех операций.

Во многих функциях представлены следующие входные аргументы.

 usigned char *vecA – указатель на массив;

 size_t bits – длина булева вектора(количество разрядов);

Во многих функциях передается именно длина вектора, а не количество ячеек. Количество ячеек, для организации цикла,

можно определять непосредственно в функции по известной вам формуле.

bytes  =  ((bits- 1) / 8) + 1;//вычисление количества ячеек булева вектора(количества байт необходимы для хранения булева вектора длины bits)

 1. Логическое умножение;

unsigned char * logMul(unsigned char *vecA, size_t bitsA, unsigned char *vecB, size_t bitsB);

2. Логическое сложение;

unsigned char * logSum(unsigned char *vecA, size_t bitsA, unsigned char *vecB, size_t bitsB);

3. Сумма по модулю 2;

unsigned char * sumMod2(unsignedchar *vecA, size_t bitsA, unsigned char *vecB, size_t bitsB);

 4. Инверсия;

void inversion(unsigned char *vec, size_t bits);

5. Сдвиг влево на K разрядов;

void shiftLeft(unsigned char *vec, size_t bits, size_t k);

6. Сдвиг вправо на K разрядов;

void shiftRight(unsigned char *vec, size_t bits, size_t k);

 7. Установка/сброс К-ого разряда;

void set1(unsigned char *vec, size_t bits, size_t bit);

void set0(unsigned char *vec, size_t bits, size_t bit);

8. Функция конвертации строки в булев вектор;

9. Функция конвертации булева вектора в строку;

10.Функция печати булева вектора на консоль;*/

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

if(vec && bits && (bits >= bit)){

  int byte = bit / 8;
  int k = bit % 8;
  unsigned char mask = 1;

  mask = mask << k;

  vec[byte] = vec[byte] | mask;

}

}

void set0(unsigned char *vec, size_t bits, size_t bit){
if(vec && bits && (bits >= bit)){

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
  size_t byte_k = k / 8;
  k = k % 8;

  size_t tail_len = 8 - (bits % 8);
  unsigned char ones = 0;
  ones = ~ones;
  ones = ones >> tail_len;

  for(size_t i = (bytes - 1); i > 0; i--){
    unsigned char mask = 0;
  size_t addr = i - byte_k;

  if(addr < bytes){

    vec[i] = vec[addr] << k;

    if(k){
    mask = vec[addr - 1];
    mask = mask >> (8 - k);
    vec[i] = vec[i] | mask;
  }
  } else {

  vec[i] = 0;
  }
    //vec[i] = vec[i] << k;



  }

  if(byte_k == 0){

    vec[0] = vec[0] << k;
  } else {

    vec[0]=0;
  }
 if(bits % 8){
  vec[bytes - 1] = vec[bytes - 1] & ones;
}
}

}

void shiftLeft(unsigned char *vec, size_t bits, size_t k){

if(vec && bits && k){

  size_t bytes = ((bits - 1) / 8) + 1;
  size_t byte_k = k / 8;
  k = k % 8;

  // size_t tail_len = 8 - (bits % 8);
  // unsigned char ones = 0;
  // ones = ~ones;
  // ones = ones >> tail_len;

  for(size_t i = 0; i < (bytes - 1); i++){
    unsigned char mask = 0;
  size_t addr = i + byte_k;

  if(addr < bytes){

    vec[i] = vec[addr] >> k;
    //vec[i] = vec[i] << k;

  if(k && (addr + 1) < bytes){
    mask = vec[addr + 1];
    mask = mask << (8 - k);
    vec[i] = vec[i] | mask;
  }

  } else {

  vec[i] = 0;
  }
  }

  if(byte_k == 0){

    vec[bytes - 1] = vec[bytes - 1] >> k;
  } else {

    vec[bytes - 1]=0;
  }
//  if(bits % 8){
//   vec[bytes - 1] = vec[bytes - 1] & ones;
// }
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
// unsigned char test5[] = "1111111111111111";
// size_t bits5 = 16;
// size_t k = 9;
/*111111111111111100000
000000000111111100000
Shift back:
111111100000000000000*/

unsigned char test5[] = "0011100001101110000110111000001000111011010011101101001110111";
size_t bits5 = 61;
size_t k = 20;
/*001110000110111000011011100000100011101101001110110100111011100000
000000000000000000000011100001101110000110111000001000111011000000
Shift back:
001110000110111000011011100000100011101100000000000000000000000000*/

// unsigned char test5[] = "0011100001101110000110111000001000111011010011101101001110111";
// size_t bits5 = 61;
// size_t k = 0;
/*001110000110111000011011100000100011101101001110110100111011100000
001110000110111000011011100000100011101101001110110100111011100000
Shift back:
001110000110111000011011100000100011101101001110110100111011100000*/

unsigned char *vec5 = convertStrToLongBv(test5,&cells);
if(!vec5){
  printf("error converting");
  return 0;
}

printBV(vec5,bits5+5);
printf("\n");

shiftRight(vec5,bits5,k);

printBV(vec5,bits5+5);

printf("\nShift back:\n");


shiftLeft(vec5,bits5,k);
printBV(vec5,bits5+5);
free(vec5);
vec5 = NULL;
printf("\n\n-----------------------------------\nShift left:\n\n");

// unsigned char test6[] = "100";
// size_t bits6 = 3;
// size_t k2 = 3;
/*10000000
00000000
Shift back:
00000000*/

unsigned char test6[] = "0011100001101110000110111000001000111011010011101101001110111";
size_t bits6 = 61;
size_t k2 = 30;
/*001110000110111000011011100000100011101101001110110100111011100000
100011101101001110110100111011100000000000000000000000000000000000
Shift back:
000000000000000000000000000000100011101101001110110100111011100000*/

// unsigned char test6[] = "1111111111111111";
// size_t bits6 = 16;
// size_t k2 = 9;
/*111111111111111100000
111111100000000000000
Shift back:
000000000111111100000*/
unsigned char *vec6 = convertStrToLongBv(test6,&cells);
if(!vec6){
  printf("error converting");
  return 0;
}

printBV(vec6,bits6+5);
printf("\n");

shiftLeft(vec6,bits6,k2);

printBV(vec6,bits6+5);

printf("\nShift back:\n");


shiftRight(vec6,bits6,k2);
printBV(vec6,bits6+5);
free(vec6);
vec6 = NULL;


printf("\n\n-----------------------------------\nSet1 / set0:\n\n");

// unsigned char test7[] = "0011100001101110000110111000001000111011010011101101001110111";
// size_t bits7 = 61;
// size_t k3 = 0;
/*0011100001101110000110111000001000111011010011101101001110111
1011100001101110000110111000001000111011010011101101001110111
1011100001101110000110111000001000111011010011101101001110111*/

// unsigned char test7[] = "10011101";
// size_t bits7 = 8;
// size_t k3 = 2;
/*10011101
10111101
10101101*/

unsigned char test7[] = "11111111";
size_t bits7 = 8;
size_t k3 = 2;

/*11111111
11111111
11101111*/

unsigned char *vec7 = convertStrToLongBv(test7,&cells);
if(!vec7){
  printf("error converting");
  return 0;
}
printBV(vec7,bits7);
printf("\n");
set1(vec7,bits7,k3);
printBV(vec7,bits7);
printf("\n");
set0(vec7,bits7,k3+1);
printBV(vec7,bits7);;


return 0;
}
