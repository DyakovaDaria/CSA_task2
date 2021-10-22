#ifndef CSA_TASK2__CONTAINER_H_
#define CSA_TASK2__CONTAINER_H_

//------------------------------------------------------------------------------
// Container.h - содержит тип данных, представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "Language.h"
#include <iostream>

class Container {
 private:
  void Clear();// Очистка контейнера от элементов (освобождение памяти)
  Language *cont[10000];

 public:
  int len = 0;// текущая длина

  Container();
  ~Container();

  // Ввод содержимого контейнера из указанного файла
  void In(std::ifstream &ifst);

  // Случайный ввод содержимого контейнера
  void InRnd(int size);

  // Вывод содержимого контейнера в указанный файл
  void Out(std::ofstream &ofst);

  // Сортировка по убыванию для частного от деления года создания
  // на количество символов в названии и "слияние" двух массивов
  void Merge(Container *c, int first, int last);

  // Функция рекурсивной сортировки
  void MergeSort(Container *c, int first, int last);
};

#endif
