#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int A,B;
    double x,y;
    cout<<"Enter x: ";cin>>x;
    cout<<"Enter A: ";cin>>A;
    cout<<"Enter B: ";cin>>B;
    x=(int)x;
    if(((int)x > 0) && (((int)x % 2) == 0)){
        if(((x >= A) && (x <= B)) || ((x >= B) && (x <= A))){
                y=(2/9.)-(4/5.)+(x+cos(sin(x)))*pow(log(x+7),3)/7.+(pow((log(x/8.)/log(4)),5))+(14./(45+sin(pow(x,8))));
                cout<<"---------\n"<<"x= "<<x<<"\n"<<"y(x)= "<<y<<endl;
            }
        else{
            cout<<"x not in ["<<A<<","<<B<<"]"<<endl;
            }
        }
    else{
            cout<<"X not even or natural number"<<endl;
        }
    return 0;
}
