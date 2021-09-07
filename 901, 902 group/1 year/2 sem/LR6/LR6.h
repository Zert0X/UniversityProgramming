#include <iostream>
using namespace std;
int str_len(char* s) {
	int length=0;
	int i = 0;
	// '\0' символ конца строки
	while (s[i]!='\0') {
		length++;
		i++;
	}
	return length;
}
char* str_n_cat(char* dest, char* source, unsigned int num) {
	try {
		if (num > str_len(source))
			num = str_len(source);
		for (int i = 0; i < num; i++) {
			char* tmp = new char[str_len(dest) + 1];
			tmp = dest;
			tmp[str_len(tmp)] += source[i];
			while (tmp[str_len(tmp) - 1] != source[i])
				tmp[str_len(tmp) - 1] = NULL;
			dest = NULL;
			dest = new char[str_len(tmp)];
			dest = tmp;
		}
	}
	catch(...) {

		return NULL;

	}
	return dest;
}
char* str_n_copy(char* dest, char* source, unsigned int num) {
	try {
		if (num > str_len(source))
			num = str_len(source);

		for (int i = 0; i < num; i++) {
			dest[i] = source[i];
			while (dest[str_len(dest) - 1] != source[i])
				dest[str_len(dest) - 1] = NULL;
		}
	}

	catch (...) {

		return NULL;

	}
	return dest;
}