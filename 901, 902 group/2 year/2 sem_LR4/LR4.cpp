#include <stdio.h>
#include <iostream>
#include <typeinfo>

class Class_Array{
    public:
    template <typename T>
    T ShowArrayElements(T arr[], int count)
    {   
        std::cout<<"Array elements  of "<< typeid(T).name()<< "\n";
        for(int i = 0;i<count;i++)
            std::cout<< "Array element "<<i<<": "<<arr[i]<<'\n';
    }

    template <typename T>
    T Min_Max(T arr[], int count)
    {
        T min = arr[0];
        int min_pos = 0;
        T max = arr[0];
        int max_pos = 0;
        for(int i=0;i<count;i++){
            if(arr[i]<min){
                min=arr[i];
                min_pos=i;
                }
            if(arr[i]>max){
                max=arr[i];
                max_pos=i;
                }
            }
        std::cout<<"Min element of array #"<<min_pos<<" = "<<min<< "\n";
        std::cout<<"Max element of array #"<<max_pos<<" = "<<max<< "\n";
    }
};

int main(){
    Class_Array b;
    float arr_float[4] = {0.5,1.0,1.5,2.0};
    int arr_int[5] = {1,2,3,4,5};
    b.ShowArrayElements(arr_int, 5);
    b.Min_Max(arr_int, 5);
    printf("\n");
    b.ShowArrayElements(arr_float, 4);
    b.Min_Max(arr_float, 4);
    return 0;
}