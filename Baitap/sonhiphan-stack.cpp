/* Sử dụng cấu trúc ngăn xếp đã định nghĩa trong bài để đổi một số từ kiểu thập phân sang
kiểu nhị phân: Chi số nguyên cho 2, mãi cho đến khi thương <2, lưu các số dư váo ngăn
xếp. Sau đó, đọc các giá trị dư từ ngăn xếp ra, ta sẽ thu được chuỗi nhị phân tương ứng. */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
}; 

class Stack {
    private: 
        Node *top;

        // Helper function to deallocate memory
        void clear();

    public:
        // Constructor
        Stack();

        // Destructor
        ~Stack();

        // Stack operations
        void push(int x);
        void pop();
        int peek() const;
        bool isEmpty() const;

        // Print elements in the stack
        void printStack() const;
};

// Constructor
Stack::Stack() : top(nullptr) {}

// Destructor
Stack::~Stack() {
    clear();
}

// Deallocate memory of all nodes
void Stack::clear() {
    while(!isEmpty()) {
        pop();
    }
}

// Add element to stack
void Stack::push(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

// Remove element from stack
void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

// Get top element without removing
int Stack::peek() const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return top->data;
}

// Check if stack is empty
bool Stack::isEmpty() const {
    return top == nullptr;
}

// Print elements in the stack
void Stack::printStack() const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }

    Node* current = top;
    cout << "Stack elements: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void decimalToBinary(int number) {
    Stack binaryStack;
    while(number >= 2) {
        int temp = number % 2;
        binaryStack.push(temp);
        number = number/2;
    }
    // push thương số cuối cùng
    binaryStack.push(number);

    cout<<"Binary: ";
    while(!binaryStack.isEmpty()) {
        cout<<binaryStack.peek();
        binaryStack.pop();
    }
    cout<<endl;
}

int main() {
    int number;
    cout<<"Nhập số nguyên dương: ";
    cin>>number;

    decimalToBinary(number);
    return 0;
}
