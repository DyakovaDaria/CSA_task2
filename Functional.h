#ifndef CSA_TASK2__FUNCTIONAL_H_
#define CSA_TASK2__FUNCTIONAL_H_

//------------------------------------------------------------------------------
// Functional.h - содержит описание функционального языка программирования
//------------------------------------------------------------------------------

#include "Language.h"
#include <fstream>
#include <string.h>

class Functional : public Language {
 private:
  // Виды типизации функционального языка
  enum tipisation {
    STATIC_TIPISATION,
    DYNAMIC_TIPISATION
  };
  int k;
  bool lazy_calculations;// наличие "ленивых" вычислений
 public:
  virtual ~Functional() {}

  // Ввод параметров функционального языка из файла
  virtual void In(std::ifstream &ifst);

  // Случайный ввод параметров функционального языка
  virtual void InRnd();
};

#endif
