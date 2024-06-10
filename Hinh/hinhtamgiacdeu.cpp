//Hinh tam giác đều rỗng
#include <iostream>
using namespace std;

void hinhTamGiacDeuRong(int height){
    for(int i =0; i<height; i++){
        for(int j=0; j<height-i-1; j++){
            cout<<" ";
        }

        for(int j=0; j<2*i +1; j++){
            if(j==0 || j==2*i || i==height-1){
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
    int height;
    cout<<"Nhập chiều cao tam giác đều: "; cin>>height;
    
    hinhTamGiacDeuRong(height);
    return 0;
}