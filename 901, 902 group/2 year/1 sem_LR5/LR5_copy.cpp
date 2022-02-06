#include <iostream>
#include <vector>
using namespace std;

struct apex{
    float x;
    float y;
};

class Class_Polygon{
    protected:
        static const int apex_quantity = 0;
        vector<apex> apexes_v;
    public:
    
        virtual void show_coords(){
            printf("Coords not initiated!\n");
        }
        
        const int get_apex_quantity(){
            return apex_quantity;
        };

        vector<apex> set_apexes_v(){
            vector<apex> apexes;
            for (int i = 0; i<apex_quantity; i++){
                apex temp;
                printf("Enter x[%d]:",i); scanf("%f",&temp.x);
                printf("Enter y[%d]:",i); scanf("%f",&temp.y);
                printf("---------------------\n");
                apexes.push_back(temp);
            } 
            return apexes;
        }
};

class Class_Triangle : public Class_Polygon{
    protected:
        static const int apex_quantity = 3;
    public:
        Class_Triangle(vector<apex> apexes){
            apexes_v = apexes;
        };

        virtual void show_coords(){
            printf("Coords of Triangle:\n");
            for (int i=0;i<apex_quantity;i++){
                printf("Apex [%2d]: x=%f | y=%f \n", i , apexes_v[i].x, apexes_v[i].y);
            }
        }

};

class Class_Rectangle : public Class_Polygon{
    protected:
        static const int apex_quantity = 4;
    public:
        Class_Rectangle(vector<apex> apexes){
            apexes_v = apexes;
        };

        virtual void show_coords(){
            printf("Coords of Rectangle:\n");
            for (int i=0;i<apex_quantity;i++){
                printf("Apex [%2d]: x=%f | y=%f \n", i , apexes_v[i].x, apexes_v[i].y);
            }
        }
    
};

int main(){
    Class_Polygon* Figures[3];
    Figures[0] = new Class_Polygon();
    printf("Enter coords for Triangle apexes:\n");
    Figures[1] = new Class_Triangle(Figures[1]->set_apexes_v());
    Figures[2] = new Class_Rectangle(Figures[2]->set_apexes_v());

    Figures[0]->show_coords();
    Figures[1]->show_coords();
    Figures[2]->show_coords();

    delete[] Figures;
    return 0;
}