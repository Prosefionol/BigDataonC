#include "BFunc.h"

int main()
{
	int n = 0;
	Elem* e = new Elem[n];
	GetFromFile(e, n, "input.txt");
	SortingRelevance(e, n);
	SaveToFile(e, n, "output.txt");
	delete[] e;
	return 0;
}