#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
using namespace std;
int main()
{
	const int m = 6, n = 6;
	int A[m][n];
	//Initializing matrix with random digital
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = rand() % 100 - 50;
		}
	}

	//Printing unsorted matrix
	printf("%16s", "Unsorted matrix:\n");
	for (int i = 0; i < m; i++) {
		printf("%31s","-------------------------------\n|");
		for (int j = 0; j < n; j++) {
			printf("%3d%2s", A[i][j], " |");
		}
		printf("\n");
	}
	printf("%31s", "-------------------------------\n");
	int current = 0; // for current row in matrix
	bool cycle=true; // for cycle between two variations of sorting
	while (current < m) {
		//descendig sort
		if (cycle)
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					if ((A[current][j] < A[current][j+1])) {
						int temp = A[current][j];
						A[current][j] = A[current][j + 1];
						A[current][j + 1] = temp;
					}
					if ((A[current+1][j] < A[current+1][j + 1])) {
						int temp = A[current+1][j];
						A[current+1][j] = A[current+1][j + 1];
						A[current+1][j + 1] = temp;
					}
				}
			}
		//ascending sort
		if (!cycle)
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					if ((A[current][j] > A[current][j+1])) {
						int temp = A[current][j];
						A[current][j] = A[current][j + 1];
						A[current][j + 1] = temp;
					}
					if ((A[current + 1][j] > A[current + 1][j + 1])) {
						int temp = A[current + 1][j];
						A[current + 1][j] = A[current + 1][j + 1];
						A[current + 1][j + 1] = temp;
					}
				}
			}
		//cycle switch
		if (cycle)
			cycle = false;
		else
			cycle = true;
		//current incriment 
		current+=2;
		
	}

	//Printing Sorted matrix
	printf("%16s", "Sorted matrix:\n");
	for (int i = 0; i < m; i++) {
		printf("%31s", "-------------------------------\n|");
		for (int j = 0; j < n; j++) {
			printf("%3d%2s", A[i][j], " |");
		}
		printf("\n");
	}
	printf("%31s", "-------------------------------\n");
}