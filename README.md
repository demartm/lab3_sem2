# lab3_sem2
Реализовать все предложенные операции для булева вектора произвольной длины.

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

10.Функция печати булева вектора на консоль;