#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <io.h>
using namespace std;
int main()
{
	FILE* f = new FILE;
	char *c = new char;
	f = fopen("z1.txt", "r");
	bool question=false;
	while (!feof(f)) {  // прочитали его и заполнили им строку
		fgets(c, 2, f);
		if (*c == '?') {
			question = true;
			break;
		}
	}
	fclose(f);
	if(question)
		cout << "In text we have question marks;";
	else
		cout << "In text we doesn't have any question marks;";
	
	return 0;
}
