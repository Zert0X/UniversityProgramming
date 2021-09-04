#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int i,a;
	char buffer[33];
	system("chcp 1251");
	system("cls");
	cout << "Введите число: ";
	cin >> i;
	do{
		cout << "Введите основание системы счисления: ";
		cin >> a;
		system("cls");
	} while ((a < 2) || (a > 36));
	itoa(i, buffer, a);
	printf("\nЧисло %d в %d ричной системе счисления: %s", i, a, buffer);
	return 0;
}