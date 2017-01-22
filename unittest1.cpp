#include "stdafx.h"
#include "CppUnitTest.h"
#include "Gauss_Methods.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{// TODO: Your test code here
			double X1[3][3] = { { 1.0,13.0,1.0 },{ 1.0,2.0,3.0 },{ 1.0,4.0,7.0 } }; 
			double Y1[3] = { 6.0, 5.0, 9.0 };
			double R[3] = { 1.875,0.25,0.875 };

			double **X = new double*[3];
			for (int i = 0; i < 3; i++)
				X[i] = new double[3];
			for (int i = 0; i < 3; i++) 
				for (int j = 0; j < 3; j++)
					X[i][j] = X1[i][j];
			double *Y = new double[3];
			for (int i = 0; i < 3; i++)
				Y[i] = Y1[i];

			double *Out;
			Out = methods::GaussMethod(3, (double **)X1, &Y);
			double eps = 0.2;

			for (int i = 0; i < 3; i++)
			{
				Assert::AreNotEqual(Out[i], R[i]);
			}
		}

	};
}