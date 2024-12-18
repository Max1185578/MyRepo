#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Юрий\source\repos\MyRepo\SELab\SELab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ValidParams)
		{
			double a = -5;
			double b = 5;
			double nx = 1;
			int n = 3;
			int exepted = 1;

			int actual = CheckValidParams(a, b, nx, n);

			Assert::AreEqual(exepted, actual);
		}
		TEST_METHOD(CalculateIteration1)
		{
			int n = 3;
			double x = -1;
			double exepted = 0.125;
			double actual = CalculateIteration(x, n);

			Assert::AreEqual(exepted, actual);
		}
		TEST_METHOD(CalculateIteration2)
		{
			int n = 4;
			double x = 5;
			double exepted = 799220;
			double actual = CalculateIteration(x, n);

			Assert::AreEqual(exepted, actual);
		}
		TEST_METHOD(CalculateIterationFaule)
		{
			int n = 3;
			double x = 2.3;
			double exepted = 26.53; //2662.5
			double actual = int(CalculateIteration(x, n) * 10);
			actual = actual / 10;

			Assert::AreEqual(exepted, actual);
		}


	};
}
