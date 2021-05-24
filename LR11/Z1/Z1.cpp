#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
using namespace std;

int main()
{
	const int m = 10;
	int A[m], odd[m], even[m];
	for (int i = 0; i < m; i++) {
		A[i] = rand() % 100 - 50;
		
	}
	//printing unsorted(original) array
	printf("%15s", "Unsorted array:");
	for (int i = 0; i < 10; i++) {
		printf("%3d%3s", A[i], " | ");
	}
	cout << '\n';
	int counter_odd = 0;
	int counter_even = 0;
	for (int i = 0; i < m; i++) {
		//odd array filling
		if ((i + 1) % 2 != 0) {
			odd[counter_odd] = A[i];
			counter_odd++;
		}
		//even array filling
		if ((i + 1) % 2 == 0) {
			even[counter_even] = A[i];
			counter_even++;
		}	
	}
	for (int i = 0; i < counter_even; i++) {
		A[i]= even[i];
	}
	int counter=0;
	for (int i = counter_even; i < m; i++) {
		A[i] = odd[counter];
		counter++;
	}
	printf("%15s", "Sorted array:");
	for (int i = 0; i < 10; i++) {
		printf("%3d%3s", A[i], " | ");
	}
}
