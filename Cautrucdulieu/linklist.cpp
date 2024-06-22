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
        void insertAt(int value, int position);
        void deleteAt(int position);
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

}
void LinkedList::insertAt(int value, int position){
    Node* newNode = new Node(value);
    if(position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* current = head;
    for(int i=0; current != nullptr && i < position -1; ++i) {
        current = current->next;
    }
    if(current == nullptr) {
        cout<<"Vị trí nằm ngoài giới hạn"<<endl;
        delete newNode;
        return;
    }
    // Chèn node mới
    newNode->next = current->next;
    current->next = newNode; 
}
void LinkedList::deleteAt(int position) {
    Node* temp = head;
    if(head == nullptr) {
        cout<<"List rỗng"<<endl;
        return;
    }
    if(position == 0) {
        head = head->next;
        delete temp;
        return;
    }
    // Tìm node trước node cần xóa
    for(int i=0; temp != nullptr && i < position-1; ++i) {
        temp = temp->next;
    }
    // Vị trí vượt quá chiều dài của danh sách
    if(temp == nullptr || temp->next == nullptr) {
        cout<<"Vị trí nằm ngoài giới hạn"<<endl;
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}
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

    myList.insertAt(10, 2);
    myList.printList();

    myList.insertAt(15, 0);
    myList.printList();

    myList.insertAt(20, 10); // Out of bounds example
    myList.printList();

    myList.deleteAt(2);
    myList.printList();

    myList.deleteAt(0);
    myList.printList();

    myList.deleteAt(10); // Out of bounds example
    myList.printList();
    return 0;
}