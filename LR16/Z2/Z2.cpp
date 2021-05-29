// Z2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
	int N=15;
	int M=2;
	int** T;
	//initializing dynamic arrays
	T = new int* [N];
	for (int i = 0; i < N; i++)
		T[i] = new int[M];
	//element of row + element of row
	int* sum = new int [N];
	for (int i = 0; i < N; i++)
		sum[i] = 0;
	//filling original matriux
	for (int i = 0; i < N; i++) {
		cout << "\n";
		for (int j = 0; j < M; j++) {
			T[i][j] = rand() % 100 - 50;
			printf("|%3d", T[i][j]);
		}
		printf("|");
	}
	//sum of elements in each row
	cout << "\n-----Sum of neighbor rows-----\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum[i] += T[i][j];
		}
	}
	//initializing dynamic array(row+row)
	int* sum_tmp = new int[N-1];
	for (int i = 0; i < N-1; i++)
		sum_tmp[i] = 0;
	//output sum of row+row
	for (int i = 0; i < N-1; i++) {
		sum_tmp[i] += sum[i] + sum[i + 1];
		cout << i + 1 << "+" << i + 2 << ":" << sum_tmp[i]<<"\n";
	}
	//finding minimal sum
	int min_val = sum_tmp[0];
	int pos=0;
	for (int i = 0; i < N - 1; i++) {
		if (sum_tmp[i] < min_val) {
			min_val = sum_tmp[i];
			pos = i;
		}
	}
	cout << "------------------------------\n";
	//outup minimal
	cout <<"Minimal:"<<min_val;
}
