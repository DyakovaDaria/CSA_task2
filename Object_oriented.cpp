//------------------------------------------------------------------------------
// Object_oriented.cpp - содержит процедуру ввода и вывода параметров и их обработки
// для уже созданного объектно-ориентированного языка
//------------------------------------------------------------------------------

#include "Object_oriented.h"
#include "rnd.h"

#include <iostream>

//------------------------------------------------------------------------------
// Ввод параметров объектно-ориентированного языка из файла
void Object_oriented::In(std::ifstream &ifst) {
  ifst >> k >> creat_year >> popularity_perc;
  ifst >> name;
  switch (k) {
    case 1:
      k = SINGLE_INHERITANCE;
      break;
    case 2:
      k = MULTIPLE_INHERITANCE;
      break;
    case 3:
      k = INTERFACE_INHERITANCE;
      break;
  }
}

// Случайный ввод параметров объектно-ориентированного языка
void Object_oriented::InRnd() {
  // Генерация года создания языка
  creat_year = RandomYear();
  // Генерация процента популярности языка
  popularity_perc = RandomPerc();
  // Генерация названия языка
  int length = rand() % 11 + 3;
  name[0] = 'A' + rand() % 26;
  for (int i = 1; i < length - 1; ++i) {
    name[i] = 'a' + rand() % 26;
  }
  name[length - 1] = '\0';
  // Генерация вида наследования в языке
  int key = rand() % 3 + 1;
  switch (key) {
    case 1:
      k = SINGLE_INHERITANCE;
      break;
    case 2:
      k = MULTIPLE_INHERITANCE;
      break;
    case 3:
      k = INTERFACE_INHERITANCE;
      break;
  }
}
