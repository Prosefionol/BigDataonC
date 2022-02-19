#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

// ��������� ��� �������� ���������� � ���������
struct product
{
	std::string name;
	double property[2];
	double relevance;
};

// ��������������� ������
typedef struct elem
{
	std::string supplier;
	product pr;
	elem* Ladr;
	elem* Radr;
};

// ��������� �������
void GetFromFile(elem** nach, elem** konc, int n); // ��������� ��������������� ������ �� �����
void WriteBase(elem* nach, int n); // ����� ���������������� ������ � ������
void BaseWrite(elem* konc, int n); // ����� ���������������� ������ � �����
void RelevanceSort(elem** nach, elem** konc); // ���������� ���������������� ������ �� �������������
void CalculatingRelevance(elem** nach); // ������� �������������
void DataSwap(elem* a, elem* b); // �������� ������� ��� �������� � ��������������� ������

// ������� �������
int main()
{
	int i, n;
	elem* nach = NULL, * konc = NULL;
	std::cout << "Database size:" << std::endl;
	std::cin >> n;
	GetFromFile(&nach, &konc, n);
	if (nach != NULL)
	{
		CalculatingRelevance(&nach);
	}
	RelevanceSort(&nach, &konc);
	std::cout << "Output:" << std::endl;
	BaseWrite(konc, n);
	_getch();
	return 0;
}

// �������� ��������������� �������
void GetFromFile(elem** nach, elem** konc, int n)
{
	std::fstream f;
	std::string str, str1;
	double a[2];
	elem* t;
	f.open("input.txt", std::ios::in); // ��������� ���� �� ������
	for (int i = 0; i < n; i++) // ��������� ������ ������� �� �����
	{
		f >> str;
		f >> str1;
		f >> a[0];
		f >> a[1];
		t = new(elem);
		if (*nach == NULL) // ���� ������ ����
		{
			t->supplier = str;
			t->pr.name = str1;
			t->pr.property[0] = a[0];
			t->pr.property[1] = a[1];
			t->Radr = NULL;
			t->Ladr = NULL;
			*nach = t;
			*konc = t;
		}
		else // ���� � ������ ���� ��������
		{
			t->supplier = str;
			t->pr.name = str1;
			t->pr.property[0] = a[0];
			t->pr.property[1] = a[1];
			t->Radr = *nach;
			t->Ladr = NULL;
			(*nach)->Ladr = t;
			*nach = t;
		}
	}
	f.close(); // ��������� ����
}

void WriteBase(elem* nach, int n)
{
	elem* t;
	t = nach;
	if (t != NULL)
	{
		while (t != NULL)
		{
			std::cout << t->pr.name << " " << t->pr.relevance << " " << t->supplier << std::endl;
			t = t->Radr;
		}
	}
	else
	{
		std::cout << "Empty database!" << std::endl;
	}
}

void BaseWrite(elem* konc, int n)
{
	elem* t;
	t = konc;
	if (t != NULL)
	{
		while (t != NULL)
		{
			std::cout << t->pr.name << " " << t->pr.relevance << " " << t->supplier << std::endl;
			t = t->Ladr;
		}
	}
	else
	{
		std::cout << "Empty database!" << std::endl;
	}
}

void RelevanceSort(elem** nach, elem** konc)
{
	elem* t;
	t = new(elem);
	for (elem* i = *nach; i; i = i->Radr)
	{
		for (elem* j = *nach; j; j = j->Radr)
		{
			if ((i->pr.name) > (j->pr.name)) // ������������� ��������� �� ��������� ��������
			{
				DataSwap(i, j);
			}
			// ���� ��������� ����������, �� ������� �������������
			if (((i->pr.name) == (j->pr.name)) && ((i->pr.relevance) > (j->pr.relevance)))
			{
				DataSwap(i, j);
			}
		}
	}
}

void CalculatingRelevance(elem** nach)
{
	for (elem* i = *nach; i; i = i->Radr)
	{
		i->pr.relevance = i->pr.property[0] + i->pr.property[1];
	}
}

void DataSwap(elem* a, elem* b)
{
	elem* t;
	t = new(elem);
	t->supplier = a->supplier;
	a->supplier = b->supplier;
	b->supplier = t->supplier;
	t->pr.name = a->pr.name;
	a->pr.name = b->pr.name;
	b->pr.name = t->pr.name;
	t->pr.relevance = a->pr.relevance;
	a->pr.relevance = b->pr.relevance;
	b->pr.relevance = t->pr.relevance;
	t->pr.property[0] = a->pr.property[0];
	a->pr.property[0] = b->pr.property[0];
	b->pr.property[0] = t->pr.property[0];
	t->pr.property[1] = a->pr.property[1];
	a->pr.property[1] = b->pr.property[1];
	b->pr.property[1] = t->pr.property[1];
}