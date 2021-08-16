#include "stdafx.h"
#include "LUP.h"

int ** CreateMatrix(int n)
{
	int ** matrix = new int *[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}

	return matrix;
}

int BearingElementIndex(int ** matrix, int k, int n)
{
	int max = matrix[k][k];
	int num = k;
	for (int i = k; i < n; i++)
	{
		if (max < matrix[i][k])
		{
			max = matrix[i][k];
			num = i;
		}
	}

	if (max == 0)
		return -1;
	else 
		return num;
}

void SwapRows(int ** matrix, int m, int k)
{
	int * l;
	l = matrix[k];
	matrix[k] = matrix[m];
	matrix[m] = l;
}

bool Prime(int q)
{
	if (q == 2 || q == 3) return true;
	for (int i = 2; i <= sqrt(q); i++)
	{
		if ((q%i) == 0)
			return false;
	}
	return true;
}

int Opposite(int a, int q)
{
	if (q == 2 || q == 3)
		return a;

	int p = q - 2, b, r = 1, log = (int)(log2(q - 2));
	for (int i = 1; i <= log; i++)
	{
		b = a;
		p = p / 2;
		if (p % 2 == 1)
		{
			for (int j = 0; j < i; j++)
				b = (b * b) % q;
			r = (r * b) % q;
		}

	}

	if ((q - 2) % 2 == 1)
		r = (r * a) % q;

	return r;
}

int Multiplication(int a, int b, int q)
{
	return (a * b) % q;
}

int Mod(int a, int b, int q)
{
	return (a + b + q) % q;
}

bool LUP(int ** matrix, int q, int * pi, int n)
{
	if (!Prime(q))
		return false;
	
	for (int k = 0; k < n - 1; k++)
	{
		int num = BearingElementIndex(matrix, k, n);
		if (num == -1) 
			break;
		SwapRows(matrix, num, k);
		int temp;
		temp = pi[k];
		pi[k] = pi[num];
		pi[num] = temp;

		for (int i = k + 1; i < n; i++)
			matrix[i][k] = Multiplication(matrix[i][k], Opposite(matrix[k][k], q), q);

		for (int i = k + 1; i < n; i++)
			for (int j = k + 1; j < n; j++)
				matrix[i][j] = Mod(matrix[i][j], - Multiplication(matrix[i][k], matrix[k][j], q), q);
	}

	for (int i = 0; i < n; i++)
	{
		if (BearingElementIndex(matrix, i, n) == -1) 
			return false;   //проверка на обратимость
	}

	return true;
}

int * Solution(int ** matrix, int * mas, int * pi, int q, int n)
{
	if (!LUP(matrix, q, pi, n))
		return NULL;

	int * y = new int[n];
	y[0] = mas[pi[0]];
	for (int i = 1; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < i; j++)
		{
			sum = Mod(sum, Multiplication(y[j], matrix[i][j], q), q);
		}
		y[i] = Mod(mas[pi[i]], - sum, q);
	}

	int * x = new int[n];
	x[n - 1] = Multiplication(Opposite(matrix[n - 1][n - 1], q), y[n - 1], q);
	for (int i = n - 2; i >= 0; i--)
	{
		int sum = 0;
		for (int j = i + 1; j < n; j++)
		{
			sum = Mod(sum, Multiplication(x[j], matrix[i][j], q), q);
		}
		x[i] = Multiplication(Mod(y[i], - sum, q), Opposite(matrix[i][i], q), q);
	}

	delete[] y;

	return x;
}
 
bool Equation(int * mas1, int * mas2)
{
	if (mas1 == NULL || mas2 == NULL)
		return true;
	else
	{
		bool flag = true;
		for (int i = 0; i < (sizeof(mas1) / sizeof(mas1[0])); i++)
		{
			if (mas1[i] != mas2[i])
			{
				flag = false;
				return flag;
			}
		}
		return flag;
	}
}

void OutputMatrix(int ** matrix, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
			cout << matrix[i][j];
	}
}

void DeleteMatrix(int ** matrix, int n)
{
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
}

