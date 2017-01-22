#include <iostream>
#include <random>
#include "Gauss_Methods.h"

int main()
{
	unsigned long size;
	std::cin >> size;
	double **X = new double*[size];
	double *Y = new double[size];
	for (unsigned long i = 0; i < size; i++)
		X[i] = new double[size];
	methods::GenerateRandom(size, size, X);
	methods::GenerateRandom(1, size, &Y);

	methods::Show(size, size, X);
	std::cout << "\n";
	methods::Show(1, size, &Y);

	Y = methods::GaussMethod(size, X, &Y);

	std::cout << "\n";
	methods::Show(1, size, &Y);
	std::system("pause");
	return 0;
}