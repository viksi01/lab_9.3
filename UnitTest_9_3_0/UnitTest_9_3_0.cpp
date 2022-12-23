#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_9.3/lab_9.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest930
{
	TEST_CLASS(UnitTest930)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Price* p = new Price;
			p->ProductName = "A";
			p->StoreName = "F";
			p->cost = 30.;
			double t = BinSearch(p, 1, "A");
			Assert::AreEqual(t, 0.);
		}
	};
}
