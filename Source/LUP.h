#pragma once

int ** CreateMatrix(int SizeOfMatrix);
int BearingElementIndex(int ** Matrix, int k, int SizeOfMatrix);
void SwapRows(int ** Matrix, int i, int j);
bool Prime(int q);
int Opposite(int a, int q);
int Multiplication(int a, int b, int q);
int Mod(int a, int b, int q);
bool LUP(int ** Matrix, int q, int * pi, int SizeOfMatrix);
int * Solution(int ** Matrix, int * mas, int * pi, int q, int SizeOfMatrix);
bool Equation(int * left, int * right);
void OutputMatrix(int ** matrix, int n);
void DeleteMatrix(int ** matrix, int SizeOfMatrix);