#include<iostream>
#include<string>
using namespace std;

typedef struct {
    int top;    // Vị trí đỉnh bắt đầu từ index 0;
    int *nodes; //Danh sách các phần tử
} Stack;

void initStack(Stack *stack);
void push(Stack *stack, int node);
int pop(Stack *stack);
void release(Stack *stack);


int main(){
    int node,n;
    Stack *stack = new Stack;
    initStack(stack);

    cout<<"Nhập mảng các số"<<endl;
    cout<<"Số phần tử cần nhập: "; cin>>n;
    
    for(int i=0; i<n; i++){
        cout<<"Phần tử "<<i+1<<": "; cin>>node;
        push(stack,node);
    }
    while(stack->top > -1){
        cout<<pop(stack)<<" ";
    }
    release(stack);
    return 0;
}

void initStack(Stack *stack){
    stack->top = -1; // Khởi tạo ngăn xếp rỗng
}

void push(Stack *stack, int node){
    int *tmpNodes = new int[stack->top + 2];  // Cấp phát vùng nhớ mới
    stack->top++;  // Tăng chỉ số của node đỉnh
    for(int i=0; i<stack->top; i++){   // Sao chép sang vùng nhớ mới
        tmpNodes[i] = stack->nodes[i];
    }
    tmpNodes[stack->top] = node;  // Thêm node mới vào đỉnh
    delete []stack->nodes;  // Giai phóng vùng nhớ cũ
    stack->nodes = tmpNodes;  // Trỏ vào vùng nhớ mới
    return;
}

int pop(Stack *stack){
    if(stack->top < 0){
        cout<<"Stack is empty"<<endl;     // Kiểm tra ngăn xếp rỗng 
        return 0;
    }
    int result = stack->nodes[stack->top];  // Lưu giữ giá trị đỉnh
    int *tmpNodes = new int[stack->top];    // Cấp phát vùng nhớ mới
    for(int i=0; i<stack->top; i++){        // Sao chép sang vùng nhớ mới
        tmpNodes[i] = stack->nodes[i];      
    } 
    stack->top--;               // Giam chỉ số của node đỉnh
    delete []stack->nodes;      // Giai phóng vùng nhớ cũ
    stack->nodes = tmpNodes;    // Trỏ vào vùng nhớ mới
    return result;              // Trả về giá trị node đỉnh
}

void release(Stack *stack){
    delete []stack->nodes;  // Giai phóng vùng nhớ 
    delete stack;
    return;
}