//Vẽ hình chữ nhật rỗng
#include <iostream>
using namespace std;

void drawHollowRectangle(int width, int height){
	for(int i=0; i<height; i++){
    	for(int j=0; j<width; j++){
        	if(i==0 || i==height-1 || j==0 || j==width-1){
				cout<<"* ";
			}
        	else{
            	cout<<"  ";
			}
    	}
    	cout<<endl;
	}
}

int main()
{
	int width, height;
    cout<<"Nhập chiều rộng HCN: "; cin>>width;
	cout <<"Nhập chiều dài HCN: "; cin>>height;

    drawHollowRectangle(width, height);
	return 0;
}
