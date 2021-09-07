#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
int main()
{
	const int m = 5, n = 5;
	int A[m][n];
	//Initializing matrix with random digital
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = rand() % 100 - 50;
		}
	}
	//printing unsorted matrix
	printf("%16s", "Unsorted matrix:\n");
	for (int i = 0; i < m; i++) {
		printf("%31s", "------------------------------\n|");
		for (int j = 0; j < n; j++) {
			printf("%3d%2s", A[i][j], " | ");
		}
		printf("\n");
	}
	printf("%31s", "------------------------------\n");

	//founding multiple of five
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] % 5 == 0) {

				//sorting column with multiple of five
				for (int o = 0; o < m - 1; o++) {
					for (int k = 0; k < n - o - 1; k++) {
						if (A[k][j] < A[k + 1][j]) {
							int temp = A[k][j];
							A[k][j] = A[k + 1][j];
							A[k + 1][j] = temp;
						}

					}
				}

			}
		}
	}
	//printing sorted matrix
	printf("%16s", "Sorted matrix:\n");
	for (int i = 0; i < m; i++) {
		printf("%31s", "------------------------------\n|");
		for (int j = 0; j < n; j++) {
			printf("%3d%2s", A[i][j], " | ");
		}
		printf("\n");
	}
	printf("%31s", "------------------------------\n");
}
