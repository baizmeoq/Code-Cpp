#include <iostream>

// Định nghĩa cấu trúc Node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Định nghĩa lớp LinkedList
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Thêm node vào cuối linked list
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Chèn node tại vị trí bất kỳ
    void insert(int position, int value) {
        Node* newNode = new Node(value);
        if (position <= 0) {
            // Chèn vào đầu danh sách
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) {
                tail = newNode;
            }
            return;
        }

        Node* current = head;
        int index = 0;
        while (current != nullptr && index < position - 1) {
            current = current->next;
            index++;
        }

        if (current == nullptr) {
            // Nếu vị trí vượt quá chiều dài của danh sách, thêm vào cuối danh sách
            if (tail != nullptr) {
                tail->next = newNode;
                tail = newNode;
            } else {
                // Danh sách đang rỗng
                head = newNode;
                tail = newNode;
            }
        } else {
            // Chèn vào giữa danh sách
            newNode->next = current->next;
            current->next = newNode;
            if (newNode->next == nullptr) {
                tail = newNode; // Cập nhật tail nếu chèn vào cuối danh sách
            }
        }
    }

    // Xóa node tại vị trí bất kỳ
    void removeAt(int position) {
        if (head == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        if (position <= 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
            return;
        }

        Node* current = head;
        int index = 0;
        while (current->next != nullptr && index < position - 1) {
            current = current->next;
            index++;
        }

        if (current->next == nullptr) {
            std::cout << "Position out of range!" << std::endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        if (current->next == nullptr) {
            tail = current;
        }
        delete temp;
    }

    // In các phần tử của linked list
    void display() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Hàm hủy để giải phóng bộ nhớ
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    std::cout << "Original Linked List: ";
    list.display();

    list.insert(2, 5);
    std::cout << "Linked List after inserting 5 at position 2: ";
    list.display();

    list.insert(0, 6);
    std::cout << "Linked List after inserting 6 at position 0: ";
    list.display();

    list.insert(10, 7);
    std::cout << "Linked List after inserting 7 at position 10: ";
    list.display();

    list.removeAt(2);
    std::cout << "Linked List after removing element at position 2: ";
    list.display();

    list.removeAt(0);
    std::cout << "Linked List after removing element at position 0: ";
    list.display();

    list.removeAt(10);
    std::cout << "Linked List after removing element at position 10: ";
    list.display();

    return 0;
}
