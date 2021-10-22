//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию
//------------------------------------------------------------------------------

#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "container.h"

void errMessage1() {
  printf("incorrect command line!\n"
         "  Waited:\n"
         "     command -f infile outfile01 outfile02\n"
         "  Or:\n"
         "     command -n number outfile01 outfile02\n");
}

void errMessage2(int size) {
  printf("incorrect number of languages = %d."
         "Set 0 < number <= 10000\n",
         size);
}

void errMessage3() {
  printf("incorrect qualifier value!\n"
         "  Waited:\n"
         "     command -f infile outfile01 outfile02\n"
         "  Or:\n"
         "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
  if (argc != 5) {
    errMessage1();
    return 1;
  }
  printf("Start\n");
  Container c;
  if (!strcmp(argv[1], "-f")) {
    std::ifstream ifst(argv[2]);
    c.In(ifst);
  } else if (!strcmp(argv[1], "-n")) {
    int size = atoi(argv[2]);
    if ((size < 1) || (size > 10000)) {
      errMessage2(size);
      return 3;
    }
    // Системные часы в качестве инициализатора
    srand(static_cast<unsigned int>(time(0)));
    // Заполнение контейнера генератором случайных чисел
    c.InRnd(size);
  } else {
    errMessage3();
    return 2;
  }
  // Вывод содержимого контейнера в файл
  std::ofstream ofst1(argv[3]);
  ofst1 << "Filled container:\n";
  c.Out(ofst1);
  // Вторая часть задания
  // Сортировка элементов контейнера и вывод результата в файл
  std::ofstream ofst2(argv[4]);
  ofst2 << "Conditionally refilled container:\n";
  c.MergeSort(&c, 0, c.len - 1);
  c.Out(ofst2);
  printf("Stop \n");
  return 0;
}
