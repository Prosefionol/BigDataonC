#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>

int main(void)
{
	int i;
	double w, w1;
	FILE* fout = fopen("Output.txt", "w");
	for (i = 0; i < 1000; i++)
	{
		const char* supplier[] = { "Postavchik_A","Postavchik_B","Postavchik_C",0 };
		int nSupplier = 0;
		while (supplier[nSupplier]) nSupplier++;
		fprintf(fout, "%s\n", supplier[rand() % nSupplier]);

		const char* product[] = { "Holodil'nik","Konditsioner","Holodil'naya_vetrina","Lari","Holodil'niy_stol","Vitrina","Perenosnoy_holodil'nik","Ice_generator","Frizer",0 };
		int nProduct = 0;
		while (product[nProduct]) nProduct++;
		fprintf(fout, "%s\n", product[rand() % nProduct]);

		w = double((rand() % 9999 + 1)) / 100;
		fprintf(fout, "%2.2f ", w);
		w1 = double((rand() % 4999 + 1)) / 100;
		fprintf(fout, "%2.2f\n", w1);
	}
	fclose(fout);
	return 0;
}