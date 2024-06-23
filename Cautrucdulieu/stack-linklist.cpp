#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
}; 

class Stack {
    private: 
        Node *top;
    public:
        // Constructor
        Stack() : top(nullptr) {}
        // Destructor
        // Giai phóng bộ nhớ của tất cả các node khi stack bị hủy
        ~Stack() {
            while(!isEmpty()) {
                pop();
            }
        }

        void push(int x);
        void pop();
        int peek() const;
        bool isEmpty() const;
        void printStack() const;

};
// Thêm phần tử vào stack
void Stack::push(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}
//Lấy phần tử trên cùng và loại bỏ khỏi stack
void Stack::pop() {
    if (isEmpty()) {
        cout<<"Stack rỗng!"<<endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}
// Lấy phần tử trên cùng mà không loại bỏ
int Stack::peek() const {
    if(isEmpty()) {
        cout<<"Stack rỗng!"<<endl;
        return -1;
    }
    return top->data;
}
// Kiểm tra stack có rỗng hay không
bool Stack::isEmpty() const {
    return top == nullptr;
}
void Stack::printStack() const {
    if(isEmpty()) {
        cout<<"Stack is empty!"<<endl;
        return;
    }
    Node* current = top;
    cout<<"Stack element: ";
    while(current != nullptr) {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

int main(){
    Stack myStack;
    myStack.push(10);
    myStack.push(30);
    myStack.push(15);
    myStack.printStack();
    cout<<"Đỉnh stack: "<<myStack.peek()<<endl;

    myStack.pop();
    cout<<"Đỉnh stack sau khi pop: "<<myStack.peek()<<endl;
    myStack.printStack();
    return 0;
}
