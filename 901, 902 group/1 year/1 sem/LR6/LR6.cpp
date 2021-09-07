#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
using namespace std;
int main()
{
	int choose=123123213213;

	while (choose != 1 && choose != 0) {
	cout << "Continue?(1-yes,0-no)";
	cin >> choose;
}
	while (choose != 0) {
		int const size = 10;
		int A[size];
		for (int i = 0; i < 10; i++) {
		A[i] = rand() % 100-50;
		}
	for (int i = 0; i < 10; i++) {
			cout << A[i] << ' ';
		}
			cout<<'\n';
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if ((A[j] % 2 != 0)) {
					int temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}
		}
	for (int i = 0; i < 10; i++) {
			cout << A[i] << ' ';
		}
	cout<<'\n';
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if ((A[j] < A[j + 1]) && (A[j + 1] % 2 == 0) && (A[j] % 2 == 0)) {
					int temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}
		}
	for (int i = 0; i < 10; i++) {
			cout << A[i] << ' ';
		}
	cout<<'\n';
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if ((A[j] > A[j + 1]) && (A[j + 1] % 2 != 0) && (A[j] % 2 != 0)) {
					int temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			cout << A[i] << ' ';
		}
		choose = 213213213; 
		
		while (choose != 1 && choose != 0) {
			cout << "Continue?(1-yes,0-no)";
			cin >> choose;
			system("cls");
		}
			
		
	}
}
