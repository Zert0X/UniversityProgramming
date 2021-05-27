// Z2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#define MAX_COUNT 8
using namespace std;
struct PRICE {
	string product_name;
	string shop_name;
	double price;
};
int main()
{
	system("ch1251");
	system("cls");
	vector <PRICE> products_list;
	for (int i = 0; i < MAX_COUNT; i++) {
		PRICE temp_product = {"","",0};
		cout << "Product" << i + 1 << ":\n";
		cout <<"Product name: ";					cin >> temp_product.product_name;
		cout <<"Shop name(case sensitive): ";		cin >> temp_product.shop_name;
		cout <<"Price: ";							cin >> temp_product.price;
		cout << "-----------------\n";
		products_list.push_back(temp_product);
	}
	for (int i = 0; i < MAX_COUNT; i++) {
		for (int j = 0; j < MAX_COUNT - 1; j++) {
			if (products_list[j].shop_name > products_list[j + 1].shop_name) {
				PRICE tmp;
				tmp = products_list[j];
				products_list[j] = products_list[j + 1];
				products_list[j + 1] = tmp;
			}
		}
	}
	system("cls");
	string shop_name_search;
	cout << "Shop name for product list(search is case sensitive):"; cin >> shop_name_search;
	for (int i = 0; i < MAX_COUNT; i++) {
		if (products_list[i].shop_name == shop_name_search){
			cout << "Product" << i + 1	<< ":"; 
			cout << "\nProduct name: "	<< products_list[i].product_name;
			cout << "\nShop name: "		<< products_list[i].shop_name;
			cout << "\nPrice: "			<< products_list[i].price<<" RUB";
			cout << "\n-----------------";
		}
	}
}
