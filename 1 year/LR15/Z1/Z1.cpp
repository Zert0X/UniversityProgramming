// Z1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define arr_size 10
#include <iostream>
#include <vector>
template <typename T>
void transform(int* arr, T size) {
	int zero_arr[arr_size];
	int tmp_arr[arr_size];
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] != 0) {
			tmp_arr[counter] = arr[i];
			counter++;
		}
	}
	for (int i = 0; i < size - counter; i++) {
		arr[i] = 0;
	}
	int counter_tmp = 0;
	for (int i = size - counter; i < size; i++) {
		arr[i] = tmp_arr[counter_tmp];
		counter_tmp++;
	}
}
using namespace std;
int main()
{
	const int size = arr_size;
	int arr[size] = {5,5,-2,3,0,-2,0,-4,2,0};
	/*for (int i = 0; i < size; i++) {
		cout << "Enter " << i + 1 << " digit\n";
		cin >> arr[i];
	}*/
	transform(arr, size);
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<"|";
	}
	return 0;
}
