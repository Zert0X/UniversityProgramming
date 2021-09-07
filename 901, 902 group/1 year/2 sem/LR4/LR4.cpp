#include <iostream>
#include <string> 
#include <windows.h>
const int m = 6;
const int n = 6;
const int bigest = (n>m) ? n : m;
using namespace std;
void text();
void text(string);
void text(int[], int arr[m][n],boolean);
void initialize(int arr[m][n]);
void menu(int arr[m][n]);
void count_all(int arr[m][n], void out(string s)) {
	int counter[2] = {0,0};
	string s="";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0)
				counter[0]++;
			if (arr[i][j] == 1)
				counter[1]++;
		}
	int tmp = counter[0];
	s = "\nZeros - "+to_string(tmp);
	tmp = counter[1];
	s += "\nOne - " + to_string(tmp)+"\n";
	return out(s);
}
void count_row(int arr[m][n], void out(int[], int arr[m][n], boolean)) {
	int counter[2] = {0,0};
	int rows_arr[m];
	for (int i = 0; i < m; i++) {
		rows_arr[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0)
				counter[0]++;
			if (arr[i][j] == 1)
				counter[1]++;
			

		}
		if ((counter[0] % 2 == 0) & (counter[1] % 2 == 0))
			rows_arr[i] = 1;
		counter[0] = 0;
		counter[1] = 0;
	}
	return out(rows_arr,arr, false);
}
void count_col(int arr[m][n], void out(int[], int arr[m][n], boolean)) {
	int counter[2] = {0,0};
	int col_arr[n];
	for (int i = 0; i < n; i++) {
		col_arr[i] = 0;
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (arr[i][j] == 0)
				counter[0]++;
			if (arr[i][j] == 1)
				counter[1]++;
			

		}
		if ((counter[0] % 2 == 0) & (counter[1] % 2 == 0))
			col_arr[j] = 1;
		counter[0] = 0;
		counter[1] = 0;
	}
	return out(col_arr, arr, true);
}
void task4(int arr[m][n], void out(int[], int arr[m][n], boolean)) {
	int counter[2] = {0,0};
	int rows_arr[m];
	for (int i = 0; i < m; i++) {
		rows_arr[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0)
				counter[0]++;
			if (arr[i][j] == 1)
				counter[1]++;
			

		}
		if (((counter[0] % 2 == 0) & (counter[1] % 2 != 0)) || ((counter[0] % 2 != 0) & (counter[1] % 2 == 0)))
			rows_arr[i] = 1;
		counter[0] = 0;
		counter[1] = 0;
	}
	return out(rows_arr,arr, false);
}
void task5(int arr[m][n], void out(int[], int arr[m][n], boolean)) {
	int counter[2] = {0,0};
	int col_arr[n];
	for (int i = 0; i < n; i++) {
		col_arr[i] = 0;
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (arr[i][j] == 0)
				counter[0]++;
			if (arr[i][j] == 1)
				counter[1]++;
			

		}
		if (((counter[0] % 2 == 0) & (counter[1] % 2 != 0)) || ((counter[0] % 2 != 0) & (counter[1] % 2 == 0)))
			col_arr[j] = 1;
		counter[0] = 0;
		counter[1] = 0;
	}
	return out(col_arr,arr, true);
}
int main()
{
	string s = "";
   	setlocale( 0,"" );
    int arr[m][n];
	initialize(arr);
    menu(arr);

}
void menu(int arr[m][n]) {
	int choose = -1;
	while (choose != 0)
	{
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout<<arr[i][j]<<" ";
			}
			cout << "\n";
		}
		cout << "\nChoose the function: \n 0 - exit \n 1 - all zeros and ones \n 2 - rows of array A, in which the number of zeros is even and the number of ones is even \n 3 - columns of array A, in which the number of zeros is even and the number of ones even \n 4 - rows of array A, in which the number of zeros is even, and the number of ones is odd, or the number of ones is even, and the number of zeros is odd \n 5 - columns of array A, in which the number of zeros is even and the number of ones is odd or the number of ones is even , and the number of zeros is odd \n ";
		cin >> choose;
		switch (choose)
		{
		case 1:	count_all(arr,text); break;
		case 2: count_row(arr, text); break;
		case 3: count_col(arr, text); break;
		case 4: task4(arr, text); break;
		case 5: task5(arr, text); break;
		case 0: break;
		default:
		{
			cout << "ERROR:\" Incorrect input of function try again \"";
			Sleep(700);
			system("cls");
			choose = -1;
		}
		break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}
void initialize(int arr[m][n]) {
	cout << "Your array: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 2;
		}
	}
}
void text(string s) {
	cout << s;
}
void text(int r_c_arr[bigest], int arr[m][n], boolean r_c) {
	

	// r_c; False=r; True=C
	if (r_c) {

		for (int j = 0; j < n; j++) {
			if (n < m)
				for (int i = n - 1; i < m; i++)
					r_c_arr[i] = 0;
			if (r_c_arr[j] == 1) {
				cout << j + 1 << "column - ";
				for (int i = 0; i < m; i++) {
					cout << arr[i][j] << " ";
				}
				cout << "\n";
			}
			
		}
	}
	else {
		if (n > m)
			for (int i = m-1; i < n; i++) 
				r_c_arr[i] = 0;
		for (int i = 0; i < m; i++) {
			if (r_c_arr[i] == 1) {
				cout << i + 1 << "row - ";
				for (int j = 0; j < n; j++) {
					cout << arr[i][j] << " ";
				}
				cout << "\n";
			}
			
		}
	}
}
