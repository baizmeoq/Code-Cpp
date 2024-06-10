//Hinh bình hành rỗng
#include <iostream>
using namespace std;

void hinhBinhHanh(int height, int length){
    for(int i =0; i<height; i++){
        for(int j=0; j<height-i-1; j++){
            cout<<" ";
        }

        for(int j=0; j<length; j++){
            if(j==0 || j==length-1 || i==0 || i==height-1){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }

        cout<<endl;
    }
}

int main()
{
    int height, lenght;
    cout<<"Nhập chiều cao hình bình hành: "; cin>>height;
    cout<<"Nhập chiều dài hình bình hành: "; cin>>lenght;
    
    hinhBinhHanh(height, lenght);
    return 0;
}