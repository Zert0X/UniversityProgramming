#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <io.h>
#include <vector>
#include <string>
using namespace std;
//////////////////////////////////////////////////
//Program wil be work fine if you will place	//
//punctuation marks for example:				//
// "Hi. how are you? i am fine! How are you? "	//
//////////////////////////////////////////////////
int main()
{
	FILE* f = new FILE;
	char* c = new char;
	f = fopen("z2.txt", "r");
	int counter=0;
	vector<fpos_t> pos;
	string s;
	//for 1-st sentence
	pos.push_back(0);
	//finding punctuations mark
	while (!feof(f)) { 
		fgets(c, 2, f);
		counter ++;
		if (*c == '.' || *c == '?' || *c == '!') {
			pos.push_back(counter);
		}
	}
	//small letter start
	cout << "---Small letter start sentences---\n";
	for (int i = 0; i < pos.size(); i++) {
		fsetpos(f, &pos[i]);
		for (int j = 0; j < 2; j++) {
			fgets(c, 2, f);
			if (*c >= 'a' && *c <= 'z') {
				fsetpos(f, &pos[i]);
				fgets(c, pos[i + 1] - pos[i] + 2, f);
				cout << c << endl;
				break;
			}
		}
	}
	//BIG LETTER START
	cout << "---Big letter start sentences---\n";
	for (int i = 0; i < pos.size(); i++) {
		fsetpos(f, &pos[i]);
		for (int j = 0; j < 2; j++) {
			fgets(c, 2, f);
			if (*c >= 'A' && *c <= 'Z') {
				fsetpos(f, &pos[i]);
				fgets(c, pos[i + 1] - pos[i] + 2, f);
				cout << c << endl;
				break;
			}
		}
	}
	
	fclose(f);
}
