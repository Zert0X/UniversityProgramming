// Z2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
const int m = 5, n = 5;
template <typename T>
void sort(T* arr, bool obj) {
	int min_max_arr[n][2];
	//finding min_max_arr
	if (obj) {
		for (int j = 0; j < n;j++) {
			int tmp_max = arr[0][j];
			for (int i = 0; i < m; i++) {
				if (arr[i][j] < tmp_max) {
					tmp_max = arr[i][j];
				}
			}
			min_max_arr[j][0] = tmp_max;
			min_max_arr[j][1] = j;
		}
	}
	else {
		for (int j = 0; j < n; j++) {
			int tmp_min = arr[0][j];
			for (int i = 0; i < m; i++) {
				if (arr[i][j] > tmp_min)
					tmp_min = arr[i][j];
			}
			min_max_arr[j][0] = tmp_min;
			min_max_arr[j][1] = j;
		}
	}

	//sorting min_max_arr
	if (obj) {
		for (int i = 0; i < n; i++){
			for(int j = 0;j<n-1;j++)
				if (min_max_arr[j][0] > min_max_arr[j + 1][0]) {
					swap(min_max_arr[j][0], min_max_arr[j + 1][0]);
					swap(min_max_arr[j][1], min_max_arr[j + 1][1]);
				}
		}
			
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++)
				if (min_max_arr[j][0] < min_max_arr[j + 1][0]) {
					swap(min_max_arr[j][0], min_max_arr[j + 1][0]);
					swap(min_max_arr[j][1], min_max_arr[j + 1][1]);
				}
		}
	}

	//swapping columns in arr
	int arr_tmp[m][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr_tmp[j][i] = arr[j][min_max_arr[i][1]];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = arr_tmp[i][j];
		}
	}
	cout << "Sequence:";
	for (int i = 0; i < n; i++) {
			cout << min_max_arr[i][0]<<"|";
	}
}

int main()
{
	
	int arr[m][n];
	for (int i = 0; i < m; i++) {
		cout << "\n";
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 100 - 20;
			printf("|%3d", arr[i][j]);
		}
		printf("|");
	}

	int obj=2;
	while (obj != 0 && obj != 1) {
		cout << "\nChoose objective:\n 0 - A\n 1 - B\n";
		cin >> obj;
	}
	sort(arr, obj);
	for (int i = 0; i < m; i++) {
		cout << "\n";
		for (int j = 0; j < n; j++) {
			printf("|%3d", arr[i][j]);
		}
		printf("|");
	}
}
