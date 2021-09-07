#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
using namespace std;
int main()
{
	int choose = -1;
	while (choose != 0) {
		int const size = 10;
		int A[size];
		//Initializing array with random numbers
		for (int i = 0; i < 10; i++) {
			A[i] = rand() % 100 - 50;
		}
		//printing unsorted(original) array
		printf("%15s","Unsorted array:");
		for (int i = 0; i < 10; i++) {
			printf("%3d%3s",A[i]," | ");
		}
		cout << '\n';

		//initial, sorting pozitive|negative
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if ((A[j] >= 0)) {
					int temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}
		}

		//Negative, sort in descending order
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if ((A[j] < A[j + 1]) && (A[j + 1] < 0) && (A[j] < 0)) {
					int temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}
		}

		//Positive sort in ascending order
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if ((A[j] > A[j + 1]) && (A[j + 1] >= 0) && (A[j] >= 0)) {
					int temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}
		}

		//printing Sorted array
		printf("%15s", "Sorted array:");
		for (int i = 0; i < 10; i++) {
			printf("%3d%3s", A[i], " | ");
		}
		cout << '\n';

		choose = -1;
		while (choose != 1 && choose != 0) {
			cout << "Continue?(1-yes,0-no)";
			cin >> choose;
			system("cls");
			if (choose == 0) return 0;
		}


	}
}