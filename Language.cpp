//------------------------------------------------------------------------------
// Language.cpp - содержит процедуры связанные с обработкой языка программирования
// и создания произвольного языка
//------------------------------------------------------------------------------

#include "Functional.h"
#include "Object_oriented.h"
#include "Procedural.h"
#include <random>

#include <iostream>

//------------------------------------------------------------------------------
// Ввод параметров языка программирования из файла
Language *Language::StaticIn(std::ifstream &ifst) {
  Language *sp = nullptr;
  int k;
  ifst >> k;
  switch (k) {
    case 1:
      sp = new Procedural;
      break;
    case 2:
      sp = new Object_oriented;
      break;
    case 3:
      sp = new Functional;
      break;
  }
  if (sp != nullptr) {
    sp->In(ifst);
  }
  return sp;
}

// Случайный ввод языка программирования
Language *Language::StaticInRnd() {
  Language *sp = nullptr;
  int k = rand() % 3 + 1;
  switch (k) {
    case 1:
      sp = new Procedural;
      break;
    case 2:
      sp = new Object_oriented;
      break;
    case 3:
      sp = new Functional;
      break;
  }
  sp->InRnd();
  return sp;
}

//-------------------------------------------------------------------------------
// Вычисление частного от деления года создания на количесвто символов в названии
float Language::Quotient() {
  return creat_year / (float) strlen(name);
}

//-------------------------------------------------------------------------------
// Вывод параметров языка в файл
void Language::Out(std::ofstream &ofst) {
  ofst << "It is procedural language: " << name << ": ";
  ofst << "the year of creation = " << creat_year;
  ofst << ", popularity percentage = " << popularity_perc;
  ofst << ". Quotient = " << Quotient() << ".\n";
}
