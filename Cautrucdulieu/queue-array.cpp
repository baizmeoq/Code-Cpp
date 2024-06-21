#include<iostream>
using namespace std;

const int SIZE = 100;

class Queue {
    private:
        int items[SIZE], front, rear;
    public:
        Queue() {
            front = -1;
            rear = -1;
        }
        bool isEmpty();
        bool isFull();
        void enqueue(int element);
        int dequeue();
        void display();
        
};

bool Queue::isEmpty() {
    return front == -1;
}
bool Queue::isFull() {
    return rear == SIZE-1;
}
void Queue::enqueue(int element) {
    if(isFull()) {
        cout<<"Queue đã đầy"<<endl;
    }else {
        if(front == -1) front = 0;
        rear++;
        items[rear] = element;
        cout<<element<<" đã được thêm vào queue"<<endl;
    }
}
int Queue::dequeue() {
    int element;
    if(isEmpty()) {
        cout<<"Hàng đợi rỗng!";
        return -1;
    } else {
        element = items[front];
        if(front >= rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        cout<<element<<" đã được lấy ra khỏi hàng đợi"<<endl;
        return element;
    }
}
void Queue::display() {
    if(isEmpty()) { 
        cout<<"Hàng đợi rỗng";
    } else {
        cout<<"Queue: ";
        for(int i=front; i<=rear; i++) {
            cout<<items[i]<<" ";
        }
        cout<<endl;
    }
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