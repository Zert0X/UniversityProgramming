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
			cout<<"������� ���������� � ���������:"<<endl;
			cout<<"�������������:"; cin>>company;
			cout<<"������:"; 		cin>>model;
			while (height<=0){
				cout<<"������(>0):"; 		cin>>height;
				height<=0? cout<<"������� ������ ������ 0!\n" : cout<<"";
			}
			while (width<=0){
				cout<<"������(>0):"; 		cin>>width;
				width<=0?cout<<"������� ������ ������ 0!\n" : cout<<"";
			}
			cout<<"����:"; 			cin>>color;
		};

		void ShowInfo(){
			cout<<"���������� � ���������:"<<endl;
			cout<<"�������������:"; cout<<company<<endl;
			cout<<"������:"; 		cout<< model <<endl;
			cout<<"������:"; 		cout<< height<<endl;
			cout<<"������:"; 		cout<< width <<endl;
			cout<<"����:";   		cout<< color <<endl;
		};
};
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	Smartphone smartphone;
	smartphone.GetInfo();
	smartphone.ShowInfo();
	return 0;
}

