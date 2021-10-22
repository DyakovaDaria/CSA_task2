#ifndef CSA_TASK2__OBJECT_ORIENTED_H_
#define CSA_TASK2__OBJECT_ORIENTED_H_

//---------------------------------------------------------------------------------------
// Object_oriented.h - содержит описание объектно-ориентированного языка программирования
//---------------------------------------------------------------------------------------

#include "Language.h"
#include <fstream>

class Object_oriented : public Language {
 private:
  // Виды наследования объектно-ориентированного языка программирования
  enum inheritance {
    SINGLE_INHERITANCE,
    MULTIPLE_INHERITANCE,
    INTERFACE_INHERITANCE
  };
  int k;

 public:
  virtual ~Object_oriented() {}

  // Ввод параметров объектно-ориентированного языка из файла
  virtual void In(std::ifstream &ifst);

  // Случайный ввод параметров объектно-ориентированного языка
  virtual void InRnd();
};

#endif
