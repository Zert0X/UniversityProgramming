#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
class Class_MLib{
	public:
		static Class_MLib *getInstance(){
			if(instance)
				instance = new Class_MLib();
			return instance;
		}
		
		double get_cos(double x){
			return cos((x*M_PI)/180);
		}
		double get_sin(double x){
			return sin((x*M_PI)/180);
		}

	private:
		Class_MLib(){
		}
		
		~Class_MLib(){
		}
		
		static Class_MLib *instance;
};

Class_MLib* Class_MLib::instance;

int main(){
	
	Class_MLib *instance = Class_MLib::getInstance();
	double x;
	cout<<"Enter x in grad:";
	cin>>x;
	double cos = (int)(instance -> get_cos(x)*10000)/10000.;
	double sin = (int)(instance -> get_sin(x)*10000)/10000.;
	double *foo = 0;
	if(modf(cos,foo) == 0)
		printf("cos: %.0f \n",cos);
	else
		printf("cos: %f \n",cos);	
		
	if(modf(sin,foo) == 0)
		printf("sin: %.0f \n",sin);
	else
		printf("sin: %f \n",sin);	
	
	return 0;
};
