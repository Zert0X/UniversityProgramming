#include <iostream>
using namespace std;
class Smartphone{
	string company="";
	string model="";
	double height=0;
	double width=0;
	string color="";
	public:
		void GetInfo(){
			cout<<"Введите информацию о смартфоне:"<<endl;
			cout<<"Производитель:"; cin>>company;
			cout<<"Модель:"; 		cin>>model;
			while (height<=0){
				cout<<"Высота(>0):"; 		cin>>height;
				height<=0? cout<<"Введите высоту больше 0!\n" : cout<<"";
			}
			while (width<=0){
				cout<<"Ширина(>0):"; 		cin>>width;
				width<=0?cout<<"Введите ширину больше 0!\n" : cout<<"";
			}
			cout<<"Цвет:"; 			cin>>color;
		};

		void ShowInfo(){
			cout<<"Информация о смартфоне:"<<endl;
			cout<<"Производитель:"; cout<<company<<endl;
			cout<<"Модель:"; 		cout<< model <<endl;
			cout<<"Высота:"; 		cout<< height<<endl;
			cout<<"Ширина:"; 		cout<< width <<endl;
			cout<<"Цвет:";   		cout<< color <<endl;
		};
};
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	Smartphone smartphone;
	smartphone.GetInfo();
	smartphone.ShowInfo();
	return 0;
}

