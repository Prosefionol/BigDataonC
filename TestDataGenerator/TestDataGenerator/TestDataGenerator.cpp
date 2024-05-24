#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main()
{
    const int criteria = 7; // Количество критериев
    std::ofstream fout; // Заполняемый файл
    int n; // Количество поставщиков

    std::srand(std::time(0));

    fout.open("input.txt");
    std::cin >> n;

    if (fout.is_open())
    {
        fout << n << " 0" << std::endl;
        for (int i = 0; i < n; i++)
        {
            fout << "Postavchik" << i << std::endl;
            fout << "Product" << std::endl;
            fout << (rand() % 10) + 1;
            for (int j = 1; j < criteria; j++)
            {
                fout << " " << (rand() % 10) + 1;
            }
            fout << std::endl;
            fout << "0." << std::endl;
        }
    }

    fout.close();
}
