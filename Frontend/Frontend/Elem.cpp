#include "Elem.h"

Elem::Elem()
{
	supplier = "";

	pr.name = "";
	pr.property[0] = 0;
	pr.property[1] = 0;
	pr.property[2] = 0;
	pr.property[3] = 0;
	pr.property[4] = 0;
	pr.property[5] = 0;
	pr.property[6] = 0;
	pr.property[7] = 0;
	pr.relevance = 0.0;
}

Elem::Elem(std::string supplier_, Product pr_)
{
	supplier = supplier_;

	pr.name = pr_.name;
	pr.property[0] = pr_.property[0];
	pr.property[1] = pr_.property[1];
	pr.property[2] = pr_.property[2];
	pr.property[3] = pr_.property[3];
	pr.property[4] = pr_.property[4];
	pr.property[5] = pr_.property[5];
	pr.property[6] = pr_.property[6];
	pr.property[7] = pr_.property[7];
	pr.relevance = pr_.relevance;
}

Elem::~Elem()
{
}

void Elem::Print()
{
	std::cout << supplier << std::endl;
	std::cout << pr.name << std::endl;
	std::cout << pr.property[0] << " " << pr.property[1] << " " << pr.property[2] << " " << pr.property[3] << " "
		<< pr.property[4] << " " << pr.property[5] << " " << pr.property[6] << " " << pr.property[7] << " " << std::endl;
	std::cout << pr.relevance << std::endl;
}

void Elem::GetDatabase(std::string supplier_, Product pr_)
{
	supplier = supplier_;

	pr.name = pr_.name;
	pr.property[0] = pr_.property[0];
	pr.property[1] = pr_.property[1];
	pr.property[2] = pr_.property[2];
	pr.property[3] = pr_.property[3];
	pr.property[4] = pr_.property[4];
	pr.property[5] = pr_.property[5];
	pr.property[6] = pr_.property[6];
	pr.property[7] = pr_.property[7];
	pr.relevance = pr_.relevance;
}

Elem& Elem::operator= (Elem eold)
{
	this->supplier = eold.supplier;

	this->pr.name = eold.pr.name;
	this->pr.property[0] = eold.pr.property[0];
	this->pr.property[1] = eold.pr.property[1];
	this->pr.property[2] = eold.pr.property[2];
	this->pr.property[3] = eold.pr.property[3];
	this->pr.property[4] = eold.pr.property[4];
	this->pr.property[5] = eold.pr.property[5];
	this->pr.property[6] = eold.pr.property[6];
	this->pr.property[7] = eold.pr.property[7];
	this->pr.relevance = eold.pr.relevance;

	return *this;
}