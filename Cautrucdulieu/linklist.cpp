#include<iostream>
using namespace std;

struct Node {
    int data;   // Dữ liệu của node
    Node* next; // Con trỏ tới node kế tiếp

    Node(int value) {  // Constructor để khỏi tạo node với giá trị value
        data = value;
        next = nullptr;
    }
    Node() {next = nullptr;}
};

class LinkedList {
    private:
        Node* head; 
    public:
        LinkedList() {
            head = nullptr;  // Khởi tạo danh sách rỗng
        }
        void insertHead(int value);
        void insertTail(int value);
        void deleteNode(int key);
        void printList();

        ~LinkedList() {
            Node* temp = head;
            while(temp != nullptr) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
        
};

void LinkedList::insertHead(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertTail(int value) {
    Node* newNode = new Node;
    newNode->data = value;

    if(head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head; 
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void LinkedList::deleteNode(int key) {
    Node* temp = head;
    Node* prev = nullptr;

    // Trường hợp node đầu tiên cần xóa
    if(temp != nullptr && temp->data == key ) {
        head = temp->next;
        delete temp;
        return;

    }
    // Tìm node cần xóa 
    while(temp != nullptr && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    // Nếu không tìm thấy node có giá trị key
    if(temp == nullptr) {
        return;
    }
    // Xóa node
    prev->next = temp->next;
    delete temp;

};
void LinkedList::printList() {
    Node* temp = head;
    while(temp != nullptr) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"nullprt"<<endl;
}

int main() {
    LinkedList myList;
    myList.insertHead(2);
    myList.insertHead(5);
    myList.insertTail(7);
    myList.insertTail(1);
    myList.insertHead(8);
    myList.printList();
    myList.deleteNode(5);
    myList.printList();
    return 0;
}