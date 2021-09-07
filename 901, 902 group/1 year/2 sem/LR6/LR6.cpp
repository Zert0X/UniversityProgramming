#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LR6.h"
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL,"Russian");

	int choose = -1;
	while(1){
		char* s1 = new char();
		char* s2 = new char();
		int num=0;
		cout << "1.Длина строки\n2.Присоединение первых N символов к другой строке\n3.Копирование первых N символов в другую строку\n0.выход\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Введите строку:";
			cin >> s1;
			cout << "длина введённой строки: " << str_len(s1) << " символов \n";
			break;
		case 2:
			cout << "Введите изначальную строку:";
			cin >> s1;
			cout << "Введите кол-во символов:";
			cin >> num;
			cout << "Введите конечную строку строку:";
			cin >> s2;
			str_n_cat(s2, s1, num);
			cout << "результат:" << s2 <<"\n";
			break;
		case 3:
			cout << "Введите изначальную строку:";
			cin >> s1;
			cout << "Введите кол-во символов:";
			cin >> num;
			str_n_copy(s2, s1, num);
			cout << "результат:" << s2 << "\n";
			break;
		case 0:
			return 0;
		default:
			cout << "Try again";
		}
		s1 = NULL;
		s2 = NULL;
	}
	return 0;
}
