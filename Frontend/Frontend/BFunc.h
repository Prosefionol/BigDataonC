#pragma once

#include "Elem.h"
#include "Oshibka.h"

// ��������� �������
void GetFromFile(Elem* (&e), int& n, std::string filename) throw (Oshibka&); // ���������� �� �����
void PrintData(Elem* e, int n) throw (Oshibka&); // ������ ������
void ChangeData(Elem* d, int n, int ch) throw (Oshibka&); // ��������� ������
void AddData(Elem* (&e), int& n) throw (Oshibka&); // ���������� ������
void CopyData(Elem* enew, Elem* eold, int n) throw (Oshibka&); // ����������� ������
void DeleteData(Elem* e, int n, int del) throw (Oshibka&); // �������� ������
void SortingRelevance(Elem* e, int n) throw (Oshibka&); // ���������� ������
void SaveToFile(Elem* (&e), int& n, std::string filename) throw (Oshibka&); // ���������� � ����
void ApplyTopsis(Elem* (&e), int& n) throw (Oshibka&); // ���������� ������ TOPSIS
