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
	// ����������� �� ��������� (����������� ������)
	Oshibka():Oshibka("Shto-to poshlo ne tak")
	{
	}
	// ����� ��������� �������� ������
	std::string GetNazv()
	{
		return Nazv;
	}
};

