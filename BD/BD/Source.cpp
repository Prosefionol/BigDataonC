#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

// ��������������� ������
typedef struct elem
{
	std::string word;
	elem* Ladr;
	elem* Radr;
};

// ��������� �������
void GetFromFile(elem** nach, elem** konc, int n); // ��������� ��������������� ������ �� �����
void WriteBase(elem* nach, int n); // ����� ���������������� ������ � ������
void BaseWrite(elem* konc, int n); // ����� ���������������� ������ � �����
void StrSort(elem** nach); // ���������� ���������������� ������
int DeleteLishnee(elem** nach, elem** konc); // �������� ������������� ��������� ���������������� ������

// ������� �������
int main()
// int _tmain(int argc, _TCHAR* argv[])
{
	int i, n;
	elem* nach = NULL, *konc = NULL;
	std::cout << "Vvedite kol-vo slov v file" << std::endl;
	std::cin >> n;
	GetFromFile(&nach, &konc, n);
	StrSort(&nach);
	std::cout << "Otsortirovanniy spisok:" << std::endl;
	BaseWrite(konc, n);
	// ������� �� ��� ���, ���� � ������ ����� ������ ������� (�������� � �����)
	i = DeleteLishnee(&nach, &konc);
	while (i == 1)
	{
		i = DeleteLishnee(&nach, &konc);
	}
	std::cout << "Otsortirovanniy spisok bez povtorov:" << std::endl;
	BaseWrite(konc, n);
	_getch();
	return 0;
}

// �������� ��������������� �������
void GetFromFile(elem** nach, elem** konc, int n)
{
	std::fstream f;
	std::string str;
	elem* t;
	f.open("input.txt", std::ios::in); // ��������� ���� �� ������
	for (int i = 0; i < n; i++) // ��������� ������ ������� �� �����
	{
		f >> str;
		t = new(elem);
		if (*nach == NULL) // ���� ������ ����
		{
			t->word = str;
			t->Radr = NULL;
			t->Ladr = NULL;
			*nach = t;
			*konc = t;
		}
		else // ���� � ������ ���� ��������
		{
			t->word = str;
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
			std::cout << t->word << std::endl;
			t = t->Radr;
		}
	}
	else
	{
		std::cout << "Spisok pust!" << std::endl;
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
			std::cout << t->word << std::endl;
			t = t->Ladr;
		}
	}
	else
	{
		std::cout << "Spisok pust!" << std::endl;
	}
}

void StrSort(elem** nach)
{
	elem* t;
	t = new(elem);
	for (elem* i = *nach; i; i = i->Radr)
	{
		for (elem* j = *nach; j; j = j->Radr)
		{
			if ((i->word).length() > (j->word).length()) // ������������� ��������� �� �����
			{
				t->word = j->word;
				j->word = i->word;
				i->word = t->word;
			}
			// ���� ������ �����, �� � ���������� �������
			if (((i->word).length() == (j->word).length()) && ((i->word) > (j->word)))
			{
				t->word = j->word;
				j->word = i->word;
				i->word = t->word;
			}
		}
	}
}

int DeleteLishnee(elem** nach, elem** konc)
{

	int d = 0;
	elem* i = *nach;
	elem* j = i->Radr;
	elem* k;
	k = new(elem);
	if (j != NULL)
	{
		elem* k = j->Radr; // ���� j ����������, �� ���������� ��������� �� ��� �������
	}
	while (j != NULL)
	{
		if ((i->word) == (j->word))
		{
			i->Radr = j->Radr;
			d = 1;
			// ���� �� j �� ��������� ������� � ������, �� �������� ����� ����� ��������, ������� ������� �� ���
			if (j->Radr != NULL)
			{
				k->Ladr = i;
				delete j;
				break;
			}
			// ���� j - ���������, �� ������ i - ���������
			else
			{
				*konc = i;
				delete j;
				break;
			}
		}
		// ������ ��� �����, ���� ��� �������� (������ ���� �� ����������)
		i = i->Radr;
		j = i->Radr;
		if (j != NULL)
		{
			k = j->Radr;
		}
	}
	return d; // ���������� � ���� ������� �� �� ���-��
}