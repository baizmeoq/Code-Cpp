#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    private:
        Node* front;
        Node* rear;
    public:
        Queue() {
            front = nullptr;
            rear = nullptr;
        }
        bool isEmpty();
        void enqueue(int element);
        int dequeue();
        void display();
        ~Queue() {
            while(!isEmpty()) {
                dequeue();
            }
        }
};
bool Queue::isEmpty() {
    return front == nullptr;
}
void Queue::enqueue(int element) {
    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = nullptr;

    if(isEmpty()) {        
        front = newNode;
        rear=  newNode;
    }else {
        rear->next = newNode;
        rear = newNode;
    }
    cout<<element<<" đã được thêm vào hàng đợi"<<endl;
}
int Queue::dequeue() {
    if(front == nullptr){
        cout<<"Queue rỗng!"<<endl;
        return -1;
    }
    int value = front->data;
    Node* temp = front;
    front = front->next;
    if(front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return value;
}
void Queue::display() {
    if(isEmpty()) {
        cout<<"Queue rỗng!"<<endl;
        return;
    }
    Node* temp = front; 
    cout<<"Queue: ";
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl; 
}
int main() {
    Queue q;

    // Kiểm tra hàng đợi rỗng
    cout << "Hàng đợi có rỗng không? " << (q.isEmpty() ? "Có" : "Không") << endl;

    // Thêm phần tử vào hàng đợi
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Hiển thị các phần tử trong hàng đợi
    q.display();

    // Lấy phần tử ra khỏi hàng đợi
    q.dequeue();
    q.dequeue();

    // Hiển thị lại các phần tử sau khi lấy ra
    q.display();
    return 0;
}