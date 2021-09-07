#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;
float min_val ( float* arr, int count, int & err);
int main()
{
	float count;
	cout << "Enter count\n";
	cin >> count;
	float* arr = new float[count];
	for (int i = 0; i < count; i++) {
		cout << "Enter arr[" << i << "]: ";
		cin >> arr[i];
	}
	int err = 0;
	float x = min_val(arr, count, err);
	if (err == 0)
	{
		cout << "y= " << (pow(sin(x), 2) + pow(cos(x), 3) - 5. + sqrt(x + 1.)) / (log(x + 5) / log(3));
	}
    else
        cout << "ERROR";
    return 0;
}
float min_val ( float* arr, int count, int & err){
    float min=-1;
    for (int i = 0; i<count;i++)
        if (arr[i]>=0.)
        min =arr[i];
    for (int i = 0; i<count;i++){
        if((min>arr[i])&&(arr[i]>=0.))
            min=arr[i];
    }
	if (min < 0.)err = 1; else err = 0;
	return min;
}
