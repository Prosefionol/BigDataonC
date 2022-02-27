#include "BFunc.h"

// Описание функций
// Считывание из файла
void GetFromFile(Elem* (&e), int& n, std::string filename) throw (Oshibka&)
{
	std::ifstream ifile(filename);
	try
	{
		if (ifile)
		{
			// Создаём временные переменные
			std::string supp;
			Product prod;

			ifile >> n;
			e = new Elem[n];

			for (int i = 0; i < n; i++)
			{
				ifile >> supp;
				ifile >> prod.name;
				ifile >> prod.property[0] >> prod.property[1] >> prod.property[2] >> prod.property[3] >>
					prod.property[4] >> prod.property[5] >> prod.property[6] >> prod.property[7];
				ifile >> prod.relevance;

				e[i].GetDatabase(supp, prod);
			}
		}
		else
		{
			throw Oshibka("Problema s otkritiem fila");
		}
	}
	catch (Oshibka& o)
	{
		std::cerr << o.GetNazv() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Chto-to poshlo ne tak!" << std::endl;
	}
	ifile.close();
}

// Печать данных
void PrintData(Elem* e, int n) throw (Oshibka&)
{
	try
	{
		if (n != 0)
		{
			for (int i = 0; i < n; i++)
			{
				e[i].Print();
			}
		}
		else
		{
			throw Oshibka("Net dannih");
		}
	}
	catch (Oshibka& o)
	{
		std::cerr << o.GetNazv() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Chto-to poshlo ne tak!" << std::endl;
	}
}

// Изменение данных
// ch - номер изменяемых данных
void ChangeData(Elem* e, int n, int ch) throw (Oshibka&)
{
	try
	{
		std::string supp;
		Product prod;

		if ((ch < n) && (ch >= 0))
		{
			std::cin >> supp;
			std::cin >> prod.name;
			std::cin >> prod.property[0] >> prod.property[1] >> prod.property[2] >> prod.property[3] >>
				prod.property[4] >> prod.property[5] >> prod.property[6] >> prod.property[7];
			std::cin >> prod.relevance;

			e[ch].GetDatabase(supp, prod);
		}
		else
		{
			throw Oshibka("Nomer za granicey dopustimih");
		}
	}
	catch (Oshibka& o)
	{
		std::cerr << o.GetNazv() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Chto-to poshlo ne tak!" << std::endl;
	}
}

// Добавление данных
void AddData(Elem* (&e), int& n) throw (Oshibka&)
{
	Elem* buffer = new Elem[n];
	try
	{
		std::string supp;
		Product prod;
		int s, ns;
		s = n;
		ns = s + 1;

		CopyData(buffer, e, s);
		e = new Elem[ns];
		CopyData(e, buffer, s);

		std::cin >> supp;
		std::cin >> prod.name;
		std::cin >> prod.property[0] >> prod.property[1] >> prod.property[2] >> prod.property[3] >>
			prod.property[4] >> prod.property[5] >> prod.property[6] >> prod.property[7];
		std::cin >> prod.relevance;

		e[n].GetDatabase(supp, prod);
	}
	catch (...)
	{
		std::cerr << "Chto-to poshlo ne tak!" << std::endl;
	}
	delete[] buffer;
}

// Копирование данных
void CopyData(Elem* enew, Elem* eold, int n) throw (Oshibka&)
{
	try
	{
		for (int i = 0; i < n; i++)
		{
			enew[i] = eold[i];
		}
	}
	catch (...)
	{
		std::cerr << "Chto-to poshlo ne tak!" << std::endl;
	}
}

// Удаление данных
// del - номер удаляемого переменного
void DeleteData(Elem* e, int n, int del) throw (Oshibka&)
{
	Elem* buffer = new Elem[n];
	try
	{
		if ((del < n) && (del >= 0))
		{
			CopyData(buffer, e, n);
			int k = 0;
			n = n - 1;
			e = new Elem[n];
			for (int i = 0; i <= n; i++)
			{
				if (i != del)
				{
					e[k] = buffer[i];
					k = k + 1;
				}
			}
		}
		else
		{
			throw Oshibka("Nomer za granicey dopustimih");
		}
	}
	catch (Oshibka& o)
	{
		std::cerr << o.GetNazv() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Chto-to poshlo ne tak!" << std::endl;
	}
	delete[] buffer;
}

// Сортировка данных
void SortingRelevance(Elem* e, int n) throw (Oshibka&)
{
	try
	{
		Elem buffer;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (e[i].GetProduct().relevance > e[j].GetProduct().relevance)
				{
					buffer = e[i];
					e[i] = e[j];
					e[j] = buffer;
				}
			}
		}
	}
	catch (...)
	{
		std::cerr << "Chto-to poshlo ne tak!" << std::endl;
	}
}

// Сохранение в файл
void SaveToFile(Elem* (&e), int& n, std::string filename) throw (Oshibka&)
{
	std::ofstream ofile(filename);
	try
	{
		if (ofile)
		{
			ofile << n << std::endl;
			
			for (int i = 0; i < n; i++)
			{
				ofile << e[i].GetSupplier() << std::endl;
				ofile << e[i].GetProduct().name << std::endl;
				ofile << e[i].GetProduct().property[0] << " " << e[i].GetProduct().property[1] << " " << e[i].GetProduct().property[2] << " "
					<< e[i].GetProduct().property[3] << " " << e[i].GetProduct().property[4] << " " << e[i].GetProduct().property[5] << " "
					<< e[i].GetProduct().property[6] << " " << e[i].GetProduct().property[7] << std::endl;
				ofile << e[i].GetProduct().relevance;
				
				if (i < n - 1)
				{
					ofile << std::endl;
				}
			}
		}
		else
		{
			throw Oshibka("Problema s otkritiem fila");
		}
	}
	catch (Oshibka& o)
	{
		std::cerr << o.GetNazv() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Chto-to poshlo ne tak!" << std::endl;
	}
	ofile.close();
}