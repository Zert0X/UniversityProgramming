#include <iostream>
#include <windows.h>
using namespace std;

//////////////////**FIRST FUNCTION//////////////////
void all_numbers(int N) {
	int even=0,odd=0;
	cout<<"All numbers between 0 and "<<N<<": \n";
	for(int i = 1 ; i<N;i++)
	{
		cout << i <<" ";
		if(i%2==0) even++; else odd++;
	}
	cout<<"\nQuantity of even: "<<even<<"\n";
	cout<<"Quantity of odd: "<<odd<<"\n";
	system("pause");
	system("cls");
}
//////////////////**SECOND FUNCTION/////////////////
void all_divisor(int N) {
	cout << "All divisor for exact division, for " << N << ": \n";
	for (int i = 1; i <= N; i++)
	{
		if (N%i == 0) cout << i << " ";
	}
	system("pause");
	system("cls");
}
//////////////////**THIRD FUNCTION//////////////////
void all_odd_even(int N) {
	int even = 0, odd = 0;
	cout << "All evens between 0 and " << N << ": \n";
	for (int i = 1; i < N; i++)
	{
		if (i % 2 == 0) { cout << i << " "; even+=i; }
	}
	cout << "\nAll odds between 0 and " << N << ": \n";
	for (int i = 1; i < N; i++)
	{
		if (i % 2 != 0) { cout << i << " "; odd+=i; }
	}
	cout << "\nSum of all even: " << even << " \n";
	cout << "Sum of all odd: " << odd <<"\n"; 
	cout << "The difference between "<<even<<" and "<<odd<<": " << abs(even-odd) << "\n";
	system("pause");
	system("cls");
}
void menu(int N) {
	int choose=-1;
	while (choose != 0)
	{
		cout << "Your N: " << N;
		cout << "\nChoose the function: \n 1 - найти и вывести все числа (0 < число < N), количество четных и нечетных чисел в данном диапазоне \n 2 - найти и вывести все делители числа N, на которые данное число делится без остатка\n 3 - найти и вывести отдельно все четные и нечетные числа (0 < число < N), суммы четных и нечетных чисел и разность между этими суммами.\n 0 - выход \n";
		cin >> choose;
		switch (choose)
		{
		case 1: all_numbers(N); break;
		case 2: all_divisor(N); break;
		case 3: all_odd_even(N); break;
		case 0: break;
		default:
		{
			cout << "ERROR:\" Incorrect input of function try again \"";
			Sleep(700);
			system("cls");
			choose = -1;
		}
			break;
		}
	}
	system("pause");
	system("cls");
} 

int main()
{
	setlocale( LC_ALL,"Russian" );
	int N;
	cout << "Enter N: ";
	cin >> N;
	menu(N);
}
