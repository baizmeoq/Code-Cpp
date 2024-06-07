//Vẽ hình vuông rỗng
#include <iostream>
using namespace std;

void drawHollowSquare(int size){
	for(int i=0; i<size; i++){
    	for(int j=0; j<size; j++){
        	if(i==0 || i==size-1)
            	cout<<"* ";
        	else if(j==0 || j==size-1)
            	cout<<"* ";
        	else
            	cout<<"  ";
    	}
    	cout<<endl;
	}
}

int main()
{
	int size;
	cout <<"Nhập kích thước hình vuông: "; cin>>size;
    
	if(size>1){
    	drawHollowSquare(size);
	}else{
    	cout<<"Kích thước phải lớn hơn 1 để tạo hình vuông rỗng"<<endl;
	}
	return 0;
}
