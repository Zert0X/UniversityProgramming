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
		cout << "1.����� ������\n2.������������� ������ N �������� � ������ ������\n3.����������� ������ N �������� � ������ ������\n0.�����\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "������� ������:";
			cin >> s1;
			cout << "����� �������� ������: " << str_len(s1) << " �������� \n";
			break;
		case 2:
			cout << "������� ����������� ������:";
			cin >> s1;
			cout << "������� ���-�� ��������:";
			cin >> num;
			cout << "������� �������� ������ ������:";
			cin >> s2;
			str_n_cat(s2, s1, num);
			cout << "���������:" << s2 <<"\n";
			break;
		case 3:
			cout << "������� ����������� ������:";
			cin >> s1;
			cout << "������� ���-�� ��������:";
			cin >> num;
			str_n_copy(s2, s1, num);
			cout << "���������:" << s2 << "\n";
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
