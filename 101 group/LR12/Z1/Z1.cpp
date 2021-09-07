#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <string>

using namespace std;
int main()
{
	string sequence="";
	int counter=0;
	printf("Enter the sequence: ");
	//get line for {space} input
	getline(cin, sequence);
	printf("Enter the character you are looking for: ");
	char n;
	cin >> n;
   
	for (int i = 0; i < sequence.length(); i++) {
		if (sequence[i] == n)
			counter++;
    }
	printf("The character you are looking for occurs %d times\n",counter);
}
