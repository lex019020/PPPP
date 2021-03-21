#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_2/Source.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace unit_test1
{
	TEST_CLASS(unit_test1)
	{
	public:
		
		TEST_METHOD(test_zeros)
		{
			string ret;
			SolveSystem(0, 0, 0, 0, 0, 0, &ret);
			Assert::AreEqual(ret.c_str(), "5");
		}

		TEST_METHOD(test_no_solution)
		{
			string ret;
			SolveSystem(2, 0, 1, 0, 1, 1, &ret);
			Assert::AreEqual(ret.c_str(), "0");
		}

		TEST_METHOD(test_no_solution_2)
		{
			string ret;
			SolveSystem(2, 4, 1, 2, 2, 2, &ret);
			Assert::AreEqual(ret.c_str(), "0");
		}

		TEST_METHOD(test_single_solution)
		{
			string ret;
			SolveSystem(1, 0, 0, 1, 1, 1, &ret);
			Assert::AreEqual(ret.c_str(), "2 1 1");
		}

		TEST_METHOD(test_inf_solutions_ykxn)
		{
			string ret;
			SolveSystem(-2, 1, 0, 0, 0, 0, &ret);
			Assert::AreEqual(ret.c_str(), "1 2 0");
		}

		TEST_METHOD(test_inf_solutions_ykxn_2)
		{
			string ret;
			SolveSystem(0, 0, 2, 1, 0, 0, &ret);
			Assert::AreEqual(ret.c_str(), "1 -2 0");
		}

		TEST_METHOD(test_inf_solutions_ykxn_3)
		{
			string ret;
			SolveSystem(1, 2, 0, 0, 0, 0, &ret);
			Assert::AreEqual(ret.c_str(), "1 -0.5 0");
		}

		TEST_METHOD(test_inf_solutions_ykxn_4)
		{
			string ret;
			SolveSystem(2, 4, 1, 2, 1, 0.5, &ret);
			Assert::AreEqual(ret.c_str(), "1 -0.5 0.25");
		}

		TEST_METHOD(test_inf_solutions_for_y)
		{
			string ret;
			SolveSystem(1, 0, 0, 0, 1, 0, &ret);
			Assert::AreEqual(ret.c_str(), "3 1");
		}

		TEST_METHOD(test_inf_solutions_for_x)
		{
			string ret;
			SolveSystem(0, 1, 0, 0, 1, 0, &ret);
			Assert::AreEqual(ret.c_str(), "4 1");
		}
	};
}
