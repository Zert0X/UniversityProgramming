#include <iostream>
#include <windows.h>
using namespace std;
struct Bridge {
	string name;
	float height;
	float length;
	float width;
	string type;
	string assignment;
	string material;
	//////////////////////////////////////////////////////////////////////////////////////////
	//name			- имя моста																//
	//height		- высота моста относительно уровня моря									//
	//length		- длина моста															//
	//width			- ширина моста															//
	//type			- тип моста (Мост,Путепровод,Виадук,Эстакада,Разводной)					//
	//assignment	- назначение моста(пешеходный,автодорожный,городской,железнодорожный)	//
	//material		- материал моста(Деревянный, Каменный, Железобетонный, Стальной)		//
	//////////////////////////////////////////////////////////////////////////////////////////
};
Bridge Bridge_Reset(){
	Bridge bridge;
	bridge.name = "None";
	bridge.height = NULL;
	bridge.length = NULL;
	bridge.width = NULL;
	bridge.type = "None";
	bridge.assignment = "None";
	bridge.material = "None";
	cout << "Reseting Done";
	Sleep(500);
	system("cls");
	return bridge;
}
Bridge Bridge_Input() {
	Bridge bridge;
	int choose = -1;
	system("cls");
	cout << "Enter Name of bridge: ";
	cin >> bridge.name;
	while (bridge.height <4.99) {
		cout << "Enter float/integer Height about sea(minimal 5): ";
		cin >> bridge.height;
	}
	while (bridge.length <=0.0) {
		cout << "Enter float/integer Length of bridge: ";
		cin >> bridge.length;
	}
	while (bridge.width <=0.0) {
		cout << "Enter float/integer Width of bridge: ";
		cin >> bridge.width;
	}
	/////////////Type/////////////
	choose = -1;
	while (choose == -1) {
		cout << "Enter type of bridge: \n 1 - Bridge \n 2 - Overpasse \n 3 - Viaduct \n 4 - Trestle Bridge \n 5 - Drawbridge\n";
		cin >> choose;
		switch (choose)
		{
		case 1: bridge.type = "Bridge"; break;
		case 2: bridge.type = "Overpasse"; break;
		case 3: bridge.type = "Viaduct"; break;
		case 4: bridge.type = "Trestle Bridge"; break;
		case 5: bridge.type = "Drawbridge"; break;
		default: {
			cout << "ERROR \"Incorect input of type\" try again.\n";
			choose = -1;
		}
			   break;
		}
	}
	/////////////assigment/////////////
	choose = -1;
	while (choose == -1) {
		cout << "Enter Assigment of bridge: \n 1 - Footbridge \n 2 - Highway \n 3 - Town(city) \n 4 - Railroad Bridge \n";
		cin >> choose;
		switch (choose)
		{
		case 1: bridge.assignment = "Footbridge Bridge"; break;
		case 2: bridge.assignment = "Highway Bridge"; break;
		case 3: bridge.assignment = "Town(city) Bridge"; break;
		case 4: bridge.assignment = "Railroad Bridge"; break;
		default: {
			cout << "ERROR \"Incorect input of assigment\" try again.\n";
			choose = -1;
		}
			   break;
		}
	}
	/////////////material/////////////
	choose = -1;
	while (choose == -1) {
		cout << "Enter Material of bridge: \n 1 - Timber \n 2 - Mason(Stone) \n 3 - ReinforcedConcrete \n 4 - Steel\n";
		cin >> choose;
		switch (choose)
		{
		case 1: bridge.material = "Timber"; break;
		case 2: bridge.material = "Mason(Stone)"; break;
		case 3: bridge.material = "ReinforcedConcrete"; break;
		case 4: bridge.material = "Steel"; break;
		default: {
			cout << "ERROR \"Incorect input of material\" try again.\n";
			choose = -1;
		}
			   break;
		}
	}
	system("pause");
	system("cls");
	return bridge;
}
void Bridge_Output(Bridge bridge) {
	cout << "Name: "		<< bridge.name		 << "\n";
	cout << "Height: "		<< bridge.height	 << "\n";
	cout << "Length: "		<< bridge.length	 << "\n";
	cout << "Width: "		<< bridge.width		 << "\n";
	cout << "Type: "		<< bridge.type		 << "\n";
	cout << "Assignment: "	<< bridge.assignment << "\n";
	cout << "Material: "	<< bridge.material	 << "\n";
	system("pause");
	system("cls");
}
void menu(Bridge bridge) {
	Bridge bridge_m = bridge;
	int choose = -1;
	while (choose != 0) {
		cout << "Please select action: \n 1 - Input information \n 2 - Reset all information \n 3 - Output information \n 0 - Exit \n";
		cin >> choose;
		switch (choose)
		{
		case 0: break;
		case 1: bridge_m = Bridge_Input(); break;
		case 2: bridge_m = Bridge_Reset(); break;
		case 3: Bridge_Output(bridge_m); break;
		default: {cout << "ERROR \"Incorect input of action\" try again."; Sleep(500); system("cls"); }break;
		}
		
	}
}
int main()
	{
	Bridge bridge1 = Bridge_Reset();
	menu(bridge1);
	return 0;
}
