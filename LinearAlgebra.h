#pragma once

#include <iostream>

class LinearAlgebra {
public:LinearAlgebra();
	  int det(int** arr, int N);
	  int** adjoint(int** arr, int N);
	  float** inverse(int** arr, int N);
	  void printMatrix(float* arr, int N);
	  void printMatrix(int* arr, int N);
	  void printMatrix(double* arr, int N);

private:int** minor(int** arr, int N, int p, int q);
	   int** cofactor(int** arr, int N);
};
