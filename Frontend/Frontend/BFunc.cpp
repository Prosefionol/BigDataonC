#include "BFunc.h"

// Описание функций
// Считывание из файла
bool GetFromFile(Elem* (&e), int& n, int& state, std::string filename) throw (Oshibka&)
{
	std::ifstream ifile(filename);
	try
	{
		if (ifile)
		{
			// Создаём временные переменные
			std::string supp;
			Product prod;
			
			ifile >> n >> state;
			
			e = new Elem[n];

			for (int i = 0; i < n; i++)
			{
				ifile >> supp;
				ifile >> prod.name;
				ifile >> prod.property[0] >> prod.property[1] >> prod.property[2] >> prod.property[3] >>
					prod.property[4] >> prod.property[5] >> prod.property[6];
				ifile >> prod.relevance;

				e[i].GetDatabase(supp, prod);
			}
		}
		else
		{
			throw Oshibka("Проблема с открытием файла!");
		}
	}
	catch (Oshibka& o)
	{
		System::Windows::Forms::MessageBox::Show(stoS(o.GetNazv()), "Ошибка!");
		ifile.close();
		return false;
	}
	catch (...)
	{
		System::Windows::Forms::MessageBox::Show("Что-то пошло не так", "Ошибка!");
		ifile.close();
		return false;
	}
	ifile.close();
	return true;
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
			throw Oshibka("Нет данных!");
		}
	}
	catch (Oshibka& o)
	{
		System::Windows::Forms::MessageBox::Show(stoS(o.GetNazv()), "Ошибка!");
	}
	catch (...)
	{
		System::Windows::Forms::MessageBox::Show("Что-то пошло не так", "Ошибка!");
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
				prod.property[4] >> prod.property[5] >> prod.property[6];
			std::cin >> prod.relevance;

			e[ch].GetDatabase(supp, prod);
		}
		else
		{
			throw Oshibka("Номер за границей допустимых!");
		}
	}
	catch (Oshibka& o)
	{
		System::Windows::Forms::MessageBox::Show(stoS(o.GetNazv()), "Ошибка!");
	}
	catch (...)
	{
		System::Windows::Forms::MessageBox::Show("Что-то пошло не так", "Ошибка!");
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
			prod.property[4] >> prod.property[5] >> prod.property[6];
		std::cin >> prod.relevance;

		e[s].GetDatabase(supp, prod);
		n = ns;
	}
	catch (...)
	{
		System::Windows::Forms::MessageBox::Show("Что-то пошло не так", "Ошибка!");
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
		System::Windows::Forms::MessageBox::Show("Что-то пошло не так", "Ошибка!");
	}
}

// Удаление данных
// del - номер удаляемого переменного
void DeleteData(Elem* (&e), int& n, int del) throw (Oshibka&)
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
			throw Oshibka("Номер за границей допустимых!");
		}
	}
	catch (Oshibka& o)
	{
		System::Windows::Forms::MessageBox::Show(stoS(o.GetNazv()), "Ошибка!");
	}
	catch (...)
	{
		System::Windows::Forms::MessageBox::Show("Что-то пошло не так", "Ошибка!");
	}
	delete[] buffer;
}

// Сортировка данных по убыванию
void SortingRelevance(Elem* e, int n) throw (Oshibka&)
{
	try
	{
		Elem buffer;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (e[i].GetProduct().relevance < e[j].GetProduct().relevance)
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
		System::Windows::Forms::MessageBox::Show("Что-то пошло не так", "Ошибка!");
	}
}

// Сортировка данных по возрастанию
void RelevanceSorting(Elem* e, int n) throw (Oshibka&)
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
		System::Windows::Forms::MessageBox::Show("Что-то пошло не так", "Ошибка!");
	}
}

// Сортировка данных по критерию
void Sorting(Elem* e, int n, int k) throw (Oshibka&)
{
	try
	{
		Elem buffer;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (e[i].GetProduct().property[k] > e[j].GetProduct().property[k])
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
		System::Windows::Forms::MessageBox::Show("Что-то пошло не так", "Ошибка!");
	}
}

// Сохранение в файл
bool SaveToFile(Elem* (&e), int& n, int state, std::string filename) throw (Oshibka&)
{
	std::ofstream ofile(filename);
	try
	{
		if (ofile)
		{
			ofile << n << " " << state << std::endl;
			
			for (int i = 0; i < n; i++)
			{
				ofile << e[i].GetSupplier() << std::endl;
				ofile << e[i].GetProduct().name << std::endl;
				ofile << e[i].GetProduct().property[0] << " " << e[i].GetProduct().property[1] << " " << e[i].GetProduct().property[2] << " "
					<< e[i].GetProduct().property[3] << " " << e[i].GetProduct().property[4] << " " << e[i].GetProduct().property[5] << " "
					<< e[i].GetProduct().property[6] << std::endl;
				ofile << e[i].GetProduct().relevance;
				
				if (i < n - 1)
				{
					ofile << std::endl;
				}
			}
		}
		else
		{
			throw Oshibka("Проблема с открытием файла!");
		}
	}
	catch (Oshibka& o)
	{
		System::Windows::Forms::MessageBox::Show(stoS(o.GetNazv()), "Ошибка!");
		ofile.close();
		return false;
	}
	catch (...)
	{
		System::Windows::Forms::MessageBox::Show("Что-то пошло не так", "Ошибка!");
		ofile.close();
		return false;
	}
	ofile.close();
	return true;
}

// Применение метода TOPSIS
void ApplyTopsis(Elem* (&e), int& n) throw (Oshibka&)
{
	const int size = 7;
	const double w[size] = { 0.23, 0.23, 0.15, 0.15, 0.08, 0.08, 0.08 };
	double* normc = new double[size * n];
	double* pos = new double[n];
	double* neg = new double[n];
	double aplus[size];
	double aminus[size];
	double prom[size] = {0};
	try
	{
		// Промежуточные значения для нормирования коэффициент
		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < n; i++)
			{
				prom[j] = prom[j] + pow(e[i].GetProduct().property[j], 2);
			}
			prom[j] = sqrt(prom[j]);
		}
		// Заполняем массив нормированными взвешенными коэффициентами
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < size; j++)
			{
				normc[i * size + j] = e[i].GetProduct().property[j] / prom[j] * w[j];
				normc[i * size + j] = int(normc[i * size + j] * 1000 + 0.5) / 1000.;
			}
		}
		// Заполняем таблицу идеальных решений
		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < n; i++)
			{
				if (i == 0)
				{
					aplus[j] = normc[j];
					aminus[j] = normc[j];
				}
				else
				{
					if (normc[i * size + j] < aminus[j])
					{
						aminus[j] = normc[i * size + j];
					}
					if (normc[i * size + j] > aplus[j])
					{
						aplus[j] = normc[i * size + j];
					}
				}
			}
		}
		// Заполняем таблицы близости
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (j == 0)
				{
					pos[i] = 0.;
					neg[i] = 0.;
				}
				else
				{
					pos[i] = pos[i] + pow(aplus[j] - normc[i * size + j], 2);
					neg[i] = neg[i] + pow(normc[i * size + j] - aminus[j], 2);
				}
			}
			pos[i] = sqrt(pos[i]);
			neg[i] = sqrt(neg[i]);
			pos[i] = int(pos[i] * 1000 + 0.5) / 1000.;
			neg[i] = int(neg[i] * 1000 + 0.5) / 1000.;
		}
		for (int i = 0; i < n; i++)
		{
			e[i].SetRelevance(int(neg[i] / (neg[i] + pos[i]) * 1000 + 0.5) / 1000.);
		}
	}
	catch (...)
	{
		System::Windows::Forms::MessageBox::Show("Что-то пошло не так", "Ошибка!");
	}
	delete[] normc;
	delete[] pos;
	delete[] neg;
}

// Применение оригинального метода
void ApplyMCDM(Elem* (&e), int& n) throw (Oshibka&)
{
	const int size = 7;
	const double w[size] = { 0.23, 0.23, 0.15, 0.15, 0.08, 0.08, 0.08 };
	const double selectionCoeff = 0.05;
	int changeCoeff;
	int weightedAverage;
	double* normc = new double[size * n];
	double* pos = new double[n];
	double* neg = new double[n];
	double aplus[size];
	double aminus[size];
	double prom[size] = { 0 };
	try
	{
		// Применение промежуточного среднего
		changeCoeff = int(floor(n * selectionCoeff));
		for (int j = 0; j < size; j++)
		{
			Sorting(e, n, j);
			weightedAverage = 0;
			for (int i = changeCoeff; i < n - changeCoeff; i++)
			{
				weightedAverage = weightedAverage + e[i].GetProduct().property[j];
			}
			if (changeCoeff != 0)
			{
				weightedAverage = weightedAverage / (2 * changeCoeff);
			}
			for (int i = 0; i < changeCoeff; i++)
			{
				e[i].SetProperty(j, weightedAverage);
			}
			for (int i = n - 1; i > n - changeCoeff - 1; i--)
			{
				e[i].SetProperty(j, weightedAverage);
			}
		}
		// Промежуточные значения для нормирования коэффициент
		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < n; i++)
			{
				prom[j] = prom[j] + pow(e[i].GetProduct().property[j], 2);
			}
			prom[j] = sqrt(prom[j]);
		}
		// Заполняем массив нормированными взвешенными коэффициентами
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < size; j++)
			{
				normc[i * size + j] = e[i].GetProduct().property[j] / prom[j] * w[j];
				normc[i * size + j] = int(normc[i * size + j] * 1000 + 0.5) / 1000.;
			}
		}
		// Заполняем таблицу идеальных решений
		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < n; i++)
			{
				if (i == 0)
				{
					aplus[j] = normc[j];
					aminus[j] = normc[j];
				}
				else
				{
					if (normc[i * size + j] < aminus[j])
					{
						aminus[j] = normc[i * size + j];
					}
					if (normc[i * size + j] > aplus[j])
					{
						aplus[j] = normc[i * size + j];
					}
				}
			}
		}
		// Заполняем таблицы близости
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (j == 0)
				{
					pos[i] = 0.;
					neg[i] = 0.;
				}
				else
				{
					pos[i] = pos[i] + pow(aplus[j] - normc[i * size + j], 2);
					neg[i] = neg[i] + pow(normc[i * size + j] - aminus[j], 2);
				}
			}
			pos[i] = sqrt(pos[i]);
			neg[i] = sqrt(neg[i]);
			pos[i] = int(pos[i] * 1000 + 0.5) / 1000.;
			neg[i] = int(neg[i] * 1000 + 0.5) / 1000.;
		}
		for (int i = 0; i < n; i++)
		{
			e[i].SetRelevance(int(neg[i] / (neg[i] + pos[i]) * 1000 + 0.5) / 1000.);
		}
	}
	catch (...)
	{
		System::Windows::Forms::MessageBox::Show("Что-то пошло не так", "Ошибка!");
	}
	delete[] normc;
	delete[] pos;
	delete[] neg;
}

// Опустошить файл
void ClearFile(std::string filename)
{
	std::ofstream delfile(filename, std::ios::out | std::ios::trunc);
	delfile.close();
}

// Функции преобразования типов
// Из фронтенда в бэкенд
std::string& Stos(System::String^ s)
{
	std::string n_s;
	const char* ch = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s)).ToPointer();
	n_s = ch;

	System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)ch));
	return n_s;
}

// Из бэкенда в фронтенд
System::String^ stoS(std::string& s)
{
	System::String^ n_s = gcnew System::String(s.c_str());
	return n_s;
}

// Из фронтенда в бэкенд
std::string& S_to_s(System::String^ s_o, std::string& s_n)
{
	const char* ch = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s_o)).ToPointer();
	s_n = ch;

	System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)ch));
	return s_n;
}

// Нахождение среднего значения релевантности
double FindAverageRelevance(Elem* e, int n) throw (Oshibka&)
{
	double avg = 0.;

	try
	{
		for (int i = 0; i < n; i++)
		{
			avg = avg + e[i].GetProduct().relevance;
		}
		avg = int(avg / n * 1000 + 0.5) / 1000.;
	}
	catch (...)
	{
		System::Windows::Forms::MessageBox::Show("Что-то пошло не так", "Ошибка!");
	}

	return avg;
}
