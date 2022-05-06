#include <stdio.h>
#include <iostream>
const char* strcat(const char* a, const char* b){
    size_t al = 0, bl = 0;
    char *r, *c;
    while(a[al++]);
        while(b[bl++]);
        r = c = new char[al+bl-1];
    while(*c++ = *a++);
        --c;
    while(*c++ = *b++);
        return r;
}
class Class_Msg{
    public:
        void set_msg(const char* msg){
            _msg = msg;
        }
        void show_msg(){
            printf("%s\n",_msg);
        }

        Class_Msg operator + (Class_Msg in_msg){
            Class_Msg res;
            const char *res_msg=strcat(this->_msg,in_msg._msg);;
            res.set_msg(res_msg);
            return res;
        }
        Class_Msg operator + (const char* in_msg){
            Class_Msg res;
            const char *res_msg=strcat(this->_msg,_msg);;
            res.set_msg(res_msg);
            return res;
        }

        bool operator == (const char* in_msg){
            return (this->_msg == in_msg);
        }
        bool operator == (Class_Msg in_msg){
            return (this->_msg == in_msg._msg);
        }
    private:
        const char* _msg;
};

int main(){
    Class_Msg a,b,c;
    a.set_msg("Final");
    b.set_msg(" Fantasy");
    a.show_msg();
    b.show_msg();
    c = a+b;
    c.show_msg();
    if(a==b)
        printf("Yep\n");
    else
        printf("No\n");
    if(a=="Final")
        printf("Yep\n");
    else
        printf("No\n");
    return 0;
}