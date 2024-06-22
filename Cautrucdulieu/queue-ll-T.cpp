#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}  // một tham chiếu đến một đối tượng kiểu T, đối tượng này không thể bị thay đổi thông qua tham chiếu này, T có thể là bất kỳ kiểu dữ liệu nào
    };              // Tác dụng tránh sao chép ko cần thiết đặc biệt đối với các đối tượng lớn, ngăn chặn sửa đổi không mong muốn, hoạt động với mọi kiểu T cho phép viết code tổng quát
    Node* front;
    Node* rear;
    size_t count;
public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}
    ~Queue() {
        while(!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {  // const member function
        return front == nullptr;
    }

    size_t size() const {
        return count;
    }

    void enqueue(const T& value) {
        Node* newNode = new Node(value);

        if(isEmpty()) {
            front = newNode;
            rear = newNode;
        }else {
            rear->next = newNode;
            rear = newNode;
        }
        ++count;
    }

    T dequeue() {
        if(isEmpty()) {
            throw runtime_error("Queue rỗng");
        }
        Node* temp = front;
        T value = temp->data;
        front = front->next;
        if(front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        --count;
        return value;
    }

    T peek() const {
        if(isEmpty()) {
            throw runtime_error("Queue rỗng");
        }
        return front->data;
    }

    void display() const {
        if (isEmpty()) {
            cout<<"Queue rỗng"<<endl;
            return;
        }
        
        Node* current = front;
        cout<<"Queue: ";
        while (current != nullptr) {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
};

int main() {
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    q.display();
    cout << "Queue size: " << q.size() << endl;
    cout << "Front element: " << q.peek() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
    q.display();
    cout << "New front element: " << q.peek() << endl;
    cout << "New queue size: " << q.size() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
    q.display();
    return 0;
}