#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <cstdio>
#include <iostream>
#include <windows.h>
using namespace std;
class Class_Triangle {
private:
	float a, b, c, area, half_perim;
public:
	Class_Triangle() {
		a = 0.0;
		b = 0.0;
		c = 0.0;
		area = 0.0;
		half_perim = 0.0;
	}
	void find_area() {
		half_perim = (a + b + c) / 2;
		area = sqrt(half_perim * (half_perim - a) * (half_perim - b) * (half_perim - c));
		printf("First side: %f \nSecond side: %f \nThird side: %f \nArea of Triangle: %f\n", a, b, c, area);
	}

	void set_info() {
		do {
			printf("Enter A:");
			scanf("%f", &a);
		} while (a <= 0);
		do {
			printf("Enter B:");
			scanf("%f", &b);
		} while (b <= 0);
		do {
			printf("Enter C:");
			scanf("%f", &c);
		} while ((c <= 0) || ((b + a) <= c));
	}
};

class Class_Circle {
private:
	float R, area;
	const double PI = 3.14;
public:
	Class_Circle() {
		R = 0.0;
		area = 0.0;
	}
	void find_area() {
		area = PI * R * R;
		cout << "Area of circle:" << area;
	}

	void set_info() {
		do {
			printf("Enter Radius:");
			scanf("%f", &R);
		} while (R <= 0);
		
	}
};
class Class_Figure {
private:
	Class_Circle Circle;
	Class_Triangle Triangle;
public:
	void SetFigure() {
		while (1) {
			int choice = 0;
			cout << "Выберите фигуру(1 - треугольник, 2-круг):"; 
			cin >> choice;
			switch (choice)
			{
			case 1: {
				Triangle.set_info(); 
				Triangle.find_area(); 
				return; }

			case 2: {
				Circle.set_info();
				Circle.find_area();
				return; }
			default:
				printf("ERROR");
				Sleep(250);
				system("cls");
				break;
			}
		}
	}

};
int main() {
	setlocale(LC_ALL, "Russian");
	Class_Figure Figure;
	Figure.SetFigure();
}