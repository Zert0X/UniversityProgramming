#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <string>
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	string s;
	printf("Enter word: ");
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'д' || s[i] == 'Д') {
			printf("Yes, there is \'Д\' character.");
			break;
		}
		else {
			if(i==(s.length()-1))
			printf("No, there is no \'Д\' character.");
		}
	}
}
