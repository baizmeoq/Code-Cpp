#include <iostream>

// Khai báo lớp Node
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor để khởi tạo nút
    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Khai báo lớp DoublyLinkedList
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor để khởi tạo danh sách liên kết đôi rỗng
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor để giải phóng bộ nhớ
    ~DoublyLinkedList() {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Hàm thêm một nút vào cuối danh sách
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Hàm thêm một nút vào đầu danh sách
    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Hàm in danh sách từ đầu đến cuối
    void printForward() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Hàm in danh sách từ cuối lên đầu
    void printBackward() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    // Hàm xóa một nút với giá trị cụ thể
    void deleteValue(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.prepend(0);

    std::cout << "Danh sách từ đầu đến cuối: ";
    dll.printForward();

    std::cout << "Danh sách từ cuối lên đầu: ";
    dll.printBackward();

    dll.deleteValue(2);
    std::cout << "Danh sách sau khi xóa giá trị 2: ";
    dll.printForward();

    return 0;
}
