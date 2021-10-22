#ifndef CSA_TASK2__PROCEDURAL_H_
#define CSA_TASK2__PROCEDURAL_H_

//------------------------------------------------------------------------------
// Procedural.h - содержит описание процедурного языка программирования
//------------------------------------------------------------------------------

#include "Language.h"
#include <fstream>

class Procedural : public Language {
 private:
  bool abstract_data_types;// наличие или отсутствие абстрактных типов данных

 public:
  virtual ~Procedural() {}

  // Ввод параметров процедурного языка из файла
  virtual void In(std::ifstream &ifst);

  // Случайный ввод параметров процедурного языка
  virtual void InRnd();
};

#endif
