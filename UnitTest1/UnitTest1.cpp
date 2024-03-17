#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2.6/TimeC.h"
#include "../lab2.6/TimeC.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			TimeC t1;
			int test = t1.getCounter();
			Assert::AreEqual(1, test);
		}
	};
}
