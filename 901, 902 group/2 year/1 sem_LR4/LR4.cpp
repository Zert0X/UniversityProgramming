#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LR4.h"
class Class_Polygon {
public:
	//////////////////////////////////////////////////////////
	//arr_size - size of array								//
	//coords - dynamic size array for coordinates of apexes	//
	//////////////////////////////////////////////////////////
	int arr_size;
	float** coords = new float* [2]; // two rows at array
	//Constructors
	Class_Polygon(int size) : arr_size(size) {
		for (int count = 0; count < 2; count++)
			coords[count] = new float[arr_size];
	};

	//Destructor
	~Class_Polygon()
	{
		delete[] coords;
	}

protected:
	void coords_input(int i) {
		printf("Enter coordinates of %d apex: \n", i + 1);
		for (int j = 0; j < 2; j++) {
			printf(j % 2 ? "Y:" : "X:");
			scanf("%f", &coords[j][i]);
		}
		if (check_duplicates(i))
			coords_input(i);
	}
	bool check_duplicates(int i) {
		float x, y;
		x = coords[0][i];
		y = coords[1][i];
		for (int j = 0; j < i; j++) {
			if (coords[0][j] == x && coords[1][j] == y)
				return true;
		}
		return false;
	}

	
};
class Class_Triangle : Class_Polygon {
public:
	
	Class_Triangle():Class_Polygon(3) {};

	void apex_input() {
		for (int i = 0; i < arr_size; i++) {
			coords_input(i);
			printf("\n");
		}
	}

	void area_output(double area){
		printf("Area of triangle = %f\n", area);
	}

	double area() {
		return abs(((coords[0][0] - coords[0][2]) * (coords[1][1] - coords[1][2])) - ((coords[0][1] - coords[0][2]) * (coords[1][0] - coords[1][2]))) * 0.5;
	}
};

class Class_Rectangle : Class_Polygon {
public:

	Class_Rectangle() :Class_Polygon(4) {};

	void apex_input() {
		printf("Enter the apexes in a clockwise|counterclockwise direction\n");
		for (int i = 0; i < arr_size; i++) {
			coords_input(i);
			printf("\n");
		}
	}

	void area_output(double area) {
		printf("Area of rectangle = %f\n", area);
	}

	double area() {
		double first_side, second_side, third_side, fourth_side;
		first_side  = sqrt(pow((coords[0][1] - coords[0][0]), 2) + pow((coords[1][1] - coords[1][0]), 2));
		second_side = sqrt(pow((coords[0][2] - coords[0][1]), 2) + pow((coords[1][2] - coords[1][1]), 2));
		third_side  = sqrt(pow((coords[0][3] - coords[0][2]), 2) + pow((coords[1][3] - coords[1][2]), 2));
		fourth_side = sqrt(pow((coords[0][3] - coords[0][0]), 2) + pow((coords[1][3] - coords[1][0]), 2));
		if (first_side == third_side) {
			if (second_side == fourth_side) {
				return first_side * second_side;
			}
			else {
				printf("Runtime error 1 - check your coordinates and write it in clockwise direction;");
				exit(1);
			}
		}

	}
};

int main()
{
	printf("Triangle:\n");
	Class_Triangle triangle;
	triangle.apex_input();
	triangle.area_output(triangle.area());
	printf("Rectangle:\n");
	Class_Rectangle rectangle;
	rectangle.apex_input();
	rectangle.area_output(rectangle.area());
}
