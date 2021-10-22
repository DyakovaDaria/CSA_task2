//------------------------------------------------------------------------------
// Container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "Container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container() : len{0} {}

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
  Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
  for (int i = 0; i < len; i++) {
    delete cont[i];
  }
  len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(std::ifstream &ifst) {
  while (!ifst.eof()) {
    if ((cont[len] = Language::StaticIn(ifst)) != nullptr) {
      len++;
    }
  }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int s) {
  while (len < s) {
    if ((cont[len] = Language::StaticInRnd()) != nullptr) {
      len++;
    }
  }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(std::ofstream &ofst) {
  ofst << "Container contains " << len << " elements.\n";
  for (int i = 0; i < len; i++) {
    ofst << i + 1 << ": ";
    cont[i]->Out(ofst);
  }
}

//------------------------------------------------------------------------------
// Сортировка по убыванию методом слияния

// Метод для "слияния" двух массивов
// first - левый индекс, last - правый индекс подмассивов
void Container::Merge(Container *c, int first, int last) {
  int middle;
  int start;
  int final;
  int j;
  Container *mas = new Container[100];
  middle = (first + last) / 2;   // Вычисление среднего элемента
  start = first;                 // Начало левой части
  final = middle + 1;            // Начало правой части
  for (j = first; j <= last; j++)// Выполнять от начала до конца
    if ((start <= middle) && ((final > last) || (c->cont[start]->Quotient() > c->cont[final]->Quotient()))) {
      mas->cont[j] = c->cont[start];
      start++;
    } else {
      mas->cont[j] = c->cont[final];
      final++;
    }
  // Возвращение результата в список
  for (j = first; j <= last; j++) {
    c->cont[j] = mas->cont[j];
  }
  delete[] mas;
}

// Рекурсивная функция сортировки
void Container::MergeSort(Container *c, int first, int last) {
  {
    if (first < last) {
      MergeSort(c, first, (first + last) / 2);   // Сортировка левой части
      MergeSort(c, (first + last) / 2 + 1, last);// Сортировка правой части
      Merge(c, first, last);                     // Слияние двух частей
    }
  }
}
