#pragma once

#include <string>

class Oshibka
{
private:
	std::string Nazv;

public:
	Oshibka(std::string osh)
	{
		Nazv = osh;
	}
	// Конструктор по умолчанию (неизвестная ошибка)
	Oshibka():Oshibka("Shto-to poshlo ne tak")
	{
	}
	// Метод получения названия ошибки
	std::string GetNazv()
	{
		return Nazv;
	}
};

