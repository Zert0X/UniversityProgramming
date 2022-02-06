#include <iostream>
#include <vector>
using namespace std;

struct apex{
    float x;
    float y;
};

class Class_Polygon{
    protected:
        vector<apex> apexes_v;
    public:
    
    virtual void show_coords(){
        printf("Coords not initiated!\n");
    }
};

class Class_Triangle : public Class_Polygon{
    public:
    Class_Triangle(vector<apex> apexes){
        apexes_v = apexes;
    };
    virtual void show_coords(){
        printf("Coords of Triangle:\n");
        for (int i=0;i<apexes_v.size();i++){
            printf("Apex [%d]: x%d=%f | y=%f \n", i , apexes_v[i].x, apexes_v[i].y);
        }
    }
};

class Class_Rectangle : public Class_Polygon{
    public:
    Class_Rectangle(vector<apex> apexes){
        apexes_v = apexes;
    };
    virtual void show_coords(){
        printf("Coords of Rectangle:\n");
        for (int i=0;i<apexes_v.size();i++){
            printf("Apex [%d]: x%d=%f | y=%f \n", i , apexes_v[i].x, apexes_v[i].y);
        }
    }
};

int main(){
    Class_Polygon* Figures[3];
    vector<apex> apexes;
    Figures[0] = new Class_Polygon();

    printf("Enter coords for Triangle apexes:\n");
    for (int i = 0; i<3; i++){
        apex temp;
        printf("Enter x[%d]:",i); scanf("%f",&temp.x);
        printf("Enter y[%d]:",i); scanf("%f",&temp.y);
        printf("---------------------\n");
        apexes.push_back(temp);
    }
    Figures[1] = new Class_Triangle(apexes);
    apexes.clear();

    printf("Enter coords for Rectangle apexes:\n");
    for (int i = 0; i<4; i++){
        apex temp;
        printf("Enter x[%d]:",i); scanf("%f",&temp.x);
        printf("Enter y[%d]:",i); scanf("%f",&temp.y);
        printf("---------------------\n");
        apexes.push_back(temp);
    }
    Figures[2] = new Class_Rectangle(apexes);
    apexes.clear();

    Figures[0]->show_coords();
    Figures[1]->show_coords();
    Figures[2]->show_coords();
    return 0;
}