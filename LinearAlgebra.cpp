//this is an implementation file for LinearAlgebra.h

#include <iostream>
#include <cmath>
#include "D://Git/mathematics-with-cpp/LinearAlgebra.h"

using namespace std;

LinearAlgebra::LinearAlgebra() {}
	int LinearAlgebra::det(int** arr, int N) {																//function to compute determinant
		int determinant = 0;
		int** minorArray;
		if (N == 1) {
			return *arr[0];
		}
		for (int i = 0; i < N; i++) {
			minorArray = minor(arr, N, 0, i);
			determinant += pow(-1, i) * (*(arr[0] + i)) * det(minorArray, N - 1);
		}
		return determinant;
	}

	int** LinearAlgebra::adjoint(int** arr, int N) {														//function to compute adjoint of the matrix
		int** cof = cofactor(arr, N);
		int** adj = new int* [N];
		for (int i = 0; i < N; i++) {
			adj[i] = new int[N];
			for (int j = 0; j < N; j++) {
				adj[i][j] = cof[j][i];
			}
		}
		return adj;
	}

	float** LinearAlgebra::inverse(int** arr, int N) {														//function to compute inverse of a matrix
		float determinant = (float)det(arr, N);
		float** null;
		if (determinant == 0) {
			cout << "The Inverse of the Matrix does not exist." << endl;
			return null;
		}
		int** adj = adjoint(arr, N);
		float** inv = new float* [N];
		for (int i = 0; i < N; i++) {
			inv[i] = new float[N];
			for (int j = 0; j < N; j++) {
				inv[i][j] = (1 / determinant) * (float)adj[i][j];
			}
		}
		return inv;
	}

	void LinearAlgebra::printMatrix(float* arr, int N) {													//function for printing a float array
		for (int i = 0; i < N; i++) {
			cout << *(arr + i) << " ";
		}
		cout << endl;
	}

	void LinearAlgebra::printMatrix(int* arr, int N) {													//function for printing a float array
		for (int i = 0; i < N; i++) {
			cout << *(arr + i) << " ";
		}
		cout << endl;
	}

	void LinearAlgebra::printMatrix(double* arr, int N) {													//function for printing a float array
		for (int i = 0; i < N; i++) {
			cout << *(arr + i) << " ";
		}
		cout << endl;
	}

	int** LinearAlgebra::minor(int** arr, int N, int p, int q) {											//function to compute minor of an element is a matrix
		int** min;
		min = new int* [N - 1];
		for (int i = 0; i < N - 1; i++) {
			min[i] = new int[N - 1];
		}
		for (int i = 0; i < N; i++) {
			if (i == p) {
				continue;
			}
			for (int j = 0; j < N; j++) {
				if (j == q) {
					continue;
				}
				if (i < p && j < q) {
					min[i][j] = *(arr[i] + j);
				}
				if (i < p && j > q) {
					min[i][j - 1] = *(arr[i] + j);
				}
				if (i > p&& j < q) {
					min[i - 1][j] = *(arr[i] + j);
				}
				if (i > p&& j > q) {
					min[i - 1][j - 1] = *(arr[i] + j);
				}
			}
		}
		return min;
	}

	int** LinearAlgebra::cofactor(int** arr, int N) {														//function to compute the cofactor matrix
		int** cof = new int* [N];
		int** min;
		for (int i = 0; i < N; i++) {
			cof[i] = new int[N];
			for (int j = 0; j < N; j++) {
				min = minor(arr, N, i, j);
				cof[i][j] = pow(-1, i + j) * det(min, N - 1);
			}
		}
		return cof;
	}