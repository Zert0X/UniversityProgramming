#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <vector>
#include <algorithm>

class ErrorMsg{
public:
	ErrorMsg(const char* msg="Unknown Exception", int code=-1){
		_code=code;
		_msg=msg;
	}
	
	int GetMsgCode() {
		return _code;
	}

	char* ShowMsg() {
			printf("Caught error, code: %d, error: %s\n",GetMsgCode(),_msg);
	}
private:
	const char* _msg;
	int _code;

};
template <typename T>
class Class_Stack{
    public:
    Class_Stack(){
        initialize_stack();
    }
    Class_Stack(int size){
        max_size = size<=0?max_size:size;
        initialize_stack();
    }
    void push(T element){   
        try{
            if (stack.size() < max_size)
                stack.push_back(element);
            else
                throw ErrorMsg("Stack overflow", 1);
        }
        catch(ErrorMsg &e){
                e.ShowMsg();
                exit(e.GetMsgCode());
        }
	}
	
	T pop(){
        try{
            if (stack.size() > 0){
                T temp = stack.back();
                stack.pop_back();
                return temp;
                }
            else
                throw ErrorMsg("Stack empty", 2);
        }
        catch(ErrorMsg &e){
                e.ShowMsg();
                exit(e.GetMsgCode());
        }
	}
    void print_stack(){
        for (int i=0;i<stack.size();i++){
            std::cout<<i<<" element of stack "<<stack[i]<<'\n';
        }
    }
    private:

    std::vector<T> stack;
    int max_size = 10;

	void initialize_stack(){
        for (int i=0;i<max_size;i++){
            std::cout<<"Enter "<<typeid(T).name()<<" stack element:";
            T temp;
            std::cin>>temp;
            push(temp);
        }
        std::reverse(stack.begin(),stack.end());
    };

};

int main(){
    Class_Stack<int> stack_i(5);
    stack_i.print_stack();
    std::cout <<"Poped out element: "<<stack_i.pop()<<'\n';
    stack_i.print_stack();
    printf("\n");
    Class_Stack<float> stack_f(7);
    stack_f.print_stack();
    std::cout <<"Poped out element: "<< stack_f.pop()<<'\n';
    stack_f.print_stack();
    return 0;
}