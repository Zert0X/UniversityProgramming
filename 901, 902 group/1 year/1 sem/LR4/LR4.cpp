#include <iostream>
using namespace std;
int main()
{
	int a=0,b=0,res;
	char com;
	cout << "Enter a,b";
	cin >> a >> b;
	cout << "Enter operator(+,-,/,*)";
	cin >> com;
	switch (com)
	{
	case '+': {res = a + b; }break;
	case '-': {res = a - b; }break;
	case '*': {res = a * b; }break;
	case '/': {res = a / b; }break;
	default: { cout << "ERROR not found operator \'" << com << "\'"; return 0;
	}break;
}
	//-----------------------------------------------------------
		cout << "First number: " << a << "\nSecond number: " << b;
		cout << "\na"<<com<<"b=" << res;
	//-----------------------------------------------------------
		switch (res % 2)
		{
		case 0:
			cout << "\nResult is even"; break;
		case 1:
			cout << "\nResult is odd"; break;
		}
	//-----------------------------------------------------------
		switch (com)
		{
		case'/':
		case'-':
			switch (res >= 1 && res <= 10)
			{
			case 1:  cout << "\nThe result is in the range from 1 to 10";	  break;
			default: cout << "\nThe result is not in the range from 1 to 10"; break;
			}break;
	//-----------------------------------------------------------	
		case'*':
		case'+':
			switch (res >= 11 && res <= 20)
			{
			case 1:  cout << "\nThe result is in the range from 11 to 20";	   break;
			default: cout << "\nThe result is not in the range from 11 to 20"; break;
			}break;
		}
	//-----------------------------------------------------------
	return 0;
}