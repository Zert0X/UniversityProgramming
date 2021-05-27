// Z1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#define fields_count 5
#include <fstream>
#include <iostream>
#include <io.h>
#include <vector>
#include <string>
using namespace std;
int student_count = 6;


struct student {
	string name;
	string birthday_date;
	int first_mark;
	int second_mark;
	int third_mark;
};


void File_Handler(const char*, vector<student>&, bool);
void File_read(const char*, vector<student>&);
void File_write(const char*, vector<student>&);
void sort(vector<student>&);


int main()
{
	system("chcp 1251");
	system("cls");
	vector<student> student_data;
	bool mode;
	cout << "Choose:\n 0 - You want to write in file?\n 1 - You want to read from file?\n";
	cin >> mode;
	//file handler .-.
	File_Handler("Students_data.txt", student_data,mode);

	//sorting student data acording to objective
	sort(student_data);

	//output
	int counter = 0;
	for (int i = 0; i < student_data.size(); i++) {
		double first_mark = student_data[i].first_mark;
		double second_mark = student_data[i].second_mark;
		double third_mark = student_data[i].third_mark;
		if ((first_mark + second_mark + third_mark) / 3. >= 4.)
			counter++;
	}
	for (int i = 0; i < student_data.size(); i++) {
		if (counter != 0) {
			string name = student_data[i].name;
			string birthday_date = student_data[i].birthday_date;
			double first_mark = student_data[i].first_mark;
			double second_mark = student_data[i].second_mark;
			double third_mark = student_data[i].third_mark;
			cout << "Student " << ":"
				<< "\nName:" << name
				<< "\nBirthday date:" << birthday_date
				<< "\nFirst mark: " << first_mark
				<< "\nSecond mark: " << second_mark
				<< "\nThird mark: " << third_mark
				<< "\n" << "---------------\n";
		}
		else{
			cout << "There is no student with average mark 4.0";
		}
	}

}

void sort(vector<student>& student_data) {
	student tmp;
	int date1, date2;
	for (int i = 0; i < student_count; i++) {
		for (int j = 0; j < student_count-1; j++) {
			date1 = stoi(student_data[j].birthday_date.substr(6, 4));
			date2 = stoi(student_data[j + 1].birthday_date.substr(6, 4));
			if (date1 < date2) {
				tmp = student_data[j];
				student_data[j] = student_data[j + 1];
				student_data[j + 1] = tmp;
			}
		}
	}

}

void File_Handler(const char* file, vector<student>& student_data, bool mode) {
	if (mode)
		File_read(file, student_data);
	else
		File_write(file, student_data);
}

//Reading file
void File_read(const char* file, vector<student>& student_data) {
	//file opening and some initializing shit
	string fields_list[fields_count] = { "Name:","Birthday:","First_Mark:","Second_Mark:","Third_Mark:" };
	FILE* student_data_file = new FILE;
	student_data_file = fopen(file, "r");
	///////////////////////////////////////
	char* student_data_string = new char;
	fpos_t pos = 0;
	for (int iterations = 0; iterations < student_count; iterations++) {
		student student_temp = { "","",0,0,0 };
		string temp_student_data_string = "";
		fgets(student_data_string, 2, student_data_file);
		temp_student_data_string += student_data_string;
		temp_student_data_string[0] == '\n' ? temp_student_data_string.erase() : temp_student_data_string;
		while (*student_data_string != '}') {
			fgets(student_data_string, 2, student_data_file);
			temp_student_data_string += student_data_string;
			fgetpos(student_data_file, &pos);
		}
		int pos1 = 0, pos2 = 0;
		//Reading and Filling all parametrs
		for (int i = 0; i < fields_count; i++) {
			pos1 = temp_student_data_string.find(fields_list[i]) != (-1) ? temp_student_data_string.find(fields_list[i]) : 0;
			pos2 = temp_student_data_string.find(";", pos1) != (-1) ? temp_student_data_string.find(";", pos1) : 0;
			string data = temp_student_data_string.substr(pos1, pos2 - pos1);
			int field_name_size = fields_list[i].size();
			data = data.substr(fields_list[i].size(), pos2 - field_name_size);

			switch (i)
			{
			case 0:	student_temp.name = data; break;
			case 1: student_temp.birthday_date = data; break;
			case 2: student_temp.first_mark = stoi(data); break;
			case 3: student_temp.second_mark = stoi(data); break;
			case 4: student_temp.third_mark = stoi(data); break;
			}
		}
		student_data.push_back(student_temp);
	}
}

//Reading Write in file
void File_write(const char* file, vector<student>& student_data) {
	//file opening and some initializing shit
	FILE* student_data_file = new FILE;
	student_data_file = fopen(file, "w+");
	string fields_list[fields_count] = { "Name:","Birthday(00.00.0000):","First_Mark(1-5):","Second_Mark(1-5):","Third_Mark(1-5):" };
	bool empty_b = false;
	if (student_data.size() == 0)
		empty_b = true;
	for (int iterations = 0; iterations < student_count; iterations++) {
		student student_temp = { "","",0,0,0 };
		string data = "";
		string temp_student_data_string = "Student" + to_string(iterations + 1) + "{";
		cout << "Student" << iterations + 1 << "{\n";
		for (int i = 0; i < fields_count; i++) {
			data = "";
			cout << "Enter " << fields_list[i];
			cin >> data;
			temp_student_data_string += fields_list[i] + data + ";";
			switch (i)
			{
			case 0:	student_temp.name = data; break;
			case 1: student_temp.birthday_date = data; break;
			case 2: student_temp.first_mark = stoi(data); break;
			case 3: student_temp.second_mark = stoi(data); break;
			case 4: student_temp.third_mark = stoi(data); break;
			}

		}
		cout << "}";
		if (empty_b)
			student_data.push_back(student_temp);
		temp_student_data_string += "}\n";
		fputs(temp_student_data_string.c_str(), student_data_file);
		system("cls");
	}

}