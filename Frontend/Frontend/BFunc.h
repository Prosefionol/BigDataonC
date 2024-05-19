#pragma once

#include "Elem.h"
#include "Oshibka.h"


// ��������� �������
bool GetFromFile(Elem* (&e), int& n, std::string filename) throw (Oshibka&); // ���������� �� �����
void PrintData(Elem* e, int n) throw (Oshibka&); // ������ ������
void ChangeData(Elem* d, int n, int ch) throw (Oshibka&); // ��������� ������
void AddData(Elem* (&e), int& n) throw (Oshibka&); // ���������� ������
void CopyData(Elem* enew, Elem* eold, int n) throw (Oshibka&); // ����������� ������
void DeleteData(Elem* (&e), int& n, int del) throw (Oshibka&); // �������� ������
void SortingRelevance(Elem* e, int n) throw (Oshibka&); // ���������� ������ �� ��������
void RelevanceSorting(Elem* e, int n) throw (Oshibka&); // ���������� ������ �� �����������
void Sorting(Elem* e, int n, int k) throw (Oshibka&); // ���������� ������ �� ��������
bool SaveToFile(Elem* (&e), int& n, std::string filename) throw (Oshibka&); // ���������� � ����
void ApplyTopsis(Elem* (&e), int& n) throw (Oshibka&); // ���������� ������ TOPSIS
void ApplyMCDM(Elem* (&e), int& n) throw (Oshibka&); // ���������� ������������� ������
double FindAverageRelevance(Elem* e, int n) throw (Oshibka&); // ���������� �������� �������� �������������
void ClearFile(std::string filename); // ���������� ����

// ��������� ������� �������������� �����
std::string& Stos(System::String^ s); // �� ��������� � ������
System::String^ stoS(std::string& s); // �� ������� � ��������
std::string& S_to_s(System::String^ s_o, std::string& s_n); // �� ��������� � ������

