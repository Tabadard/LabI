#include "stdafx.h"
#include "CppUnitTest.h"
#include "Gauss_Methods.h"
#include "Gauss_Methods.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace methods;

namespace GaussTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			double X1[3][3] = { { 1.0,13.0,1.0 },{ 1.0,2.0,3.0 },{ 1.0,4.0,7.0 } };
			double Y1[3] = { 6.0, 5.0, 9.0 };
			double R[3] = { 1.875,0.25,0.875 };

			double X2[4][4] = { {7,4,3,1},{3,13,27,2},{9,10,2,3},{90,14,53,4} };
			double Y2[4] = { 12,8,4,8 };
			double R2[4] = { 2.056578,15.34082,-3.337,-53.74764 };

			double *Out;

			Out = GaussMethod(3, (double **)X1, (double**)Y1);

			for (int i = 0; i < 3; i++)
			{
				Assert::IsTrue(abs(Out[i] - R[i]) < eps);
			}

			Out = GaussMethod(3, (double **)X2, (double **)Y2);

			for (int i = 0; i < 3; i++)
			{
				Assert::IsTrue(abs(Out[i] - R2[i]) < eps);
			}
		}

	};
}