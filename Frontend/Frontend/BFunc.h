#pragma once

#include "Elem.h"
#include "Oshibka.h"

// Прототипы функций
void GetFromFile(Elem* (&e), int& n, std::string filename) throw (Oshibka&); // Считывание из файла
void PrintData(Elem* e, int n) throw (Oshibka&); // Печать данных
void ChangeData(Elem* d, int n, int ch) throw (Oshibka&); // Изменение данных
void AddData(Elem* (&e), int& n) throw (Oshibka&); // Добавление данных
void CopyData(Elem* enew, Elem* eold, int n) throw (Oshibka&); // Копирование данных
void DeleteData(Elem* e, int n, int del) throw (Oshibka&); // Удаление данных
void SortingRelevance(Elem* e, int n) throw (Oshibka&); // Сортировка данных
void SaveToFile(Elem* (&e), int& n, std::string filename) throw (Oshibka&); // Сохранение в файл
void ApplyTopsis(Elem* (&e), int& n) throw (Oshibka&); // Применение метода TOPSIS
