#pragma once

#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

// Структура для хранения информации о продукции
struct Product
{
	std::string name;
	int property[7];
	double relevance;
};

class Elem
{
private:
	std::string supplier;
	Product pr;
public:
	Elem();
	Elem(std::string supplier_, Product pr_);
	~Elem();

	void Print();
	void GetDatabase(std::string supplier_, Product pr_);
	std::string GetSupplier()
	{
		return supplier;
	}
	Product GetProduct()
	{
		return pr;
	}
	void SetRelevance(double rel)
	{
		pr.relevance = rel;
	}
	void SetProperty(int k, int prop)
	{
		pr.property[k] = prop;
	}

	Elem& operator= (Elem eold);
};


