//------------------------------------------------------------------------------
// Functional.cpp - содержит процедуру ввода и вывода параметров и их обработки
// для уже созданного функционального языка
//------------------------------------------------------------------------------

#include "Functional.h"
#include "rnd.h"

#include <iostream>

//------------------------------------------------------------------------------
// Ввод параметров функционального языка из файла
void Functional::In(std::ifstream &ifst) {
  ifst >> k >> creat_year >> popularity_perc >> lazy_calculations;
  ifst >> name;
  switch (k) {
    case 1:
      k = DYNAMIC_TIPISATION;
      break;
    case 2:
      k = STATIC_TIPISATION;
      break;
  }
}

// Случайный ввод параметров функционального языка
void Functional::InRnd() {
  // Генерация года создания языка
  creat_year = RandomYear();
  // Генерация процента популярности языка
  popularity_perc = RandomPerc();
  // Генерация наличия "ленивых" вычислений
  lazy_calculations = RandomBool();
  // Генерация названия языка
  int length = rand() % 11 + 3;
  name[0] = 'A' + rand() % 26;
  for (int i = 1; i < length - 1; ++i) {
    name[i] = 'a' + rand() % 26;
  }
  name[length - 1] = '\0';
  // Генерация типизации языка
  int key = rand() % 2 + 1;
  switch (key) {
    case 1:
      k = DYNAMIC_TIPISATION;
      break;
    case 2:
      k = STATIC_TIPISATION;
      break;
  }
}
