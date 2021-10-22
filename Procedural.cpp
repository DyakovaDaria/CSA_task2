//------------------------------------------------------------------------------
// Procedural.cpp - содержит процедуру ввода и вывода параметров и их обработки
// для уже созданного процедурного языка
//------------------------------------------------------------------------------

#include "Procedural.h"
#include "rnd.h"

#include <iostream>

//------------------------------------------------------------------------------
// Ввод параметров процедурного языка из файла
void Procedural::In(std::ifstream &ifst) {
  ifst >> creat_year >> popularity_perc >> abstract_data_types;
  ifst >> name;
}

// Случайный ввод параметров процедурного языка
void Procedural::InRnd() {
  // Генерация года создания языка
  creat_year = RandomYear();
  // Генерация процента популярности языка
  popularity_perc = RandomPerc();
  // Генерация наличия абстрактных типов данных в языке
  abstract_data_types = RandomBool();
  // Генерация названия языка
  int length = rand() % 11 + 3;
  name[0] = 'A' + rand() % 26;
  for (int i = 1; i < length - 1; ++i) {
    name[i] = 'a' + rand() % 26;
  }
  name[length - 1] = '\0';
}
