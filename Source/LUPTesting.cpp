#include "stdafx.h"
#include "LUP.h"

//q = 5, n = 3
TEST(Test, Test1)
{
	int q = 5, n = 3;
	int ** A = CreateMatrix(n);
	A[0][0] = 1;
	A[0][1] = 4;
	A[0][2] = 3;
	A[1][0] = 2;
	A[1][1] = 1;
	A[1][2] = 0;
	A[2][0] = 4;
	A[2][1] = 0;
	A[2][2] = 1;
	OutputMatrix(A, n);
	cout << endl << endl;

	int * mas = new int[n];
	mas[0] = 1;
	mas[1] = 0;
	mas[2] = 4;
	for (int i = 0; i < n; i++)
		cout << mas[i] << endl;

	int * vectorP = new int[n];
	for (int i = 0; i < n; i++)
		vectorP[i] = i;

	cout << endl;
	int * Y = new int[n];
	Y[0] = 4;
	Y[1] = 2;
	Y[2] = 3;
	for (int i = 0; i < n; i++)
		cout << Y[i] << endl;

	cout << endl;
	int * X = new int[n];
	X = Solution(A, mas, vectorP, q, n);
	DeleteMatrix(A, n);
	ASSERT_EQ(true, Equation(Y, X));
}

//q = 3, n = 1
TEST(Test, Test2)
{
	int q = 3, n = 1;
	int ** A = CreateMatrix(n);
	A[0][0] = 2;

	int * mas = new int[n];
	mas[0] = 1;

	int * vectorP = new int[n];
	for (int i = 0; i < n; i++)
		vectorP[i] = i;
	
	//LUP(A, q, vectorP);

	int * Y = new int[n];
	Y[0] = 2;

	int * X = new int[n];
	X = Solution(A, mas, vectorP, q, n);
	DeleteMatrix(A, n);
	ASSERT_EQ(true, Equation(Y, X));
}

//q = 3, n = 2
TEST(Test, Test3)
{
	int q = 3, n = 2;
	int ** A = CreateMatrix(n);
	A[0][0] = 2;
	A[0][1] = 1;
	A[1][0] = 1;
	A[1][1] = 0;

	int * mas = new int[n];
	mas[0] = 0;
	mas[1] = 1;

	int * vectorP = new int[n];
	for (int i = 0; i < n; i++)
		vectorP[i] = i;

	int * Y = new int[n];
	Y[0] = 1;
	Y[1] = 1;

	int * X = new int[n];
	X = Solution(A, mas, vectorP, q, n);
	DeleteMatrix(A, n);
	ASSERT_EQ(true, Equation(Y, X));
}

//q = 3, n = 3
TEST(Test, Test4)
{
	int q = 3, n = 3;
	int ** A = CreateMatrix(n);
	A[0][0] = 2;
	A[0][1] = 2;
	A[0][2] = 2;
	A[1][0] = 1;
	A[1][1] = 1;
	A[1][2] = 0;
	A[2][0] = 0;
	A[2][1] = 1;
	A[2][2] = 1;

	int * mas = new int[n];
	mas[0] = 1;
	mas[1] = 1;
	mas[2] = 0;

	int * vectorP = new int[n];
	for (int i = 0; i < n; i++)
		vectorP[i] = i;

	int * Y = new int[n];
	Y[0] = 2;
	Y[1] = 2;
	Y[2] = 1;

	int * X = new int[n];
	X = Solution(A, mas, vectorP, q, n);
	DeleteMatrix(A, n);
	ASSERT_EQ(true, Equation(Y, X));
}

//q = 4, n = 1
TEST(Test, Test5)
{
	int q = 4, n = 1;
	int ** A = CreateMatrix(n);
	A[0][0] = 2;

	int * mas = new int[n];
	mas[0] = 1;

	int * vectorP = new int[n];
	for (int i = 0; i < n; i++)
		vectorP[i] = i;

	int * X = new int[n];
	X = Solution(A, mas, vectorP, q, n);
	DeleteMatrix(A, n);
	ASSERT_EQ(true, Equation(NULL, X));
}

//матрица необратима
TEST(Test, Test6)
{
	int q = 5, n = 3;
	int ** A = CreateMatrix(n);
	A[0][0] = 1;
	A[0][1] = 2;
	A[0][2] = 3;
	A[1][0] = 1;
	A[1][1] = 2;
	A[1][2] = 3;
	A[2][0] = 1;
	A[2][1] = 2;
	A[2][2] = 3;

	int * mas = new int[n];
	int * vectorP = new int[n];

	int * X = new int[n];
	X = Solution(A, mas, vectorP, q, n);
	DeleteMatrix(A, n);
	ASSERT_EQ(true, Equation(NULL, X));
}

//матрица необратима
TEST(Test, Test7)
{
	int q = 2, n = 2;
	int ** A = CreateMatrix(n);
	A[0][0] = 1;
	A[0][1] = 1;
	A[1][0] = 1;
	A[1][1] = 1;

	int * mas = new int[n];
	int * vectorP = new int[n];

	int * X = new int[n];
	X = Solution(A, mas, vectorP, q, n);
	DeleteMatrix(A, n);
	ASSERT_EQ(true, Equation(NULL, X));
}

//проверка на простоту
TEST(Test, Test8)
{
	ASSERT_EQ(true, Prime(29));
}

//проверка на простоту
TEST(Test, Test9)
{
	ASSERT_EQ(true, Prime(101));
}

//проверка на простоту
TEST(Test, Test10)
{
	ASSERT_EQ(false, Prime(169));
}

//обратимость, q = 5
TEST(Test, Test11)
{
	int a = 4, q = 5;
	ASSERT_EQ(4, Opposite(a, q));
}

//обратимость, q = 7
TEST(Test, Test12)
{
	int a = 5, q = 7;
	ASSERT_EQ(3, Opposite(a, q));
}

//обратимость, q = 11
TEST(Test, Test13)
{
	int a = 9, q = 11;
	ASSERT_EQ(5, Opposite(a, q));
}