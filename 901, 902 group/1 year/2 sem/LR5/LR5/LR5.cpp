#include <iostream>
using namespace std;
void print_tab(float A, float B, float step);
void error_handler();
int main()
{
	for (int i = 0; i < 3; i++){
	error_handler();
	}
}
void print_tab(float A, float B, float step) {
	A >= B ? A = B : A = A;
	printf(":%10.3f", A);
	printf(":%10.3f", sin(A));
	printf(":%10.3f", cos(A));
	printf(":%10.3f", pow(A, 2));
	printf(":%10.3f:", pow(A, 3));
	printf("\n");
	A < B ? print_tab(A + step, B, step) : (void)NULL;
}
void error_handler() {
	float A, B, step;
	cout << "A="; cin >> A;
	cout << "B="; cin >> B;
	cout << "step="; cin >> step;
	printf("%56s", "--------------------------------------------------------\n");
	printf("%56s", ":    x     : y=sin(x) : y=cos(x) :  x=y^2   :  x=y^3   :\n");
	printf("%56s", "--------------------------------------------------------\n");
	try {
		A > B ? throw("A>B") : NULL;
		step <= 0 ? throw("step<=0") :NULL;
		print_tab(A, B, step);
	}
	catch (const char* exception) {
		std::cerr << "Error: " << exception << '\n';
	}
}