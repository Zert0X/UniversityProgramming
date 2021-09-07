#include "windows.h"
#include <iostream>
using namespace std;
int main()
{
	int choose = 10, k = 0;;
	
	double sum = 0, F = 1;
	while ((choose != 1) && (choose != 0)) {
		cout << "Please choose action:\n1-Start programm\n0-Exit\n";
		cin >> choose;
	}
	system("cls");
	while (choose != 0) {
		sum = 0;
		choose = 10;
		////////////////////////////////////
		cout << "Enter A,B as integer:\n";
		float a, b;
		cin >> a >> b;
		if (a > b) {
			float o;
			o = a;
			a = b;
			b = o;
		}//Switching positions
		if (a < (-10) || b>10) {
			cout << "Error [A,B] not in range [-10,10]";
			break;
		}
		////////////////////////////////////
		printf("%28s\n", "----------------------------");
		printf("%c%8s%c%8s%c%8s%c\n",':'," Value",':',"  Sum",':',"F",':');
		double i=a-0.1;
		if (i < 0) k = 0; else k = 10;
		while (i < b) {
			printf("%28s\n", "----------------------------");
			i = i + 0.1;
			if (i>-1 && k < 10) k += 1;
			if (i > -1 && i<0.0 && k == 10 )  i = 0.0; 
			/* из-за арифметики с++ факториал 0.0 при стартовом А<0 не считался коректно из-за чего пришлось 
			   делать обходное назначение i=0 в тот момент когда оно должно быть равно 0, а не i=-1.38e-18  */
			sum = sum + i;
			if ((i >= 0.0 )&& (k == 10)) {
				for (int j = 1; j <= round(i); j++)
				{
					F = F*j;
				}
				k = 0;
				printf("%c%8.1f%c%8.3f%c%8.0f%c\n", ':', i, ':', sum, ':', F, ':');
				F = 1;
			}else
			printf("%c%8.1f%c%8.3f%c%8s%c\n", ':', i, ':', sum, ':', "", ':');
			
		}
		////////////////////////////////////
		while (choose != 1 && choose != 0) {
			cout << "Programm completed.....\nPlease choose action:\n1-Restart programm\n0-Exit\n";
			cin >> choose;
		}
		system("cls");
	}
	return 0;
}
