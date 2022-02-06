#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int quarters[2] = { 1,2 };
class polygon {
public:
	//////////////////////////////////////////////////////////
	//arr_size - size of array								//
	//coords - dynamic size array for coordinates of apexes	//
	//////////////////////////////////////////////////////////
	int arr_size = 3;
	float** coords = new float* [2]; // two rows at array
	//Constructors
	polygon() {
		array_size_input();
		for (int count = 0; count < 2; count++)
			coords[count] = new float[arr_size]; // arr_size columns
	};

	polygon(int size) : arr_size(size) {
		for (int count = 0; count < 2; count++)
			coords[count] = new float[arr_size];
	};

	//Destructor
	~polygon() 
	{
		delete[] coords;
	}

	

	//input apexes array 
	void apex_input() {
		for (int i = 0; i < arr_size; i++) {
			coords_input(i);
			printf("\n");
		}
	}
	//output apex coordinates
	void apex_output() {
		for (int i = 0; i < arr_size; i++) {
			printf("Coordinates of %d apex: ", i + 1);
			printf("X:%4.1f	Y:%4.1f\n", coords[0][i], coords[1][i]);
			}
			
		}
private:
	//input number of apexes
	void array_size_input() {
		printf("Enter number of apexes: ");
		scanf("%d", &arr_size);
		(arr_size < 3) ? array_size_input() : (void)NULL;
	}
	//
	void coords_input(int i) {
		printf("Enter coordinates of %d apex: \n", i + 1);
		for (int j = 0; j < 2; j++) {
			printf(j % 2 ? "Y:" : "X:");
			scanf("%f", &coords[j][i]);
		}
		if (!in_quarter(i) || check_duplicates(i))
			coords_input(i);
	}
	//check apex coordinates for conditions
	bool in_quarter(int pos) {
		bool check[2] = { false,false };
		for (int quarter_counter = 0; quarter_counter < 2; quarter_counter++) {
			switch (quarters[quarter_counter])
			{
			case 1: check[quarter_counter] = (coords[0][pos] > 0 && coords[1][pos] > 0) ? true : false; break;
			case 2: check[quarter_counter] = (coords[0][pos] < 0 && coords[1][pos] > 0) ? true : false; break;
			case 3: check[quarter_counter] = (coords[0][pos] < 0 && coords[1][pos] < 0) ? true : false; break;
			case 4: check[quarter_counter] = (coords[0][pos] > 0 && coords[1][pos] < 0) ? true : false; break;
			default:
				printf("Runtime error: 0 - no quarter \"%d\"", quarters[quarter_counter]);
				exit(0);
				break;
			}
		}
		return (check[0] || check[1]);
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
int main()
{
	printf("Default constructor:\n");
	polygon polygon1;
	polygon1.apex_input();
	polygon1.apex_output();

	printf("\nConstructor with size:\n");
	printf("Enter number of apexes:");
	int size=0;
	while (size < 3) {
		scanf("%d", &size);
	}
	polygon polygon2(size);
	polygon2.apex_input();
	polygon2.apex_output();
}