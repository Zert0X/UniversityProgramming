#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string> 
using namespace std;

class Class_MsgError{
public:
	Class_MsgError(const char* msg="Unknown Exception", int code=-1){
		_code=code;
		_msg=msg;
	}
	
	int GetMsgCode() {
		return _code;
	}

	char* ShowMsg() {
			printf("Caughted error, code: %d, error: %s\n",GetMsgCode(),_msg);
	}
private:
	const char* _msg;
	int _code;

};


class Class_MLib {
public:
	static Class_MLib* getInstance() {
		if (instance)
			instance = new Class_MLib();
		return instance;
	}

	double get_cos(double x) {
		return (int)(cos((x * M_PI) / 180) * 10000) / 10000.;
	}
	double get_sin(double x) {
		return (int)(sin((x * M_PI) / 180) * 10000) / 10000.;
	}
	double get_tg(double x) {
		double cos = get_cos(x);
		double sin = get_sin(x);
		if (cos == 0)
			throw Class_MsgError("division by 0", 1);
		return (int)(sin / cos * 10000) / 10000.;
	}
	double get_ctg(double x) {
		double cos = get_cos(x);
		double sin = get_sin(x);
		if (sin == 0)
			throw Class_MsgError("division by 0", 1);
		return (int)(cos / sin * 10000) / 10000.;
	}

	static void output(double num,const char* name) {
		if (modf(num, nullptr) == 0)
			printf("%s: %.0f \n",name, num);
		else
			printf("%s: %.4f \n",name, num);
	}
private:
	Class_MLib() {
	}

	~Class_MLib() {
	}

	static Class_MLib* instance;
};

Class_MLib* Class_MLib::instance;

int main() {
	Class_MLib* math = Class_MLib::getInstance();
	double x;
	cout << "Enter x in grad:";
	cin >> x;
	double cos = 0.0;
	double sin = 0.0;
	double tg  = 0.0;
	double ctg = 0.0;
	cos = math->get_cos(x);
	sin = math->get_sin(x);
	math->output(cos, "cos");
	math->output(sin, "sin");
	try{
		tg = math->get_tg(x);
		math->output(tg, "tg");
	}
	catch(Class_MsgError &error){
		error.ShowMsg();
	}

    try{
        ctg = math->get_ctg(x);
		math->output(ctg, "ctg");
	}
	catch(Class_MsgError &error){
		error.ShowMsg();
	}


	return 0;
};
