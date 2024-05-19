#pragma once

#include "Elem.h"
#include "Oshibka.h"


// Прототипы функций
bool GetFromFile(Elem* (&e), int& n, std::string filename) throw (Oshibka&); // Считывание из файла
void PrintData(Elem* e, int n) throw (Oshibka&); // Печать данных
void ChangeData(Elem* d, int n, int ch) throw (Oshibka&); // Изменение данных
void AddData(Elem* (&e), int& n) throw (Oshibka&); // Добавление данных
void CopyData(Elem* enew, Elem* eold, int n) throw (Oshibka&); // Копирование данных
void DeleteData(Elem* (&e), int& n, int del) throw (Oshibka&); // Удаление данных
void SortingRelevance(Elem* e, int n) throw (Oshibka&); // Сортировка данных по убыванию
void RelevanceSorting(Elem* e, int n) throw (Oshibka&); // Сортировка данных по возрастанию
void Sorting(Elem* e, int n, int k) throw (Oshibka&); // Сортировка данных по критерию
bool SaveToFile(Elem* (&e), int& n, std::string filename) throw (Oshibka&); // Сохранение в файл
void ApplyTopsis(Elem* (&e), int& n) throw (Oshibka&); // Применение метода TOPSIS
void ApplyMCDM(Elem* (&e), int& n) throw (Oshibka&); // Применение оригинального метода
double FindAverageRelevance(Elem* e, int n) throw (Oshibka&); // Нахождение среднего значения релевантности
void ClearFile(std::string filename); // Опустошить файл

// Прототипы функций преобразования типов
std::string& Stos(System::String^ s); // Из фронтенда в бэкенд
System::String^ stoS(std::string& s); // Из бэкенда в фронтенд
std::string& S_to_s(System::String^ s_o, std::string& s_n); // Из фронтенда в бэкенд

