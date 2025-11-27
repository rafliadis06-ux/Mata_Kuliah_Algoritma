#include <iostream>
using namespace std;

#define MAX 5

// Struktur Circular Queue
struct CircularQueue {
    char data[MAX];
    int front;
    int rear;
    int count; // untuk hitung jumlah elemen
};

// Inisialisasi Queue
void init(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Cek apakah Queue kosong
bool isEmpty(CircularQueue *q) {
    return (q->count == 0);
}

// Cek apakah Queue penuh
bool isFull(CircularQueue *q) {
    return (q->count == MAX);
}

// Insert elemen ke Queue
void insert(CircularQueue *q, char value) {
    if (isFull(q)) {
        cout << "Queue penuh! Tidak bisa insert " << value << endl;
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = value;
        q->count++;
        cout << "Inserted: " << value << " di posisi " << q->rear << endl;
    }
}

// Remove elemen dari Queue
void remove(CircularQueue *q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
    } else {
        char value = q->data[q->front];
        cout << "Removed: " << value << " dari posisi " << q->front << endl;
        q->front = (q->front + 1) % MAX;
        q->count--;
    }
}

// Tampilkan posisi front dan rear
void showPosition(CircularQueue *q) {
    cout << "Front = " << q->front << ", Rear = " << q->rear;
    cout << ", Jumlah elemen = " << q->count << endl;
}

// Tampilkan isi Queue
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Isi Queue: ";
        int pos = q->front;
        for (int i = 0; i < q->count; i++) {
            cout << q->data[pos] << " ";
            pos = (pos + 1) % MAX;
        }
        cout << endl;
    }
}

int main() {
    CircularQueue q;
    init(&q);
    
    cout << "=== Program Circular Queue ===" << endl;
    cout << "Ukuran MAX = " << MAX << endl;
    cout << endl;
    
    // 1. Mengisi queue hingga penuh
    cout << "1. Mengisi Queue hingga penuh:" << endl;
    insert(&q, 'A');
    insert(&q, 'B');
    insert(&q, 'C');
    insert(&q, 'D');
    insert(&q, 'E');
    cout << endl;
    
    cout << "Posisi: ";
    showPosition(&q);
    display(&q);
    cout << endl;
    
    // 2. Menghapus 3 elemen
    cout << "2. Menghapus 3 elemen:" << endl;
    remove(&q);
    remove(&q);
    remove(&q);
    cout << endl;
    
    cout << "Posisi: ";
    showPosition(&q);
    display(&q);
    cout << endl;
    
    // 3. Mengisi 2 elemen baru
    cout << "3. Mengisi 2 elemen baru:" << endl;
    insert(&q, 'F');
    insert(&q, 'G');
    cout << endl;
    
    // 4. Menampilkan posisi front dan rear
    cout << "4. Posisi Front dan Rear:" << endl;
    showPosition(&q);
    cout << endl;
    
    // 5. Menampilkan isi queue
    cout << "5. Isi Queue:" << endl;
    display(&q);
    
    return 0;
}