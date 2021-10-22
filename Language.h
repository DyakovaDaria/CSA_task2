#ifndef CSA_TASK2__LANGUAGE_H_
#define CSA_TASK2__LANGUAGE_H_

//------------------------------------------------------------------------------
// Language.h - содержит описание языка программирования как обобщенного артефакта
//------------------------------------------------------------------------------

#include <fstream>

class Language {
 public:
  int creat_year;       // год создания языка
  float popularity_perc;// процент популярности
  char name[100];       // название языка

  virtual ~Language(){};

  // Ввод языка программирования
  static Language *StaticIn(std::ifstream &ifst);

  // Ввод языка программирования
  virtual void In(std::ifstream &ifst) = 0;

  // Случайный ввод языка программирования
  static Language *StaticInRnd();

  // Случайный ввод языка программирования
  virtual void InRnd() = 0;

  // Вывод языка программирования в файл
  void Out(std::ofstream &ofst);

  // Вычисление частного от деления года создания на количество символов в названии
  float Quotient();
};

#endif
