#include <iostream>
#include <random>
#include "Gauss_Methods.h"

void methods::GenerateRandom(unsigned long raws, unsigned columns, double **X)
{
	std::random_device rt;
	std::mt19937 generator(rt());
	std::uniform_int_distribution<int> ur(MIN, MAX);

	for (unsigned long i = 0; i < raws; i++)
	{
		for (unsigned long j = 0; j < columns; j++)
		{
			X[i][j] = ur(generator);
		}
	}
}

void methods::Show(unsigned long raws, unsigned long columns, double **X)
{
	for (unsigned long i = 0; i < raws; i++)
	{
		for (unsigned long j = 0; j < columns; j++)
		{
			std::cout << X[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void methods::exchangeraws(double **X, unsigned long fraw, unsigned long sraw, unsigned long size)
{
	double temp;
	for (unsigned long i = 0; i < size; i++)
	{
		temp = X[fraw][i];
		X[fraw][i] = X[sraw][i];
		X[sraw][i] = temp;
	}
}

double * methods::GaussMethod(unsigned long size, double ** X, double ** Y)
{
	double * result = new double[size];
	double max;
	//const double eps = 0.0000001;
	unsigned long index;
	for (unsigned long i = 0; i < size; i++)
	{
		max = abs(X[i][i]);
		index = i;
		for (unsigned long j = i + 1; j < size; j++)
		{
			if (abs(X[j][i] > max))
			{
				max = abs(X[j][i]);
				index = j;
			}
		}
		if (max < eps)
		{
			std::cout << "There is a 0 - vector here! Can't get result!\n";
			return 0;
		}

		methods::exchangeraws(X, i, index, size);
		double temp = Y[0][i];
		Y[0][i] = Y[0][index];
		Y[0][index] = temp;

		for (unsigned long j = i; j < size; j++)
		{
			double temp = X[j][i];
			if (abs(temp) < eps)
				continue;
			for (unsigned long k = 0; k < size; k++)
				X[j][k] = X[j][k] / temp;
			Y[0][j] = Y[0][j] / temp;
			if (j == i)
				continue;
			for (unsigned long k = 0; k < size; k++)
				X[j][k] = X[j][k] - X[i][k];
			Y[0][j] = Y[0][j] - Y[0][i];
		}
	}

	for (long i = size - 1; i >= 0; i--)
	{
		result[i] = Y[0][i];
		for (long j = 0; j < i; j++)
		{
			Y[0][j] = Y[0][j] - X[j][i] * result[i];
		}
	}

	return result;
}
