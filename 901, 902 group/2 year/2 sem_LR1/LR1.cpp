#include <stdio.h>
#include <iostream>
#include <string>
#define ARR_SIZE 10
using namespace std;

class Class_Static {
public:
	Class_Static() {
		Class_Static::first++;
	};
	Class_Static(int i) {
		Class_Static::second++;
	};
	Class_Static(int i, int ii) {
		Class_Static::third++;
	};
	void static ShowClassInfo() {
		string s;
		for (int i = 0; i < 3; i++) {
			switch (i) {
			case 0:s = "по умолчанию = " + to_string(Class_Static::first);      break;
			case 1:s = "с одним параметром = " + to_string(Class_Static::second);  break;
			case 2:s = "с двумя параметрами = " + to_string(Class_Static::third);   break;
			}
			cout<<"Количество экземпляров класса Class_Static, использующих конструктор"<<s<<"\n";
		}
	};
	private:
		static int first, second, third;


};

int Class_Static::first;
int Class_Static::second;
int Class_Static::third;

int main() {
	setlocale(0, "");
	Class_Static* Class_Static_arr[ARR_SIZE];
	for (int i = 0; i < 3; i++)
		Class_Static_arr[i] = new Class_Static();
	for (int i = 0; i < 5; i++)
		Class_Static_arr[3 + i] = new Class_Static(i);
	for (int i = 0; i < 2; i++)
		Class_Static_arr[8 + i] = new Class_Static(i, i);
	Class_Static::ShowClassInfo();
	return 0;
}