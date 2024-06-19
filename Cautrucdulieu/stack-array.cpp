#include<iostream>
using namespace std;

const int MAX = 100;

class Stack {
    private:
        int top;
        int data[MAX];
    public:
        // Constructor
        Stack() : top(-1) {}
        
        void push(int x);
        void pop();
        int peek();
        bool isEmpty();
        int size();
};

void Stack::push(int x) {
    if(top < MAX -1) {
        data[++top] = x;
    }else {
        cout<<"Stack đầy!"<<endl;
    }
}
void Stack::pop() {
    if(top >= 0) {
        top--;
    }else {
        cout<<"Stack rỗng!"<<endl;
    }
}
int Stack::peek() {
    if(top >= 0) {
        return data[top];
    }else {
        cout<<"Stack rỗng!"<<endl;
        return -1;
    }
}
bool Stack::isEmpty() {
    return top == -1;
}
int Stack::size() {
    if(top >=0) {
        int temp = top;
        return ++temp;
    }else {
        cout<<"Stack rỗng!"<<endl;
        return -1;
    }
}

int main() {
    Stack myStack;
    myStack.push(10); // Thêm phần tử vào stack
    myStack.push(20);
    myStack.push(30);

    std::cout << "Đỉnh stack: " << myStack.peek() << std::endl;

    myStack.pop(); // Loại bỏ phần tử trên đỉnh

    std::cout << "Kích thước stack: " << myStack.size() << std::endl; 

    return 0;
}