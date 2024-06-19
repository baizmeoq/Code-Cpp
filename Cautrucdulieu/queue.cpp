#include<iostream>
using namespace std;

typedef struct {
    int front, rear;     // Vị trí đỉnh đầu, đỉnh cuối
    int *nodes;         // Danh sách các phần tử
} Queue;

void init(Queue* queue);
void insert(Queue* queue, int node);
int remove(Queue* queue);
void release(Queue* queue);
void traverse(Queue* queue);

int main() {
    Queue* queue = new Queue;
    init(queue);
    insert(queue, 2);
    insert(queue, 5);
    insert(queue, 1);
    insert(queue, 9);
    traverse(queue);
    cout<<"Xóa: "<<remove(queue)<<endl;
    traverse(queue);
    cout<<"Xóa: "<<remove(queue)<<endl;
    traverse(queue);
    release(queue);
    return 0;
}

void init(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->nodes = nullptr;
}

void insert(Queue* queue, int node) {
    int* temp = new int[queue->rear + 2];   // Cấp phát vùng nhớ mới
    queue->rear++;                          // Tăng chỉ số của node đuôi
    if(queue->front == -1) {                // Nếu hàng đợi cũ rỗng
        queue->front = 0;                   // thì cập nhật front
    }
    for(int i=0; i<queue->rear; i++) {      // Sao chép sang vùng nhớ mới
        temp[i] = queue->nodes[i];
    }
    temp[queue->rear] = node;               // Thêm node mới vào đuôi
    delete []queue->nodes;                  // Giai phóng vùng nhớ cũ
    queue->nodes = temp;                    // Trỏ vào vùng nhớ mới
}
// Lấy phần tử đầu và xóa khỏi queue
int remove(Queue* queue) {
    if(queue->front < 0 || queue->rear < 0) {   // Kiểm tra hàng đợi
        cout<<"Queue rỗng!"<<endl;
        return 0;
    }
    // Lưu trữ giá trị phần tử đầu
    int result = queue->nodes[queue->front];
    int* temp;
    if(queue->rear > 0) {       // Nếu có hơn 1 phần tử
        temp = new int[queue->rear];    // Cấp phát vùng nhớ mới
        for(int i=0; i<queue->rear; i++) {
            temp[i] = queue->nodes[i+1];
        }
    }else {     // Nếu chỉ có 1 phần tử
        queue->front--;  // Hàng đợi thành rỗng
    }
    queue->rear--;  // Giam chỉ số node đuôi
    delete []queue->nodes;
    queue->nodes = temp;
    return result;
}
// Duyệt và in các phần tử trong queue
void traverse(Queue* queue) {
    if(queue->front == -1) {
        cout<<"Queue rỗng!"<<endl;
        return;
    }
    cout<<"Queue: ";
    for(int i =0; i<=queue->rear; i++) {
        cout<<queue->nodes[i]<<" ";
    }
    cout<<endl;
}

void release(Queue* queue) {
    if(queue->front > -1) {
        delete []queue->nodes;
    }
    delete queue;
}