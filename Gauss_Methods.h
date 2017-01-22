#ifndef GAUSS_METHODS
#define GAUSS_METHODS

#define MIN 0
#define MAX 10
#define eps 0.0000001

namespace methods {
	void GenerateRandom(unsigned long raws, unsigned columns, double **X);
	void Show(unsigned long raws, unsigned long columns, double **X);
	void exchangeraws(double **X, unsigned long fraw, unsigned long sraw, unsigned long size);
	double * GaussMethod(unsigned long size, double **X, double **Y);
}
#endif