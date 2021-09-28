#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

// Двунаправленный список
typedef struct elem
{
	std::string word;
	elem* Ladr;
	elem* Radr;
};

// Прототипы функций
void GetFromFile(elem** nach, elem** konc, int n); // Заполняем двунаправленный список из файла
void WriteBase(elem* nach, int n); // Вывод двунаправленного списка с начала
void BaseWrite(elem* konc, int n); // Вывод двунаправленного списка с конца
void StrSort(elem** nach); // Сортировка двунаправленного списка
int DeleteLishnee(elem** nach, elem** konc); // Удаление повторяющихся элементов двунаправленного списка

// Главная функция
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
	// Удаляем до тех пор, пока в списке будет нечего удалять (проходим в цикле)
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

// Описание вспомогательных функций
void GetFromFile(elem** nach, elem** konc, int n)
{
	std::fstream f;
	std::string str;
	elem* t;
	f.open("input.txt", std::ios::in); // Открываем файл на чтение
	for (int i = 0; i < n; i++) // Заполняем список словами из файла
	{
		f >> str;
		t = new(elem);
		if (*nach == NULL) // Если список пуст
		{
			t->word = str;
			t->Radr = NULL;
			t->Ladr = NULL;
			*nach = t;
			*konc = t;
		}
		else // Если в списке есть елементы
		{
			t->word = str;
			t->Radr = *nach;
			t->Ladr = NULL;
			(*nach)->Ladr = t;
			*nach = t;
		}
	}
	f.close(); // Закрываем файл
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
			if ((i->word).length() > (j->word).length()) // Первоначально сортируем по длине
			{
				t->word = j->word;
				j->word = i->word;
				i->word = t->word;
			}
			// Если равная длина, то в алфавитном порядке
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
		elem* k = j->Radr; // Если j существует, то запоминаем следующий за ним элемент
	}
	while (j != NULL)
	{
		if ((i->word) == (j->word))
		{
			i->Radr = j->Radr;
			d = 1;
			// Если за j не последний элемент в списке, то изменяем левый адрес элемента, который следует за ним
			if (j->Radr != NULL)
			{
				k->Ladr = i;
				delete j;
				break;
			}
			// Если j - последний, то теперь i - последний
			else
			{
				*konc = i;
				delete j;
				break;
			}
		}
		// Делаем шаг вперёд, если это возможно (список пока не закончился)
		i = i->Radr;
		j = i->Radr;
		if (j != NULL)
		{
			k = j->Radr;
		}
	}
	return d; // Отправляем в мейн удалили ли мы что-то
}