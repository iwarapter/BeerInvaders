#include "stdafx.h"
#include "CppUnitTest.h"
#include "Vector2D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BeerInvadersUnitTests
{		
	TEST_CLASS(Vector2D_Tests)
	{
	public:
		
		TEST_METHOD(Vector2D_isZero)
		{
			// TODO: Your test code here
			Vector2D v1(0.0,0.0);
			Assert::IsTrue(v1.isZero());
		}

		TEST_METHOD(Vector2D_Zero)
		{
			//instantiate vector of value 1, 1 this should not be 
			Vector2D v1(1.0,1.0);
			v1.Zero();
			Assert::IsTrue(v1.x == 0.0 && v1.y == 0.0);
		}

		TEST_METHOD(Vector2D_Length)
		{
			Vector2D v1(1.0, 0.0);

			Assert::IsTrue(v1.Length() == 1.0);
		}

		TEST_METHOD(Vector2D_LengthSq)
		{
			//x * x + y * y
			//(2 * 2) + (2 * 2) = (4 + 4) = 8

			Vector2D v1(2.0, 2.0);
			Assert::IsTrue(v1.LengthSq() == 8.0);
		}

		TEST_METHOD(Vector2D_Dot)
		{
			//x * v2.x + y * v2.y;
			//(2 * 3) + (2 * 3) = (6 + 6) = 12
			
			Vector2D v1(2.0, 2.0);
			Vector2D v2(3.0, 3.0);
			Assert::IsTrue(v1.Dot(v2) == 12.0f);
		}
	};
}