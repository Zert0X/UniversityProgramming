#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Class_Shape{
    protected:
        virtual float area_calculation() = 0;
    public:
        virtual void InputShapeData() = 0;
        virtual void ShowShapeArea() = 0;
};

class Class_Circle : public Class_Shape{
    protected:
        float radius;
        float area_calculation() override{
            return M_PI*radius*radius;
        }
    public:
        void InputShapeData() override{ //setter for radius
            printf("Enter radius:");
            scanf("%f",&radius);
        }
        void ShowShapeArea() override{
            printf("Circle area equals: %f", area_calculation());
        }

};
class Class_Polygon : public Class_Shape{
    protected:
        static const int sides_quantity = 0;

        vector<float> sides_v;

        virtual float area_calculation() = 0;

    public:

        virtual void ShowShapeArea() = 0;

        virtual void InputShapeData() =0;
};
class Class_Triangle:public Class_Polygon{
    protected:
        static const int sides_quantity = 3;

        float area_calculation(){
            float half_perim = (sides_v[0]+sides_v[1]+sides_v[2])/2.;
            return sqrt(half_perim*(half_perim-sides_v[0])*(half_perim-sides_v[1])*(half_perim-sides_v[2]));
        }

    public:
        void ShowShapeArea() override{
            printf("Triangle area equals: %f", area_calculation());
        }
        void InputShapeData() override{
            vector<float> sides;
            for (int i = 0; i<sides_quantity; i++){
                float temp;
                printf("Enter side[%d]:",i); scanf("%f",&temp);
                printf("---------------------\n");
                sides.push_back(temp);
            } 
            sides_v = sides;
        }
};

int main(){
    Class_Shape *shape;
    int choose = 0;
    while(choose==0){
        printf("Choose shape:\n1-Triangle\n2-Circle\n");
        scanf("%d",&choose);
        switch(choose){
            case 1:
                shape = new Class_Triangle();break;
            case 2:
                shape = new Class_Circle();break;
            default:
                choose = 0;
        }
    }
    shape -> InputShapeData();
    shape -> ShowShapeArea();
    delete shape;
}